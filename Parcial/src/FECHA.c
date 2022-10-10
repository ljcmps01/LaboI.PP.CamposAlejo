/*
 * FECHA.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#include "FECHA.h"

int validarDia(int dia)
{

	return enRango(dia, 0, 31);
}

int validarMes(int mes)
{

	return enRango(mes, 0, 12);
}

int validarAnio(int anio)
{
	return anio>2000;
}
