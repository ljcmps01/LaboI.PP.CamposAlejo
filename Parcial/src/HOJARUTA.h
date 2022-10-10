/*
 * HOJARUTA.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef HOJARUTA_H_
#define HOJARUTA_H_

#include "FECHA.h"

#define MIN_HOJA_ID 20000

typedef struct
{
	int idHoja;	//Comienza en 20000
	int transporteId;//Debe existir y validad
	int precioViaje;
	int kmsTotales;
	eFecha fecha;
}eHojaRuta;

#endif /* HOJARUTA_H_ */
