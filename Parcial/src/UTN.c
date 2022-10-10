/*|
 * UTN.c
 *
 *  Created on: 24 sep. 2022
 *      Author: ljcmp
 */
#include "UTN.h"




int reemplazarChar(char *string, char busqueda, char reemplazo)
{
	int coincidencias=-1;

	if(string!=NULL && strlen(string) > 0)
	{
		coincidencias=0;
		for (int i=0; i<strlen(string) ;i++)
		{
			if(*(string+i)==busqueda)
			{
				*(string+i)=reemplazo;
				coincidencias++;
			}
		}
	}

	return coincidencias;
}

void imprimirString(char *mensaje,int max)
{
	for (int i = 0; i < 10 && mensaje[i]!='\0'; ++i) {
		printf("%c",mensaje[i]);
	}
}

void listarMenu(char *array,int tam, int len)
{
	for (int i = 0; i < tam; ++i) {
		printf("%d - ",i);
		imprimirString(&array[i*len], len);
		printf("\n");
	}
}

int burbujeo(int *array,int tam){
	for(int i=0;i<tam;i++)
	{
		for(int j=0;j<tam-1;j++)
		{
			//printf("%d vs %d\n",array[i],array[j]);
			if(array[j]>array[i])
			{
				//printf("%d es menor que %d\n",array[j],array[i]);
				swap(&array[i],&array[j]);

			}
		}
	}
	return 0;
}

int listarArray(int *array,int tam, int enumerar)
{
	if(array!=NULL&&array>0)
	{
		for (int i = 0; i < tam; ++i) {
			if(enumerar)
			{
				printf("%d - ",i);
			}
			printf("%d \n",array[i]);
		}
		printf("\n");
		return 0;
	}

	return 1;
}

int swap(int *a,int *b)
{
	if(a!=NULL && a>0 && b!=NULL && b>0)
	{
		int aux=*a;
		*a=*b;
		*b=aux;
		return 0;
	}
	return 1;
}



float calcularPromedio(int total,int cantidad)
{
	if(cantidad>0)
	{
		return (float)total/cantidad;
	}
	return 0;

}

float calcularPorcentaje(int porcion,int total)
{
	if(total>0)
	{
		return (float)porcion*100/total;
	}
	return 0;

}
