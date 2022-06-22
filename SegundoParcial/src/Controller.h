#include "LinkedList.h"
#include "Service.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int controller_loadFromText(char* File, LinkedList* pArrayListService);
int controller_saveAsText(char* path , LinkedList* listaServicios);

int controller_ListService(LinkedList* pArrayListService);

void controller_Filtrar(LinkedList* listaServicios);

void freeAll(LinkedList* pArrayListPassenger);

void controller_CalcularPrecioFinal(LinkedList* listaServicios);
LinkedList* controller_FiltrarPorTipo(LinkedList* listaServicios);

void controller_Filtrar(LinkedList* listaServicios);
int controler_OrdenarPorDescripcion(LinkedList* listaServicios);
void controller_GuardarListaOrdenada(char* path,LinkedList* listaServicios,int flag);
