/*
 * INFORMES.h
 *
 *  Created on: 16 oct. 2022
 *      Author: ljcmp
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "TRANSPORTE.h"
#include "HOJARUTA.h"

int submenuInformes();

int mostrarTransportexTipo(eTransporte *listaTransporte, int tam);

int mostrarHojasxFecha(eHojaRuta *listaHojas, int tam);

int mostrarPrecioxTransporte(eTransporte *listaTransporte, eHojaRuta *listaHojas, int tam);

int precioxTransporte(eHojaRuta *listaHojas, int tam, int idTransporte);

int mostrarPrecioxTipoyFecha(eHojaRuta *listaHojas, eTransporte *listaTransporte, int tam);

float precioxTipoyFecha(eHojaRuta *listaHojas, eTransporte *listaTransporte, int tam, int tipoID, eFecha fecha);
#endif /* INFORMES_H_ */
