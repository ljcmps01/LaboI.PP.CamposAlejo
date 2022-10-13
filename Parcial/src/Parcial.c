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

	eHojaRuta listaHojaRuta[TAM];
	int idHojaRuta=MIN_HOJA_ID;

	int salida=1;

	if(inicializarTransporte(listaTransportes, TAM))
	{
		printf("Error de inicializacion de transporte\n");
		return EXIT_FAILURE;
	}
	if(inicializarHojas(listaHojaRuta, TAM))
	{
		printf("Error de inicializacion de hojas de ruta\n");
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
				listarTipos(tipos, TAM_TIPOS);
				break;
			case 6:
				printf("Alta Hoja de ruta\n");
				if(altaHoja(listaHojaRuta, listaTransportes, TAM, &idHojaRuta))
				{
					printf("Alta fallida\n");
				}
				else
				{
					printf("Alta exitosa\n");
				}
				break;
			case 7:
				printf("Listar hojas de ruta\n");
				break;
			case 8:
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


