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


#endif /* INFORMES_H_ */
