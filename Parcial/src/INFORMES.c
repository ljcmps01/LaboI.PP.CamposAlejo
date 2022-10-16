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
