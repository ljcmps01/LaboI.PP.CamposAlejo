/*
 * INPUT.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef INPUT_H_
#define INPUT_H_

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

int cargarString(char *string,int tam);

int enRango(int dato,int min, int max);

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
 * Pide al usuario que ingrese un entero, si se encuentra fuera del rango
 * dado por min y max se le pide al usuario que vuelva a ingresar
 *
 * @param dato: puntero donde se guardará el valor valido
 * @param min: valor minimo del rango
 * @param max: valor maximo del rango
 */
void intEnRango(int *dato,int min, int max);

#endif /* INPUT_H_ */
