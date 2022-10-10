/*
 * TRANSPORTE.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#include "TRANSPORTE.h"

#define HARDCODED_N 4

int hardcodearTransporte(eTransporte *listaTransporte, int tam, int *pSigID)
{
	eTransporte datosHardcodeados[HARDCODED_N]=
	{
			{*pSigID,"gatos",0,2,1000,0},
			{*pSigID++,"electronica",0,2,1002,0},
			{*pSigID++,"basura",0,2,1003,0},
			{*pSigID++,"comida",0,2,1000,0}
	};

	if(listaTransporte!=NULL && tam >0 && pSigID!=NULL)
	{
		for(int i=0;i<HARDCODED_N;i++)
		{
			*(listaTransporte+i)=*(datosHardcodeados+i);
		}
	}
	return EXIT_FAILURE;
}

int siguienteTransporteEmpty(eTransporte *listaTransporte, int tam)
{
	int siguienteLibre=0;

	if(listaTransporte!=NULL && tam>0)
	{
		while(siguienteLibre<tam)
		{
			if(((listaTransporte+siguienteLibre)->isEmpty))
			{
				return siguienteLibre;
			}
			siguienteLibre++;
		}
	}
	return -1;
}

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

	intEnRango(&opcion, 1, 8);

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
