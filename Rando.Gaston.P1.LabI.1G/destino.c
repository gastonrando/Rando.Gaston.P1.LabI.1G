#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int cargarDescripcionDestino( eDestino destinos[], int tamDes,int idDes, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (destinos != NULL && tamDes > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamDes; i++)
        {
            if (destinos[i].id == idDes)
            {
                strcpy(descripcion, destinos[i].descripcion);
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

int cargarPrecio( eDestino destinos[], int tamDes,int idDes, float* pPrecio)
{
    int todoOk = 0;
    int flag = 1;
    if (destinos != NULL && tamDes > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamDes; i++)
        {
            if (destinos[i].id == idDes)
            {

                *pPrecio=destinos[i].precio;
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


int mostrarDestinos( eDestino destinos[], int tam )
{
    int todoOk = 0;
    if (destinos != NULL && tam > 0 )
    {
        printf("      *** Destinos *** \n\n");
        printf("  Id         Descripcion             Precio\n\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s         %10.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}



int validarIdDestino( int id, eDestino destinos[], int tam )
{
    int esValido = 0;
    if (destinos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == destinos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}


