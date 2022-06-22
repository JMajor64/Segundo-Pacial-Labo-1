#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Service.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServiceFromText(FILE* pFile , LinkedList* pArrayListService)
{
	int retorno=0;

	char auxId[8];
	char auxDescripcion[50];
	char auxTipo[2];
	char auxPrecio[20];
	char auxCantidad[8];
	char PrecioTotal[20];

	eServicios* new;


	if (pFile!=NULL)
		{

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxTipo,auxPrecio,auxCantidad,PrecioTotal);

			while(!feof(pFile))
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxDescripcion,auxTipo,auxPrecio,auxCantidad,PrecioTotal);

				new=Service_newParametros(auxId,auxDescripcion,auxTipo,auxPrecio,auxCantidad,PrecioTotal);

				if(new!=NULL)
				{
					retorno=ll_add(pArrayListService,new);
				}
				else{
					printf("\n");
					printf("Error, borre la lista y vuelva a intentarlo\n");
					break;
				}
			}
			setbuf(stdout, NULL);
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServiceFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	eServicios aux;
	eServicios Last;

	eServicios* new;
	   if(pFile!=NULL)
		   {
			   while(!feof(pFile))
			   {
				   fread(&aux,sizeof(eServicios),1,pFile);
				   if(aux.id != Last.id)
				   {
					   new=Service_NonStrNewParametros(aux);
					   if(new!=NULL)
					   {
					   		retorno=ll_add(pArrayListPassenger,new);
					   }
				   }
				   aux=Last;
			   }
		   }
	   else
	   {
		   printf("Error en Lectura en Binario\n");
	   }

    return retorno;
}
