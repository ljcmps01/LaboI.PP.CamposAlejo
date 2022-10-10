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

#define minID 1000

typedef struct
{
	int idTipo;
	char descripcion[30];
}eTipo;

eTipo tipos[4];


void listarTipos(eTipo* listaTipos, int tam);

#endif /* TIPO_H_ */
