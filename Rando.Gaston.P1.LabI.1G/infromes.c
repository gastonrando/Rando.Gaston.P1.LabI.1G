#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"

int menuInformes(){

int opcion;
    system("cls");
    printf("     *** Menu Informes ***\n");
    printf(" 1- Micros segun Empresa\n");
    printf(" 2- Micros segun Tipo\n");
    printf(" 3- Listado de Empresas con micros VIP\n");
    printf(" 4- Listado de micros separados por Empresa\n");
    printf(" 5- Listado de empresas con mayor capacidad\n");
    printf(" 6- Listado de empresas con menor cantidad de micros\n");
    printf(" 7- Informe de viajes segun micro\n");
    printf(" 8- Suma de precios de viajes realizado por micro a eleccion\n");
    printf(" 9- SALIR\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    opcion=tolower(opcion);

    return opcion;

    }
