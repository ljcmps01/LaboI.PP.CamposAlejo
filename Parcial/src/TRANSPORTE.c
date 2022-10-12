/*
 * TRANSPORTE.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#include "TRANSPORTE.h"

#define HARDCODED_N 4


int modificarTransporte(eTransporte *listaTransporte, int tam)
{
	int indiceModificacion;
	int idModificacion;
	if(listaTransporte!=NULL && tam>0)
		{
			if(!listarTransportes(listaTransporte, tam))
			{
				printf("ERROR - No hay entidades cargadas\n");
			}
			else
			{
				printf("Ingrese el ID del transporte a modificar\n");
				cargarInt(&idModificacion);
				indiceModificacion=indicePorID(listaTransporte, tam, idModificacion);

				if(indiceModificacion!=-1 && !((listaTransporte+indiceModificacion)->isEmpty))
				{

					switch (submenuModificar()) {
						case 1:
							printf("Ingrese nuevo peso de carga: \n");
							cargarInt(&(listaTransporte+indiceModificacion)->pesoCarga);
							break;
						case 2:
							printf("Ingrese nueva cantidad de bultos: \n");
							cargarInt(&(listaTransporte+indiceModificacion)->cantidadBultos);
							break;
						default:

							break;
					}
					return EXIT_SUCCESS;
				}
				else
				{
					printf("ERROR - no se encontro ID\n");
				}
			}
		}
		return EXIT_FAILURE;
}


int submenuModificar(void)
{
	int opcion;

	printf("Que dato desea cambiar?\n");
	printf("1 - peso de carga\n");
	printf("2 - cantidad de bultos\n");
	printf("3 - salir\n");

	intEnRango(&opcion, 1, 3);

	return opcion;
}

int bajaTransporte(eTransporte *listaTransporte, int tam)
{
	int indiceBaja;
	int idBaja;
	if(listaTransporte!=NULL && tam>0)
	{
		if(!listarTransportes(listaTransporte, tam))
		{
			printf("ERROR - No hay entidades cargadas\n");
		}
		else
		{
			printf("Ingrese el ID del transporte a borrar\n");
			cargarInt(&idBaja);
			indiceBaja=indicePorID(listaTransporte, tam, idBaja);

			if(indiceBaja!=-1 && !((listaTransporte+indiceBaja)->isEmpty))
			{
				(listaTransporte+indiceBaja)->isEmpty=1;
				return EXIT_SUCCESS;
			}
			else
			{
				printf("ERROR - no se encontro ID\n");
			}
		}
	}
	return EXIT_FAILURE;
}

int indicePorID(eTransporte *listaTransporte, int tam, int id)
{
	int indice=-1;
	if(listaTransporte!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if((listaTransporte+i)->idTransporte==id)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}

int listarTransportes(eTransporte *listaTransporte, int tam)
{
	int contadorDeTransportes=0;
	if(listaTransporte!=NULL && tam>0)
	{

		for(int i=0;i<tam;i++)
		{
			if(!(listaTransporte+i)->isEmpty)
			{
				if(contadorDeTransportes==0)
				{
					printf("\t\tLISTA DE TRANSPORTES\n");
					printf("-----------------------------------------------------------------\n");
					printf("|  ID |     Descripcion    |  Peso |Bultos |        tipoID      |\n");
					printf("-----------------------------------------------------------------\n");
				}
				mostrarFilaTransporte((listaTransporte+i));
				contadorDeTransportes++;
			}
		}
	}
	return contadorDeTransportes;

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
