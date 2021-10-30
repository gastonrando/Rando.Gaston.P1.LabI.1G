#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "chofer.h"


int cargarDescripcionChofer( eChofer choferes[], int tamC ,int idChofer, char nombre[] )
{
    int todoOk = 0;
    int flag = 1;
    if (choferes != NULL && tamC > 0 && nombre != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamC; i++)
        {
            if (choferes[i].id == idChofer)
            {
                strcpy(nombre, choferes[i].nombre);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}


int mostrarChoferes( eChofer choferes[], int tam )
{
    int todoOk = 0;
    if (choferes != NULL && tam > 0 )
    {
        printf("      *** Choferes *** \n\n");
        printf("  Id         Nombre     Sexo\n");
        for (int i = 0; i < tam; i++){
            if (!choferes[i].isEmpty)
            {
            printf("  %d       %-10s        %c\n", choferes[i].id, choferes[i].nombre, choferes[i].sexo);
            }
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int validarIdChoferes( int id, eChofer choferes[], int tam )
{
    int esValido = 0;
    if (choferes != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == choferes[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int inicializarChoferes(eChofer choferes[], int tam){

    int todoOk = 0;
    if (choferes != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            choferes[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreChoferes(eChofer choferes[], int tam)
{
    int indice = -1;
    if(choferes != NULL && tam > 0){

        for (int i = 0; i < tam; i++)
        {
            if (choferes[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaChoferes(eChofer choferes[], int tamC, int* pId)
{
    int todoOk = 0;
    int indice;

    eChofer auxChofer;

    if (choferes != NULL && tamC>0)
        {

        system("cls");
        printf("  ***Alta de Chofer*** \n\n");
        indice = buscarLibreChoferes(choferes, tamC);

        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxChofer.id = *pId;

            printf("Ingrese su nombre: \n");
			fflush(stdin);
			gets(auxChofer.nombre);

			printf("Ingrese su sexo (f-m): \n");
			fflush(stdin);
			scanf("%c",&auxChofer.sexo);
			auxChofer.sexo=tolower(auxChofer.sexo);
			while(auxChofer.sexo !='f' && auxChofer.sexo !='m')
            {
                printf("Error. Ingrese su sexo valido (f-m): \n");
			fflush(stdin);
			scanf("%c",&auxChofer.sexo);
			auxChofer.sexo=tolower(auxChofer.sexo);

            }

            auxChofer.isEmpty=0;

            choferes[indice] = auxChofer;

            todoOk = 1;
        }
    }
    return todoOk;
}
