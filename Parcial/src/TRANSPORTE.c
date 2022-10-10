/*
 * TRANSPORTE.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#include "TRANSPORTE.h"

int imprimirMenuPrincipal(void)
{
	int opcion;

	printf("\tABM LOGISTICA\n\n");
	printf("1 - Alta Transporte\n");
	printf("2 - Modificar Transporte\n");
	printf("3 - Baja Transporte\n");
	printf("4 - Listar Transporte\n");
	printf("5 - Listar Tipos\n");
	printf("6 - Alta Hoja de Ruta\n");
	printf("7 - Informes\n");
	printf("8 - Salir\n");
	printf("\n");

	intEnRango(&opcion, 1, 7);

	return opcion;
}

int inicializarTransporte(eTransporte *transporte,int tam)
{
	int contador=0;

	if(transporte!=NULL && tam>0)
	{
		while(contador<tam)
		{
			(transporte+contador)->isEmpty=1;
			contador++;
		}
	}
	else
	{
		return 1;	//error de inicializacion
	}
	return 0;	//Exito
}
