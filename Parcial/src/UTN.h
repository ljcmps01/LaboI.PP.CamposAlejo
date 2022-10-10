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
