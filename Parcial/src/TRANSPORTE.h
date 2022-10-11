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
#include "TIPO.h"

#define MIN_TRASNPORTE_ID 10000

typedef struct
{
	int idTransporte;
	char *descripcion;	//max 30
	int pesoCarga;
	int cantidadBultos;
	int tipoId;
	int isEmpty;
}eTransporte;

int listarTransportes(eTransporte *listaTransporte, int tam);

int mostrarFilaTransporte(eTransporte *transporte);

/**
 * @brief	realiza la alta de una nueva entidad de transporte en caso de ser posible
 *
 * @param listaTransporte	puntero a la lista de transportes
 * @param tam	tamaño del puntero
 * @param pSigID	puntero a ID autoincremental
 * @return	retorna 0 en caso de alta exitoso, 1 en caso de error
 */
int altaTransporte(eTransporte *listaTransporte, int tam, int* pSigID);

/**
 * @brief hardcodea 4 entidades de transporte
 *
 * @param listaTransporte puntero a la lista de transportes
 * @param tam tamaño del puntero
 * @param pSigID	puntero a ID autoincremental
 * @return	retorna 0 en caso de alta exitoso, 1 en caso de error
 */
int hardcodearTransporte(eTransporte *listaTransporte, int tam, int *pSigID);

/**
 * @brief	Busca la siguiente entidad de transporte vacia
 *
 * @param listaTransporte	puntero a la lista de entidades de transporte
 * @param tam	Cantidad maxima de transporte
 * @return retorna el subindice correspondiente a la entidad vacia
 */
int siguienteTransporteEmpty(eTransporte *listaTransporte, int tam);

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
