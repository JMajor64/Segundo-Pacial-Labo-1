#include "Service.h"
/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

//print

/*Passenger_newParametros()
 * \brief Crea una variable tipo Passenger en memoria dinamica y le asigna valor
 * \param idStr, nombreStr, apellidoStr, PrecioStr, flyCodeStr, tipoPasajeroStr y status almacenan cada uno de los campos de una estructura tipo Passenger
 * \ return Retorna un puntero a un Passenger en memoria dinamica
 * */

eServicios* Service_newParametros(char* idStr,char* descripcionStr,char* TipoServStr,char* PrecioStr,char* cantidadStr,char* PrecioFinalStr)
{
	eServicios aux;
	eServicios* new;

		//convertir datos;

		aux.id=atoi(idStr);
		aux.precio=atof(PrecioStr);
		aux.tipoServicio=atoi(TipoServStr);
		aux.cantidad=atoi(cantidadStr);
		strcpy(aux.descripcion,descripcionStr);
		aux.precioFinal=atof(PrecioFinalStr);

		//introducir datos
		new=Service_NonStrNewParametros(aux);

	return new;
}

/*Passenger_NonStrNewParametros()
 * \brief Crea una variable tipo Passenger en memoria dinamica y le asigna valor
 * \param aux Es una variable tipo Passenger que guarda los valores a asignar al Passenger en memoria dinamica
 * \return Retona un Puntero a Passenger
 * */

eServicios* Service_NonStrNewParametros(eServicios aux)
{
	eServicios* new;
	new=Service_new();
	if(new!=NULL)
	{
		Service_setId(new,aux.id);
		Service_setDescripcion(new,aux.descripcion);
		Service_setTipoServicio(new,aux.tipoServicio);
		Service_setPrecio(new,aux.precio);
		Service_setCantidad(new,aux.cantidad);
		Service_setPrecioFinal(new,aux.precioFinal);
	}
	else{
		printf("Error, intente mas tarde\n");
	}
	return new;
}



int TypeService(char *typeStr)
{
	int typeInt=0;
	if(strcmp(typeStr,"Minorista") == 0)
	{
		typeInt=1;
	}else
	{
		if(strcmp(typeStr,"Mayorista") == 0)
		{
			typeInt=2;
		}
		else
		{
			if(strcmp(typeStr,"Exportar") == 0)
			{
				typeInt=3;
			}
		}
	}
	return typeInt;
}

/*printType()
 * \brief imprime un tipoPasajero en forma de caracteres
 * \param TypeInt entero equivalente a la cadena del tipoPasajero
 * */
void printType(int TypeInt)
{
	switch(TypeInt)
	{
	case 1:
		printf("Minorista\n");
		break;
	case 2:
		printf("Mayorista\n");
		break;
	case 3:
		printf("Exportar\n");
		break;
	default:
		printf("Error, Tipo invalido\n");
		break;
	}
}

/*Passenger_getFromUser()
 * \brief Pide al usuario los datos y los asigna a una variable Passenger
 * \return Retona una variable tipo Passenger con los valores asignados
 * */
eServicios Service_getFromUser()
{
	eServicios aux;
	int validate=0;

	while(validate==0){
		validate=Utn_getInt("Ingrese Id",0,4,&aux.id);
	}
	validate=0;

	while(validate==0){
		validate=Utn_getString("ingrese breve Descripcion",aux.descripcion,sizeof(aux.descripcion));
	}
	validate=0;

	while(validate==0){
	printf("Ingrese el tipo de servicio: \n");
	printf("1 ");
	printType(1);
	printf("2 ");
	printType(2);
	printf("3 ");
	printType(3);
	validate=Utn_getInt("",0,4,&aux.tipoServicio);
	}
	validate=0;

	while(validate==0){
		validate=Utn_getFloat("Ingrese el precio por unidad",0,9999999,&aux.precio);
	}
	validate=0;

	while(validate==0){
		validate=Utn_getInt("Ingrese la cantidad de unidades",0,4,&aux.cantidad);
	}

	return aux;
}
/*Passenger_new ()
 * \brief Crea un Passenger en memoria dinamica
 * \return Retorna un puntero a un Passenger en memoria dinamica
 * */
eServicios* Service_new()
{
	eServicios* new=(eServicios*) malloc(sizeof(eServicios));

	return new;
}

//SETERS

/* Passenger_setId()
 * \brief Asigna un valor al campo Id de un Passenger
 * \param this Direccion de memoria o Puntero a Passenger
 * \param id entero a asignar al campo Id del Passenger
 * \return 1 si funciona correctamente, 0 si no
 * */
int Service_setId(eServicios* this,int id)
{
	int retorno=0;
	if(this!=NULL)
	{
		(*this).id=id;
		retorno=1;
	}
	return retorno;
}

int Service_setDescripcion(eServicios* this,char* descripcion)
{
	int retorno=0;
	if(this!=NULL&& strlen(descripcion)<sizeof((*this).descripcion))
	{
		strcpy((*this).descripcion,descripcion);
		retorno=1;
	}
	return retorno;
}

int Service_setTipoServicio(eServicios* this,int TipoServicio)
{
	int retorno=0;
	if(this!=NULL && TipoServicio>0)
	{
		(*this).tipoServicio=TipoServicio;
		retorno=1;
	}
	return retorno;
}

int Service_setPrecio(eServicios* this,float precio)
{
	int retorno=0;
	if(this!=NULL && precio>0)
	{
		this->precio=precio;
	}
	return retorno;
}

int Service_setCantidad(eServicios* this,int cantidad)
{
	int retorno=0;
	if(this!=NULL && cantidad>0)
	{
		this->cantidad=cantidad;
	}
	return retorno;
}

int Service_setPrecioFinal(eServicios* this,float PrecioFinal)
{
	int retorno=0;
	if(this!=NULL && PrecioFinal>-1)
	{
		this->precioFinal=PrecioFinal;
	}
	return retorno;
}
/////////////////////////////////////////////////

//GETERS

int Service_getId(eServicios* this,int* id)
{
	int retorno=0;
	if(this!=NULL && id!=NULL)
	{
		*id=(*this).id;
		retorno=1;
	}
	return retorno;
}


int Service_getDescripcion(eServicios* this,char* descripcion)
{
	int retorno=0;
	if(this!=NULL && descripcion!=NULL)
	{
		strcpy(descripcion,(*this).descripcion);
		retorno=1;
	}
	return retorno;
}



int Service_getTipoServicio(eServicios* this,int* TipoServicio)
{
	int retorno=0;
	if(this!=NULL && TipoServicio!=NULL)
	{
		*TipoServicio=(*this).tipoServicio;
		retorno=1;
	}
	return retorno;
}


int Service_getPrecio(eServicios* this,float* precio)
{
	int retorno=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio=(*this).precio;
		retorno=1;
	}
	return retorno;
}


int Service_getCantidad(eServicios* this,int* cantidad)
{
	int retorno=0;
	if(this!=NULL && cantidad!=NULL)
	{
		*cantidad=(*this).cantidad;
		retorno=1;
	}
	return retorno;
}

void GetTypeStr(eServicios* this,char* Type)
{
	switch(this->tipoServicio)
	{
	case 1:
		strcpy(Type,"Minorista");
		break;
	case 2:
		strcpy(Type,"Mayorista");
		break;
	case 3:
		strcpy(Type,"Exportar");
		break;
	}
}

int Service_getPrecioFinal(eServicios* this,float* precio)
{
	int retorno=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio=(*this).precioFinal;
		retorno=1;
	}
	return retorno;
}

/* Passenger_printPassenger()
 * \brief Imprime un Passenger
 * \param aux Passenger* a imprimir
 * */
void Service_printService(eServicios* aux)
{
	char auxType[16];
	GetTypeStr(aux,auxType);
	printf("%-6d||%-20s ||%-10s\t||%-7.2f\t||%-6d\t||%-8.2f\n",aux->id,aux->descripcion,auxType,aux->precio,aux->cantidad,aux->precioFinal);

}

int Service_sortByDescripcion(void* ServiceA,void* ServiceB)
{
	int retorno=-1;
	char auxDescripcionA[50];
	char auxDescripcionB[50];
	{
		if(ServiceA != NULL && ServiceB != NULL)
		{
			Service_getDescripcion(ServiceA,auxDescripcionA);
			Service_getDescripcion(ServiceB,auxDescripcionB);
			retorno=strcmp(auxDescripcionA,auxDescripcionB);
		}
	}
	return retorno;
}

int Service_sortById(void* ServiceA,void* ServiceB)
{
	int retorno=-1;
	int auxIdA=0;
	int auxIdB=0;
	eServicios* AuxA;
	eServicios* AuxB;
	AuxA=(eServicios*)ServiceA;
	AuxB=(eServicios*)ServiceB;

	if(ServiceA != NULL && ServiceB != NULL)
	{
		Service_getId(AuxA,&auxIdA);
		Service_getId(AuxB,&auxIdB);
		if(auxIdA>auxIdB)
		{
			retorno=1;
		}else{
			retorno=-1;
		}

	}
	return retorno;
}

/* Passenger_free()
 * \brief elimina un Passenger de la memoria dinamica
 * \param delete Passenger* a eliminar
 * */
 void Service_free(eServicios* delete)
 {
	free(delete);
 }


/*FiltrarPassengers
 * \brief filtra pasajeros por tipo
 * \param this Passenger
 * */
 int Service_filtrarPorTipo1(void* this)
 {
     int retorno = 0;
     if(this != NULL)
     {
    	 eServicios* Aux;
		 Aux=(eServicios*)this;
      if(Aux->tipoServicio == 1){
         retorno = 1;
      }

     }
     return retorno;
 }

 /*FiltrarPassengers
  * \brief filtra pasajeros por tipo
  * \param this Passenger
  * */
  int Service_filtrarPorTipo2(void* this)
  {
      int retorno = 0;
      if(this != NULL)
      {
    	  eServicios* Aux;
    	  Aux=(eServicios*)this;

       if(Aux->tipoServicio == 2){
          retorno = 1;
       }

      }
      return retorno;
  }
  /*FiltrarPassengers
   * \brief filtra pasajeros por tipo
   * \param this Passenger
   * */
   int Service_filtrarPorTipo3(void* this)
   {
       int retorno = 0;
       if(this != NULL)
       {
    	   eServicios* Aux;
    	   Aux=(eServicios*)this;
        if(Aux->tipoServicio == 3){
           retorno = 1;
        }

       }
       return retorno;
   }

 /* calcularPrecioFinal
  * \brief Calcula el iva al precio del pasaje
  * \param this Passenger*
  * */
 void calcularPrecioFinal(void* this)
 {
     if(this != NULL)
     {
    	 eServicios* Aux;
    	 Aux=(eServicios*)this;
    	 float auxPrice;
         int cantidad;
         float total;
         Service_getPrecio(Aux,&auxPrice);
         Service_getCantidad(Aux,&cantidad);
         total= auxPrice * cantidad;

         Service_setPrecioFinal(Aux,total);

     }
     return;
 }




