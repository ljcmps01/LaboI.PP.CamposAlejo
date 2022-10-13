/*
 * FECHA.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef FECHA_H_
#define FECHA_H_

#include "UTN.h"
#include "INPUT.h"

#define MIN_ANIO 1900

typedef struct
{
	int dia;
	int mes;
	int anio;
}
eFecha;

/**
 * @fn void mostrarFecha(eFecha)
 * @brief imprime los datos de la entidad pasada como parametro ya formateados
 *
 * @param fecha
 */
void mostrarFecha(eFecha fecha);

/**
 * @fn int validarDia(int)
 * @brief Valida que el dia este dentro de un rango (1:31)
 *
 * @param mes valor del dia a analizar
 * @return retorna 1 si el valor pasado de parametro es valido, 0 si no lo es
 */
int validarDia(int dia);


/**
 * @fn int validarMes(int)
 * @brief Valida que el mes este dentro de un rango (1:12)
 *
 * @param mes valor del mes a analizar
 * @return retorna 1 si el valor pasado de parametro es valido, 0 si no lo es
 */
int validarMes(int mes);

/**
 * @fn int validarAnio(int)
 * @brief Valida que el año sea positivo y mayor que un minimo constante (MIN_ANIO)
 *
 * @param anio valor del año a analizar
 * @return retorna 1 si el valor pasado de parametro es valido, 0 si no lo es
 */
int validarAnio(int anio);

/**
 * @fn void cargarFecha(eFecha*)
 * @brief Carga los datos de una fecha en una entidad eFecha pasada como puntero
 *
 * @param fecha Puntero a cargar
 */
void cargarFecha(eFecha *fecha);

#endif /* FECHA_H_ */
