#include "LinkedList.h"
#include "utnlib.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define IVA 21

typedef struct
{
	int id;
	char descripcion[50];
	int tipoServicio;
	float precio;
	int cantidad;
	float precioFinal;

}eServicios;




eServicios* Service_new();
int Service_delete(eServicios* delete);
void Service_free(eServicios* delete);

int TypeService(char *typeStr);
void printType(int TypeInt);

eServicios* Service_newParametros(char* idStr,char* descripcionStr,char* TipoServStr,char* PrecioStr,char* cantidadStr,char* PrecioFinalStr);
eServicios* Service_NonStrNewParametros(eServicios aux);
eServicios Service_getFromUser();

int Service_setId(eServicios* this,int id);
int Service_getId(eServicios* this,int* id);

int Service_setDescripcion(eServicios* this,char* descripcion);
int Service_getDescripcion(eServicios* this,char* descripcion);

int Service_setTipoServicio(eServicios* this,int TipoServicio);
int Service_getTipoServicio(eServicios* this,int* TipoServicio);

int Service_setPrecio(eServicios* this,float precio);
int Service_getPrecio(eServicios* this,float* precio);

int Service_setCantidad(eServicios* this,int cantidad);
int Service_getCantidad(eServicios* this,int* cantidad);

int Service_setPrecioFinal(eServicios* this,float PrecioFinal);
int Service_getPrecioFinal(eServicios* this,float* precio);

void GetTypeStr(eServicios* this,char* Type);

void Service_printService(eServicios* aux);

int Service_sortByDescripcion(void* ServiceA,void* ServiceB);
int Service_sortById(void* ServiceA,void* ServiceB);

void calcularPrecioFinal(void* this);

int Service_filtrarPorTipo1(void* this);
int Service_filtrarPorTipo2(void* this);
int Service_filtrarPorTipo3(void* this);

#endif /* PASSENGER_H_ */
