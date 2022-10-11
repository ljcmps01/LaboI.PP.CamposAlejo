/*
 * TRANSPORTE.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#include "TRANSPORTE.h"

#define HARDCODED_N 4


int listarTransportes(eTransporte *listaTransporte, int tam)
{
	if(listaTransporte!=NULL && tam>0)
	{
		printf("\t\tLISTA DE TRANSPORTES\n");
		printf("-----------------------------------------------------------------\n");
		printf("|  ID |     Descripcion    |  Peso |Bultos |        tipoID      |\n");
		printf("-----------------------------------------------------------------\n");
		for(int i=0;i<tam;i++)
		{
			if((listaTransporte+i)->isEmpty)
			{
				break;
			}
			//printf("|%-5d|%-20s|%7d|%7d|%7d|\n",(listaTransporte+i)->idTransporte,(listaTransporte+i)->descripcion,(listaTransporte+i)->pesoCarga,(listaTransporte+i)->cantidadBultos,(listaTransporte+i)->tipoId);
			mostrarFilaTransporte((listaTransporte+i));
		}
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;

}


int mostrarFilaTransporte(eTransporte *transporte)
{
	char descripcionTipo[20];
	if(transporte!=NULL)
	{
		getDescripcionTipo(descripcionTipo, transporte->tipoId, tipos);
		printf("|%-5d|%-20s|%7d|%7d|%20s|\n",transporte->idTransporte,transporte->descripcion,transporte->pesoCarga,transporte->cantidadBultos,descripcionTipo);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

int altaTransporte(eTransporte *listaTransporte, int tam, int* pSigID)
{
	eTransporte bufferTransporte;
	int indice;
//	char descripcion[20];

	if(listaTransporte!=NULL && tam>0 && pSigID!=NULL)
	{
		indice=siguienteTransporteEmpty(listaTransporte, tam);
		if(indice==-1)
		{
			printf("No hay espacio para mas transportes\n");
			return EXIT_FAILURE;
		}

		bufferTransporte.idTransporte=*pSigID;

			printf("ingrese descripcion del transporte\n");
			fflush(stdin);
			scanf("%30s",bufferTransporte.descripcion);
			printf("Se ingreso: %s\n",bufferTransporte.descripcion);
//		strcpy(bufferTransporte.descripcion,descripcion);

		printf("ingrese peso de la carga\n");
		cargarInt(&bufferTransporte.pesoCarga);

		printf("ingrese cantidad de bultos\n");
		cargarInt(&bufferTransporte.cantidadBultos);

		printf("ingrese tipo\n");
		listarTipos(tipos, TAM_TIPOS);

		intEnRango(&bufferTransporte.tipoId, 1000, 1004);

		bufferTransporte.isEmpty=0;

		*(listaTransporte+indice)=bufferTransporte;

		(*pSigID)++;

		return EXIT_SUCCESS;

	}
	else
	{
		printf("Error de vectores\n");
		return EXIT_FAILURE;
	}


	return EXIT_FAILURE;
}

int hardcodearTransporte(eTransporte *listaTransporte, int tam, int *pSigID)
{
	eTransporte datosHardcodeados[HARDCODED_N]=
	{
			{(*pSigID)++,"gatos",100,2,1000,0},
			{(*pSigID)++,"electronica",50,2,1002,0},
			{(*pSigID)++,"basura",1000,2,1003,0},
			{(*pSigID)++,"comida",300,2,1000,0}
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
