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


/**
 * @fn int listarHojas(eHojaRuta*, int)
 * @brief imprime la lista de hojas de ruta cargadas y no vacias
 *
 * @param listaHoja
 * @param tam
 * @return retorna 0 en caso de exito y 1 en caso de error
 */
int listarHojas(eHojaRuta *listaHoja, int tam);

/**
 * @fn int mostrarFilaHoja(eHojaRuta*)
 * @brief Muestra una unica entidad de las hojas de ruta
 *
 * @param hoja Entidad a imprimir
 * @return retorna 0 en caso de exito y 1 en caso de error
 */
int mostrarFilaHoja(eHojaRuta *hoja);

/**
 * @fn int altaHoja(eHojaRuta*, eTransporte*, int, int*)
 * @brief	le pide al usuario toda la informacion necesaria para dar de alta
 * una hoja de ruta y valida que los inputs sean correctos
 *
 * @param listaHojas	puntero a la lista de hoja
 * @param listaTransporte	puntero a la lista de transportes
 * @param tam tamaño de las listas
 * @param id
 * @return retorna 0 en caso de exito y 1 en caso de error
 */
int altaHoja(eHojaRuta *listaHojas, eTransporte*listaTransporte ,int tam, int *id);

/**
 * @fn int siguienteHojaEmpty(eHojaRuta*, int)
 * @brief busca la siguiente hoja vacia
 *
 * @param listaHojas puntero a lista de hojas de ruta
 * @param tam cantidad de hojas de ruta a inicializar
 * @return retorna el indice de la entidad libre
 */
 */
int siguienteHojaEmpty(eHojaRuta *listaHojas,int tam);

/**
 * @fn int inicializarHojas(eHojaRuta*, int)
 * @brief inicializa las hojas de ruta
 *
 * @param listaHojas puntero a lista de hojas de ruta
 * @param tam cantidad de hojas de ruta a inicializar
 * @return retorna 0 en caso de exito y 1 en caso de error
 */
int inicializarHojas(eHojaRuta *listaHojas,int tam);

#endif /* HOJARUTA_H_ */
