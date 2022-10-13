/*
 * INPUT.c
 *
 *  Created on: 9 oct. 2022
 *      Author: ljcmp
 */
#include "INPUT.h"

int esSoloLetra(char *pResultado)
{
	int contador=0;
	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		while(contador<strlen(pResultado))
		{
			if(!(enRango(*(pResultado+contador), 65, 89) ) && !(enRango(*(pResultado+contador), 97, 122)))
			{
				return 0;
			}

			contador++;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

int esLetraConEspacio(char *pResultado)
{
	int contador=0;
	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		while(contador<strlen(pResultado))
		{
			if(!(enRango(*(pResultado+contador), 65, 89) ) && !(enRango(*(pResultado+contador), 97, 122)) && *(pResultado+contador)!=32)
			{
				return 0;
			}

			contador++;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

int enRango(int dato,int min, int max)
{
	return (dato>=min && dato<=max);
}

void cargarFloat(float *dato)
{
	if(dato!=NULL&&dato>0)
	{
		float aux;
			int exito;
			int flagError=0;

			do
			{
				if(flagError)
				{
					printf("Ingrese valor valido\n");
				}
				fflush(stdin);
				exito=scanf("%f",&aux);
				//Si hay necesidad de volver a ingresar al bucle es porque efectivamente
				//hubo un error en la entrada de datos, caso contrario la funcion finalizará
				//exitosamente
				flagError=1;

			}while(!exito||aux<=0);

			*dato=aux;
	}
}

void cargarInt(int *dato)
{
	if(dato!=NULL)
	{
		int aux;
		int exito;
		int flagError=0;

		do
		{
			if(flagError)
			{
				printf("Ingrese valor valido\n");
			}

			fflush(stdin);
			exito=scanf("%d",&aux);
			flagError=1;

		}while(!exito||aux<=0);

		*dato=aux;
	}
}

void intEnRango(int *dato,int min, int max)
{
	if(dato!=NULL)
	{
		int aux;
		int flagError=0;

		do
		{
			if(flagError)
			{
				printf("Ingrese valor valido\n");
			}
			cargarInt(&aux);
			flagError=1;
		}while (!enRango(aux, min, max));

		*dato=aux;
	}
}
