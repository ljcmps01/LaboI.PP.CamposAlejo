/*
 * FECHA.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#include "FECHA.h"

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
