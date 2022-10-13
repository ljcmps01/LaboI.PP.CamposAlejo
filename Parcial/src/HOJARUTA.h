/*
 * HOJARUTA.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef HOJARUTA_H_
#define HOJARUTA_H_

#include "FECHA.h"
#include "TRANSPORTE.h"
#include "INPUT.h"

#define MIN_HOJA_ID 20000

typedef struct
{
	int idHoja;	//Comienza en 20000
	int transporteId;//Debe existir y validad
	float precioViaje;
	int kmsTotales;
	eFecha fecha;
	int isEmpty;
}eHojaRuta;


int altaHoja(eHojaRuta *listaHojas, eTransporte*listaTransporte ,int tam, int *id);

int siguienteHojaEmpty(eHojaRuta *listaHojas,int tam);

int inicializarHojas(eHojaRuta *listaHojas,int tam);

#endif /* HOJARUTA_H_ */
