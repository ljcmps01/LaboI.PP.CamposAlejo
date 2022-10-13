/*
 * HOJARUTA.c
 *
 *  Created on: 12 oct. 2022
 *      Author: ljcmp
 */


#include "HOJARUTA.h"



int inicializarHojas(eHojaRuta *listaHojas,int tam)
{
	int contador=0;

		if(listaHojas!=NULL && tam>0)
		{
			while(contador<tam)
			{
				(listaHojas+contador)->isEmpty=1;
				contador++;
			}
		}
		else
		{
			return 1;	//error de inicializacion
		}
		return 0;	//Exito
}

int siguienteHojaEmpty(eHojaRuta *listaHojas,int tam)
{
	int siguienteLibre=0;

		if(listaHojas!=NULL && tam>0)
		{
			while(siguienteLibre<tam)
			{
				if(((listaHojas+siguienteLibre)->isEmpty))
				{
					return siguienteLibre;
				}
				siguienteLibre++;
			}
		}
		return -1;
}

int altaHoja(eHojaRuta *listaHojas, eTransporte*listaTransporte ,int tam, int *id)
{
	eHojaRuta bufferHojas;
	int indice;

	if(listaHojas!=NULL && listaTransporte && tam>0 && id!=NULL)
	{
		indice=siguienteHojaEmpty(listaHojas, tam);
		if(indice==-1)
		{
			printf("No hay espacio para mas Hojas\n");
			return EXIT_FAILURE;
		}

		bufferHojas.idHoja=*id;

		if(!listarTransportes(listaTransporte, tam))
		{
			printf("ERROR - no se ingreso ningun transporte todavia");
			return EXIT_FAILURE;
		}

		do
		{
			printf("ingrese ID del transporte a asignar la hoja de ruta:\n");
			cargarInt(&bufferHojas.transporteId);

		}while(!existeTransporte(listaTransporte, tam, bufferHojas.transporteId));

		printf("ingrese precio del viaje\n");
		cargarFloat(&bufferHojas.precioViaje);

		printf("ingrese cantidad de km totales\n");
		cargarInt(&bufferHojas.kmsTotales);

		cargarFecha(bufferHojas.fecha);

		bufferHojas.isEmpty=0;

		*(listaHojas+indice)=bufferHojas;

		(*id)++;

		return EXIT_SUCCESS;

	}
	else
	{
		printf("Error de punteros\n");
		return EXIT_FAILURE;
	}

	return EXIT_FAILURE;
}
