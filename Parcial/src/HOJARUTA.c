/*
 * HOJARUTA.c
 *
 *  Created on: 12 oct. 2022
 *      Author: ljcmp
 */


#include "HOJARUTA.h"


int listarHojas(eHojaRuta *listaHoja, int tam)
{
	int contadorDeHojas=0;
	if(listaHoja!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(!((listaHoja+i)->isEmpty))
			{
				if(contadorDeHojas==0)
				{
					printf("\t\tLISTA DE Hojas\n");
					printf("-----------------------------------------------------------------\n");
					printf("|  ID |ID de transporte|  Precio |   KMs  |         fecha       |\n");
					printf("-----------------------------------------------------------------\n");
				}
				mostrarFilaHoja((listaHoja+i));
				contadorDeHojas++;
			}
		}
	}
	return contadorDeHojas;

}

int mostrarFilaHoja(eHojaRuta *hoja)
{
	if(hoja!=NULL)
	{
		printf("|%-5d|%16d|%9.2f|%8d|      ",hoja->idHoja,hoja->transporteId,hoja->precioViaje,hoja->kmsTotales);
		mostrarFecha(hoja->fecha);
		printf("|\n");
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

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
			printf("ERROR - no se ingreso ningun transporte todavia\n");
			return EXIT_FAILURE;
		}

		do
		{
			printf("ingrese ID del transporte a asignar la hoja de ruta: (o 0 para cancelar)\n");
			cargarInt(&bufferHojas.transporteId);
			if(bufferHojas.transporteId==0)
			{
				return EXIT_FAILURE;
			}

		}while(!existeTransporte(listaTransporte, tam, bufferHojas.transporteId));

		printf("ingrese precio del viaje\n");
		cargarFloat(&bufferHojas.precioViaje);

		printf("ingrese cantidad de km totales\n");
		cargarInt(&bufferHojas.kmsTotales);

		cargarFecha(&(bufferHojas.fecha));

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
