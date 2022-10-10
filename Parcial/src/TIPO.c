/*
 * TIPO.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

//Tipo: (1-CAMION RECTO, 2-CAMION REMOLQUE, 3-CAMION SEMIRREMOLQUE, 4-CAMION
//ELEVADOR)
#include "TIPO.h"

eTipo tipos[4]=
{
		{1000,"Camion recto"},
		{1001,"Camion remolque"},
		{1002,"Camion semirremolque"},
		{1003,"Camion elevador"}
};

void listarTipos(eTipo* listaTipos, int tam)
{
	if(listaTipos!=NULL && tam>0)
	{
		for(int i=0;i < tam;i++)
		{
			printf("%d - %s\n",(listaTipos+i)->idTipo,(listaTipos+i)->descripcion);
		}
	}
}
