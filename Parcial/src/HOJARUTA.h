/*
 * HOJARUTA.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef HOJARUTA_H_
#define HOJARUTA_H_

#include "UTN.h"
#include "TRANSPORTE.h"
#include "INPUT.h"

#define MIN_ANIO 1900

#define MIN_HOJA_ID 20000

typedef struct
{
	int dia;
	int mes;
	int anio;
}
eFecha;

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
 * @fn int imprimirHojasxFecha(eHojaRuta*, int, eFecha)
 * @brief Imprime las hojas de ruta que posean la misma fecha dada como parametro
 *
 * @param listaHoja puntero a la lista de hojas de ruta
 * @param tam tamaño de la lista de hojas de ruta
 * @param fechaUsuario fecha deseada a buscar
 * @return	retorna 1 en caso de haber encontrado un error de punteros, 0 si
 * se completo la funcion correctamente
 */
int imprimirHojasxFecha(eHojaRuta *listaHoja, int tam, eFecha fechaUsuario);

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


/********************************************************************************
 * 							funciones eFecha									*
 ********************************************************************************/

/**
 * @brief Compara dos fechas por igualdad
 *
 * @param a
 * @param b
 * @return	retorna 0 si son distintas y 1 si son iguales
 */
int compararFechas(eFecha a,eFecha b);

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

#endif /* HOJARUTA_H_ */
