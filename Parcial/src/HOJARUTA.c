/*
 * HOJARUTA.c
 *
 *  Created on: 12 oct. 2022
 *      Author: ljcmp
 */


#include "HOJARUTA.h"

int imprimirHojasxFecha(eHojaRuta *listaHoja, int tam, eFecha fechaUsuario)
{
	int coincidencias=0;
	if(listaHoja!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(compararFechas((*(listaHoja+i)).fecha, fechaUsuario))
			{
				mostrarFilaHoja((listaHoja+i));
				coincidencias++;
			}
		}
		if(coincidencias==0)
		{
			printf("No se encontraron hojas con la fecha dada\n");
		}

		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

int listarHojas(eHojaRuta *listaHoja, int tam)
{
	int contadorDeHojas=0;
	if(listaHoja!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(!((*(listaHoja+i)).isEmpty))
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
		printf("|%-5d|%16d|%9.2f|%8d|      ",(*hoja).idHoja,(*hoja).transporteId,(*hoja).precioViaje,(*hoja).kmsTotales);
		mostrarFecha((*hoja).fecha);
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
				(*(listaHojas+contador)).isEmpty=1;
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
				if(((*(listaHojas+siguienteLibre)).isEmpty))
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
			printf("ingrese ID del transporte a asignar la hoja de ruta: 	");
			cargarInt(&bufferHojas.transporteId);

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

/********************************************************************************
 * 							funciones eFecha									*
 ********************************************************************************/

int compararFechas(eFecha a,eFecha b)
{
	if(a.dia==b.dia)
	{
		if(a.mes==b.mes)
		{
			if(a.anio==b.anio)
			{
				return 1;
			}
		}
	}

	return 0;
}

void mostrarFecha(eFecha fecha)
{
	printf("%d / %d / %d ", fecha.dia, fecha.mes, fecha.anio);
}

int validarDia(int dia)
{
	return enRango(dia, 1, 31);
}

int validarMes(int mes)
{

	return enRango(mes, 1, 12);
}

int validarAnio(int anio)
{
	return anio>MIN_ANIO;
}

void cargarFecha(eFecha *fecha)
{
	eFecha temporal;

	do
	{
		printf("Ingrese dia: \n");
	cargarInt(&temporal.dia);
	}while(!validarDia(temporal.dia));

	do
	{
		printf("Ingrese mes: \n");
	cargarInt(&temporal.mes);
	}while(!validarMes(temporal.mes));

	do
	{
		printf("Ingrese anio: \n");
	cargarInt(&temporal.anio);
	}while(!validarAnio(temporal.anio));
	*fecha=temporal;
}

