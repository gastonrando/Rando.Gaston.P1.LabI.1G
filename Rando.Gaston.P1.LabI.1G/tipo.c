#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipos( eTipo tipos[], int tamTip,int idTipo, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (tipos != NULL && tamTip > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamTip; i++)
        {
            if (tipos[i].id == idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
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


int mostrarTipos( eTipo tipos[], int tam )
{
    int todoOk = 0;
    if (tipos != NULL && tam > 0 )
    {
        printf("      *** Tipos *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int validarIdTipos( int id, eTipo tipos[], int tam )
{
    int esValido = 0;
    if (tipos != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == tipos[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
