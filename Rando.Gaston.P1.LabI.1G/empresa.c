#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

int cargarDescripcionEmpresas( eEmpresa empresas[], int tamEmp,int idEmp, char descripcion[] )
{
    int todoOk = 0;
    int flag = 1;
    if (empresas != NULL && tamEmp > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tamEmp; i++)
        {
            if (empresas[i].id == idEmp)
            {
                strcpy(descripcion, empresas[i].descripcion);
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


int mostrarEmpresas( eEmpresa empresas[], int tam )
{
    int todoOk = 0;
    if (empresas != NULL && tam > 0 )
    {
        printf("      *** Empresas *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", empresas[i].id, empresas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}


int validarIdEmpresa( int id, eEmpresa empresas[], int tam )
{
    int esValido = 0;
    if (empresas != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == empresas[i].id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

