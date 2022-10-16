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
#include <string.h>

#include "INPUT.h"

#define MIN_TRASNPORTE_ID 10000

#define TAM_TIPOS 4

typedef struct
{
	int idTipo;
	char descripcion[30];
}eTipo;

typedef struct
{
	int idTransporte;
	char descripcion[30];	//max 30
	int pesoCarga;
	int cantidadBultos;
	int tipoId;
	int isEmpty;
}eTransporte;

eTipo tipos[TAM_TIPOS];

int imprimirTransportexTipo(eTransporte *listaTransporte, int tam, int idTipo);

int getDescripcionTipo(char *destino,int tipoID,eTipo* listaTipos);

void listarTipos(eTipo* listaTipos, int tam);

/**
 * @fn int existeTransporte(eTransporte*, int, int)
 * @brief busca dentro de la lista dada como parametro la existencia de una
 * entidad cuyo ID coincida con aquel dado de parametro
 *
 * @param listaTransporte
 * @param tam
 * @param id
 * @return
 */
int existeTransporte(eTransporte *listaTransporte, int tam, int id);

/**
 * @fn int ordenarTransportes(eTransporte*, int)
 * @brief Ordena las entidades primero por id de tipo y luego por descripcion
 *
 * @param listaTransporte puntero a la lista de transportes
 * @param tam
 * @return retorna 0 en caso de swappeo exitoso y 1 en caso de error
 */
int ordenarTransportes(eTransporte *listaTransporte, int tam);

/**
 * @fn int swapTransporte(eTransporte*, eTransporte*)
 * @brief Swappea de indice los transportes dados como parametros
 *
 * @param transporteA
 * @param transporteB
 * @return retorna 0 en caso de orden exitoso y 1 en caso de error
 */
int swapTransporte(eTransporte *transporteA,eTransporte *transporteB);

/**
 * @fn int modificarTransporte(eTransporte*, int)
 * @brief le pide al usuario que ingrese el id de una de las entidades cargadas
 * 		y si existe le pregunta que desea modificar, y luego le modifica el valor dado
 *
 * @param listaTransporte puntero a la lista de transportes
 * @param tam
 * @return retorna 0 en caso de modificacion exitosa y 1 en caso de error
 */
int modificarTransporte(eTransporte *listaTransporte, int tam);

/**
 * @fn int submenuModificar(void)
 * @brief	Imprime el submenu de modificar y le pide al usuario que ingrese una de las opciones disponibles
 *
 * @return retorna el valor de la opcion elegida
 */
int submenuModificar(void);

/**
 * @fn int bajaTransporte(eTransporte*, int)
 * @brief	Pide al usuario que ingrese el id de una entidad, lo valida y si existe le da
 *  una baja logica
 *
 * @param listaTransporte puntero a la lista de transportes
 * @param tam
 * @return retorna 0 en caso de baja exitosa y 1 en caso de error
 */
int bajaTransporte(eTransporte *listaTransporte, int tam);

/**
 * @brief obtiene el indice de la entidad que contenga el id dado como parametro
 *
 * @param listaTransporte puntero a la lista de transportes
 * @param tam tamaño de la lista
 * @param id id a buscar
 * @return retorna el indice obtenido o -1 en caso de no encontrar coincidencia
 */
int indicePorID(eTransporte *listaTransporte, int tam, int id);

/**
 * @brief lista fila por fila todos los transportes cargados
 *
 * @param listaTransporte puntero a la lista de transportes
 * @param tam tamaño de la lista
 * @return retorna 0 en caso de exito, 1 en caso de error
 */
int listarTransportes(eTransporte *listaTransporte, int tam);

/**
 * @brief Muestra los datos de una entidad dada como parametro
 *
 * @param transporte puntero a la entidad a mostrar
 * @return retorna la cantidad de entidades impresas
 */
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
