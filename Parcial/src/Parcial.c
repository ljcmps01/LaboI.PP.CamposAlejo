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

	if(inicializarTransporte(listaTransportes, TAM))
	{
		printf("Error de inicializacion\n");
		system("PAUSE");
		return EXIT_FAILURE;
	}

	switch (imprimirMenuPrincipal()) {
		case 1:
			printf("Alta transporte\n");
			break;
		case 2:
			printf("Modificar Transporte\n");
			break;
		case 3:
			printf("Baja Transporte\n");
			break;
		case 4:
			printf("Lista Transporte\n");
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
			break;
	}

	printf("\nPROGRAMA FINALIZADO\n");
	return EXIT_SUCCESS;
}


