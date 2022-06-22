#include "Controller.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* File, LinkedList* pArrayListService)
{
	int retorno=0;
	char fileName[20];
	Utn_getString("Ingrese el nombre del archivo (Sin extension)",fileName,sizeof(fileName));
	FILE * pFile;
	if(fileName!=NULL)
	{
		strcat(fileName,".csv");
	}
	pFile = fopen (fileName, "r");

	if(pFile!=NULL)
	{
		parser_ServiceFromText(pFile,pArrayListService);
		printf("%s abierto exitosamente\n",fileName);
		system("pause");
		strcpy(File,fileName);
		retorno=1;
	}
	else
	{
		printf("Error, archivo no encontrado\n");
		system("pause");
	}

	fclose(pFile);

    return retorno;
}

/** \brief Listar servicios
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListService(LinkedList* pArrayListService)
{
	int len;
	int i;
	eServicios* aux;
	len=ll_len(pArrayListService);
	system("@cls||clear");
	printf("Id\tDercipcion \t\t  Tipo \t  Precio \t  Cantidad \t Precio Final\n");
	for(i=0;i<len;i++)
	{
		aux=ll_get(pArrayListService,i);
		if(aux!=NULL)
		{
			Service_printService(aux);
		}
		else{
			printf("ERROR\n");
			system("pause");
		}
	}
	system("pause");
    return 1;
}


/** \brief Guarda los datos de los servicios en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* listaServicios)
{
	int retorno=0;
	FILE* pFile;

	pFile=fopen(path,"w");

	if(pFile!=NULL)
	{
		int len;

		len=ll_len(listaServicios);
		if(len!=-1)
		{
			printf("Guardando lista, por favor espere...\n");
			eServicios* aux;
			int auxId;
			char Descripcion[50];
			int Tipo;
			float auxprice;
			int cantidad;
			float PrecioFinal;

				fprintf(pFile,"Id, Descripcion, Tipo, Precio, Cantidad, PrecioFinal\n");

			int i;
			for(i=0;i<len;i++)
			{
				aux=ll_get(listaServicios,i);

				Service_getId(aux,&auxId);
				Service_getDescripcion(aux,Descripcion);
				Service_getTipoServicio(aux,&Tipo);
				Service_getPrecio(aux,&auxprice);
				Service_getCantidad(aux,&cantidad);
				Service_getPrecioFinal(aux,&PrecioFinal);

				fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",auxId,Descripcion,Tipo,auxprice,cantidad,PrecioFinal);
			}

		}

	}
	fclose(pFile);
    return retorno;
}


/* ()
 * \brief calcula el id a asignar a un nuevo Passenger
 * \param pArrayListPassenger LinkedList*
 * \return int Id a asignar
 * */

/* freeAll()
 * \brief Libera toda la memoria dinamica usada durante la ejecucion del programa
 * \param pArrayListPassenger LinkedList*
 * */
void freeAll(LinkedList* listaServicios)
{
	int len;
	int i;
	eServicios* aux;

	len=ll_len(listaServicios);
	for(i=0;i<len;i++)
	{
		aux=ll_get(listaServicios,i);
		if(aux!=NULL)
		{
			Service_free(aux);
		}
	}
	ll_clear(listaServicios);
	ll_deleteLinkedList(listaServicios);
}

void controller_CalcularPrecioFinal(LinkedList* listaServicios)
{
	ll_map(listaServicios,calcularPrecioFinal);
}

LinkedList* controller_FiltrarPorTipo(LinkedList* listaServicios)
{
	int class;
	 int verif=0;
	 LinkedList* FList;
	 while(verif==0)
	 {
		system("@cls||clear");
		printf("\n");
		printf("1 ");
		printType(1);
		printf("2 ");
		printType(2);
		printf("3 ");
		printType(3);
		verif=Utn_getInt("Ingrese el tipo de Servicio",0,4,&class);
	 }
	 switch(class)
	 {
	 case 1:
		 FList=ll_filter(listaServicios,Service_filtrarPorTipo1);
		 break;
	 case 2:
		 FList=ll_filter(listaServicios,Service_filtrarPorTipo2);
		 break;
	 case 3:
		 FList=ll_filter(listaServicios,Service_filtrarPorTipo3);
		 break;
	 }
	 return FList;
}


void controller_Filtrar(LinkedList* listaServicios)
{
	LinkedList* ListaFiltrada;
	ListaFiltrada=controller_FiltrarPorTipo(listaServicios);
	if(ListaFiltrada!=NULL)
	{
		controller_ListService(ListaFiltrada);


		char auxType[20];
		GetTypeStr(ll_get(ListaFiltrada,1),auxType);
		strcat(auxType,".csv");
		ll_sort(listaServicios,Service_sortById,1);
		printf("\n");
		printf("\n");
		controller_saveAsText(auxType,ListaFiltrada);

		printf("Se ha guardado la lista filtrada\n");
		system("pause");
	}

}

int controler_OrdenarPorDescripcion(LinkedList* listaServicios)
{
	ll_sort(listaServicios,Service_sortByDescripcion,1);
	return 1;
}

void controller_GuardarListaOrdenada(char* path,LinkedList* listaServicios,int flag)
{
	if(flag)
	{
		controller_saveAsText(path,listaServicios);
		printf("Lista guardada exitosamente\n");
		system("pause");
	}
	else{
		printf("Error, no ha ordenado la lista, no se puede guardar\n");
		system("pause");
	}
}
