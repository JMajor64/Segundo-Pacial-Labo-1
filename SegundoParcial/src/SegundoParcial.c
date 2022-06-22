/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"
#include "Service.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int option = 0;
	    int flag=0;
	    int flagOrden=0;
	    int dataLoad=0;
	    char fileName[20];

	    setbuf(stdout, NULL);

	    LinkedList* listaServicios = ll_newLinkedList();

	    do{
	    	//print
			system("@cls||clear");
			 printf("\n");
			 printf("****************************************************************\n");
			 printf("\n");
			 printf("1: Cargar los datos de desde archivo\n");
			 printf("2: Listar servicios\n");
			 printf("3: Asignar Precio final\n");
			 printf("4: Filtrar lista por Tipo\n");
			 printf("5: Ordenar pedidos por descripcion\n");
			 printf("6: Guardar lista ordenada\n");
			 printf("7: Salir\n");
			 printf("\n");
			 printf("****************************************************************\n");
			 printf("\n");

			 Utn_getInt("",0,20,&option);

	        switch(option)
	        {
	            case 1:
	            	if(flag!=1)
	            	{
	            		flag=controller_loadFromText(fileName,listaServicios);
	            		dataLoad=flag;
	            	}
	                break;
	            case 2:
	            	if(dataLoad)
					{
						controller_ListService(listaServicios);
					}
					else
					{
						printf("Ingrese algun dato antes de continuar\n");
						system("pause");
					}
	            	break;
	            case 3:
	            	if(dataLoad)
					{
	            		controller_CalcularPrecioFinal(listaServicios);
					}
					else
					{
						printf("Ingrese algun dato antes de continuar\n");
						system("pause");
					}
	            	break;
	            case 4:
	            	if(dataLoad)
	            	{
	            		controller_Filtrar(listaServicios);
	            	}
	            	else
	            	{
	            		printf("Ingrese algun dato antes de continuar\n");
	            		system("pause");
	            	}
	            	break;
	            case 5:
	            	if(dataLoad)
	            	{
	            		flagOrden=controler_OrdenarPorDescripcion(listaServicios);
	            	}
	            	else
	            	{
	            	    printf("Ingrese algun dato antes de continuar\n");
	            	    system("pause");
	            	}
	            	break;
	            case 6:
	            	if(dataLoad)
					{
	            		controller_GuardarListaOrdenada(fileName,listaServicios,flagOrden);
					}
					else
					{
						printf("Ingrese algun dato antes de continuar\n");
						system("pause");
					}
	            	break;
	            case 7:
	            	freeAll(listaServicios);
	            	break;

	            default:
	            	break;
	        }

	    }while(option != 7);
	    return 0;
}
