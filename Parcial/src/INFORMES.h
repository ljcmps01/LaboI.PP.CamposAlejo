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

/**
 * @fn int submenuInformes()
 * @brief imprime el submenu de opciones de informes y pide al usuario
 * una opcion valida
 *
 * @return	retorna la opcion ingresada por el usuario
 */
int submenuInformes();

/**
 * @fn int mostrarTransportexTipo(eTransporte*, int)
 * @brief	pide al usuario el id del tipo de transporte que desea buscar
 * y lista todos los transportes que coincidan con ese id de tipo
 *
 * @param listaTransporte
 * @param tam
 * @return	1 en caso de error de puntero, 0 en caso de funcion ejecutada correctamente
 */
int mostrarTransportexTipo(eTransporte *listaTransporte, int tam);

/**
 * @fn int mostrarHojasxFecha(eHojaRuta*, int)
 * @brief  pide al usuario que ingrese una fecha y lista todas las hojas de ruta
 * que coincidan con esa fecha
 *
 * @param listaHojas
 * @param tam
 * @return	1 en caso de error de puntero, 0 en caso de funcion ejecutada correctamente
 */
int mostrarHojasxFecha(eHojaRuta *listaHojas, int tam);

/**
 * @fn int mostrarPrecioxTransporte(eTransporte*, eHojaRuta*, int)
 * @brief	pide al usuario que ingrese el id de un transporte ingresado previamente
 * e imprime el importe total acumulado por las hojas de ruta asignadas a ese
 * transporte
 *
 * @param listaTransporte
 * @param listaHojas
 * @param tam
 * @return@return	1 en caso de error de puntero o lista de transporte nula, 0 en caso de funcion ejecutada correctamente
 */
int mostrarPrecioxTransporte(eTransporte *listaTransporte, eHojaRuta *listaHojas, int tam);

/**
 * @fn int precioxTransporte(eHojaRuta*, int, int)
 * @brief recorre la lista de hojas buscando todas aquellas cuyo id de transporte
 * coincida con aquel dado como parametro y en caso de coincidencia acumula el
 * importe obtenido
 *
 * @param listaHojas
 * @param tam
 * @param idTransporte ID ingresado por el usuario
 * @return	retorna el importe acumulado para el ID dado
 */
int precioxTransporte(eHojaRuta *listaHojas, int tam, int idTransporte);

/**
 * @fn int mostrarPrecioxTipoyFecha(eHojaRuta*, eTransporte*, int)
 * @brief pide y valida del usuario un tipo de id y una fecha, e imprime la
 * acumulacion de importes de las hojas de ruta que coincidan con ambos parametros
 *
 * @param listaHojas
 * @param listaTransporte
 * @param tam
 * @return@return	1 en caso de error de puntero o lista de transporte nula, 0 en caso de funcion ejecutada correctamente
 */
int mostrarPrecioxTipoyFecha(eHojaRuta *listaHojas, eTransporte *listaTransporte, int tam);

/**
 * @fn float precioxTipoyFecha(eHojaRuta*, eTransporte*, int, int, eFecha)
 * @brief busca las hojas de ruta que coincidan con los parametros dados por el usuario
 * y acumula el importe de aquellas hojas de ruta que coincidan
 *
 * @param listaHojas
 * @param listaTransporte
 * @param tam
 * @param tipoID
 * @param fecha
 * @return retorna el importe acumulado de las hojas de ruta coincidentes
 */
float precioxTipoyFecha(eHojaRuta *listaHojas, eTransporte *listaTransporte, int tam, int tipoID, eFecha fecha);
#endif /* INFORMES_H_ */
