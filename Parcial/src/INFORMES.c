/*
 * INFORMES.c
 *
 *  Created on: 16 oct. 2022
 *      Author: ljcmp
 */


#include "INFORMES.h"


int submenuInformes()
{
	int opcion;

	printf("1 - Mostrar transportes de un tipo\n");
	printf("2 - Mostrar todas las hojas de ruta efectuadas en una fecha seleccionada\n");
	printf("3 - Informar importe total de las hojas de ruta realizadas en un transporte seleccionado\n");
	printf("4 - Informar importe total de todas las hojas de ruta de un tipo en una fechaseleccionada\n");
	printf("5 - Salir\n");
	printf("\n");

	intEnRango(&opcion, 1, 5);

	return opcion;
}

int mostrarTransportexTipo(eTransporte *listaTransporte, int tam)
{
	int tipoID;
	if(listaTransporte!=NULL && tam>0)
	{
		listarTipos(tipos, TAM_TIPOS);
		printf("Ingresar id del tipo a mostrar: ");
		intEnRango(&tipoID, 1000, 1004);

		imprimirTransportexTipo(listaTransporte, tam, tipoID);

		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}


int mostrarHojasxFecha(eHojaRuta *listaHojas, int tam)
{
	eFecha fecha;
	if(listaHojas!=NULL && tam>0)
	{
		printf("Ingrese fecha a buscar:\n");
		cargarFecha(&fecha);

		printf("Se ingreso la fecha: ");
		mostrarFecha(fecha);
		printf("\n");

		imprimirHojasxFecha(listaHojas, tam, fecha);

		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}


int mostrarPrecioxTransporte(eTransporte *listaTransporte, eHojaRuta *listaHojas, int tam)
{
	int transporteID;
	int precioTotal;
	if(listaTransporte!=NULL && listaHojas !=NULL && tam>0)
	{
		if(!listarTransportes(listaTransporte, tam))
		{
			printf("ERROR - no se ingreso ningun transporte todavia\n");
			return EXIT_FAILURE;
		}

		do
		{
			printf("ingrese ID del transporte a asignar la hoja de ruta: 	");
			cargarInt(&transporteID);

		}while(!existeTransporte(listaTransporte, tam, transporteID));

		precioTotal=precioxTransporte(listaHojas, tam, transporteID);
		if(precioTotal==-1)
		{
			printf("Error al sumar precios");
		}
		else
		{
			printf("Precio total del id dado: %d\n",precioTotal);
		}
	}
	return EXIT_FAILURE;
}


int precioxTransporte(eHojaRuta *listaHojas, int tam, int idTransporte)
{
	int precioTotal=0;
	if(listaHojas!=NULL && tam>0)
	{
		for (int i = 0; i < tam; ++i) {
			if((*(listaHojas+i)).transporteId==idTransporte)
			{
				precioTotal+=(*(listaHojas+i)).precioViaje;
			}
		}
		if(precioTotal==0)
		{
			printf("No se encontraron coincidencias\n");
			return -1;
		}
		return precioTotal;
	}

	return -1;
}

int mostrarPrecioxTipoyFecha(eHojaRuta *listaHojas, eTransporte *listaTransporte, int tam)
{
	int bufferTipo;
	eFecha bufferFecha;
	float importeTotal;

	if(listaHojas!=NULL && listaTransporte!=NULL && tam>0)
	{
		printf("ingrese tipo\n");
		listarTipos(tipos, TAM_TIPOS);

		intEnRango(&bufferTipo, 1000, 1004);

		cargarFecha(&bufferFecha);

		importeTotal=precioxTipoyFecha(listaHojas, listaTransporte, tam, bufferTipo, bufferFecha);

		if(importeTotal>0)
		{
			printf("El importe total es de: $%.2f\n",importeTotal);
		}
		else
		{
			if(importeTotal==0)
			{
				printf("No se encontro hojas de ruta con los datos ingresados\n");
			}
			else
			{

				printf("ERROR validacion de punteros\n");
			}
		}

		return(EXIT_SUCCESS);
	}


	return EXIT_FAILURE;
}

float precioxTipoyFecha(eHojaRuta *listaHojas, eTransporte *listaTransporte, int tam, int tipoID, eFecha fecha)
{
	int bufferIndiceTransporte;
	float importeAcumulado=0;

	if(listaHojas!=NULL && listaTransporte!=NULL && tam>0)
	{
		for (int i = 0; i < tam; ++i) {
			if(compararFechas((*(listaHojas+i)).fecha, fecha))
			{
				bufferIndiceTransporte=indicePorID(listaTransporte, tam, (*(listaHojas+i)).transporteId);
				if((*(listaTransporte+bufferIndiceTransporte)).tipoId==tipoID)
				{
					importeAcumulado+=(*(listaHojas+i)).precioViaje;
				}
			}
		}
		return importeAcumulado;
	}

	return -1;
}










