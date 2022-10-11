/*
 * Tipo.h
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

#ifndef TIPO_H_
#define TIPO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TIPOS 4

typedef struct
{
	int idTipo;
	char descripcion[30];
}eTipo;

eTipo tipos[TAM_TIPOS];

int getDescripcionTipo(char *destino,int tipoID,eTipo* listaTipos);

void listarTipos(eTipo* listaTipos, int tam);

#endif /* TIPO_H_ */
