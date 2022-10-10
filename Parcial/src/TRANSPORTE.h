/*
 * TRANSPORTE.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

#include <stdio.h>
#include <stdlib.h>
#include "INPUT.h"

typedef struct
{
	int idTransporte;
	char *descripcion;	//max 30
	int pesoCarga;
	int cantidadBultos;
	int tipoId;
	int isEmpty;
}eTransporte;

/**
 * @brief inicializa los campos isEmpty de la estructura eTransporte en 1
 *
 * @param transporte puntero a la lista de entidades a inicializar
 * @param tam cantidad de entidades
 * @return retorna 1 en caso de error y 0 en caso de exito
 */
int inicializarTransporte(eTransporte *transporte,int tam);

/**
 * @brief imprime el menu principal del ABM de logistica y pide al usuario que ingrese una opcion
 *
 * @return retorna una opcion valida del menu
 */
int imprimirMenuPrincipal(void);

#endif /* TRANSPORTE_H_ */
