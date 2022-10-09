/*
 * UTN.h
 *
 *  Created on: 20 sep. 2022
 *      Author: ljcmp
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief valida que la cadena son solo letras
* \param cadena es un puntero al espacio de memoria donde se dejara el
resultado de la funcion
* return Retorna 1 si todo ok, 0, SI ES ERROR.
*/
int esSoloLetra(char *pResultado);

/**
* \brief valida que la cadena son solo letras y espacio en el medio
* \param cadena es un puntero al espacio de memoria donde se dejara el
* resultado de la funcion
* return Retorna 1 si todo ok, 0, SI ES ERROR.
*/
int esLetraConEspacio(char *pResultado);

int estaEnRango(int dato,int min, int max);

int reemplazarChar(char *string, char busqueda, char reemplazo);

void listarMenu(char *array,int tam, int len);

void imprimirString(char *mensaje,int max);

/**
 * \fn int burbujeo(int*, int)
 * \brief ordena un array en orden ascendente por algoritmo de burbujeo
 *
 * \param array puntero del array a ordenar
 * \param tam tamaño del array
 * \return
 */
int burbujeo(int *array,int tam);

/**
 * \fn int listarArray(int*, int, int)
 * \brief lista todos o una parte de los elementos de un array de enteros
 *
 * \param array puntero al primer elemento del array
 * \param tam tamaño del array
 * \param enumerar si vale 1 imprime cada elemento con su indice, si vale 0 solo se lista
 * \return
 */
int listarArray(int *array,int tam, int enumerar);


/**
 * \fn int swap(int*, int*)
 * \brief swappea los valores de a y b
 *
 * \param a
 * \param b
 * \return retorna 0 si el swap fue exitoso, caso contrario retorna 1
 */
int swap(int *a,int *b);

/**
 * @brief
 * Le pide al usuario que ingrese un float, si no ingresa un float
 * le volvera a pedir al usuario que ingrese un valor valido
 *
 * @param dato: puntero de la variable a modifica
 */
void cargarFloat(float *dato);

/**
 * @brief
 * Le pide al usuario que ingrese un float, si no ingresa un int
 * le volvera a pedir al usuario que ingrese un valor valido
 *
 * @param dato
 */
void cargarInt(int *dato);

/**
 * @brief
 *	Verifica si un entero esta por debajo de un umbral
 *
 * @param dato
 * @param umbral
 * @return si esta por debajo devuelve 1, sino devuelve 0
 */
int esMenorQue(int dato, int umbral);


/**
 * @brief
 *	Verifica si un entero esta por encima de un umbral
 *
 * @param dato
 * @param umbral
 * @return si esta por encima devuelve 1, sino devuelve 0
 */
int esMayorQue(int dato, int umbral);

/**
 * @brief
 * Pide al usuario que ingrese un entero, si se encuentra fuera del rango
 * dado por min y max se le pide al usuario que vuelva a ingresar
 *
 * @param dato: puntero donde se guardará el valor valido
 * @param min: valor minimo del rango
 * @param max: valor maximo del rango
 */
void intEnRango(int *dato,int min, int max);

/**
 * @brief
 * Le pide al usuario que ingrese un float, si no ingresa un char
 * le volvera a pedir al usuario que ingrese un valor valido
 *
 * @param dato: puntero de la variable a modifica
 */
void cargarChar(char *dato);

/**
 * @brief
 * Obtiene el promedio
 *
 * @param total: valor del tamaño total de la muestra
 * @param cantidad: porcion para calcular el promedio
 * @return	retorna el promedio calculado
 */
float calcularPromedio(int total,int cantidad);

/**
 * @brief
 *  calcula el porcentaje que representa la porcion sobre el total
 *
 * @param porcion, porcion o fraccion a calcular del total
 * @param total, total de la muestra
 * @return	retorna el porcentaje que representa la fraccion
 */
float calcularPorcentaje(int porcion,int total);

#endif /* UTN_H_ */
