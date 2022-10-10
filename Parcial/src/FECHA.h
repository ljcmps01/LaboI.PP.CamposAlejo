/*
 * FECHA.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef FECHA_H_
#define FECHA_H_

#include "UTN.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}
eFecha;

int validarDia(int dia);

int validarMes(int mes);

int validarAnio(int anio);

#endif /* FECHA_H_ */
