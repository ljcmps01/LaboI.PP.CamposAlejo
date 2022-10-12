/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "FECHA.h"
#include "TIPO.h"
#include "TRANSPORTE.h"
#include "HOJARUTA.h"

#define TAM 10

int main(void) {
	setbuf(stdout,NULL);

	eTransporte listaTransportes[TAM];
	int indice=MIN_TRASNPORTE_ID;

	int salida=0;

	if(inicializarTransporte(listaTransportes, TAM))
	{
		printf("Error de inicializacion\n");
		return EXIT_FAILURE;
	}

	hardcodearTransporte(listaTransportes, TAM, &indice);

	printf("Siguiente indice libre: %d\n",siguienteTransporteEmpty(listaTransportes, TAM));

	do
	{
		switch (imprimirMenuPrincipal()) {
			case 1:
				printf("Alta transporte\n");
				if(altaTransporte(listaTransportes, TAM, &indice))
				{
					printf("Alta fallida\n");
				}
				else
				{
					printf("Alta exitosa\n");
				}
				break;
			case 2:
				modificarTransporte(listaTransportes, TAM);
				break;
			case 3:
				if(!bajaTransporte(listaTransportes, TAM))
				{
					printf("Se dio de baja el transporte exitosamente\n");
				}
				else
				{
					printf("Error en la baja\n");
				}
				break;
			case 4:
				printf("Lista Transporte\n");
				listarTransportes(listaTransportes,TAM);
				break;
			case 5:
				printf("Listar Tipos\n");
				break;
			case 6:
				printf("Listar hojas de ruta\n");
				break;
			case 7:
				printf("Informe\n");
				break;
			default:
				printf("SALIDA\n");
				salida=1;
				break;
		}
	}while(!salida);


	printf("\nPROGRAMA FINALIZADO\n");
	return EXIT_SUCCESS;
}


