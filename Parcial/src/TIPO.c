/*
 * TIPO.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */

//Tipo: (1-CAMION RECTO, 2-CAMION REMOLQUE, 3-CAMION SEMIRREMOLQUE, 4-CAMION
//ELEVADOR)
#include "TIPO.h"

eTipo tipos[TAM_TIPOS]=
{
		{1000,"Camion recto"},
		{1001,"Camion remolque"},
		{1002,"Camion semirremolque"},
		{1003,"Camion elevador"}
};


int getDescripcionTipo(char *destino,int tipoID,eTipo* listaTipos)
{
	if(destino!=NULL && listaTipos!=NULL)
	{
		for(int i=0;i<TAM_TIPOS;i++)
		{
			if(tipoID==(listaTipos+i)->idTipo)
			{
				strcpy(destino,(listaTipos+i)->descripcion);
				return 1;
			}
		}
		printf("idTipo error\n");
		return 0;
	}
	return 0;
}

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
