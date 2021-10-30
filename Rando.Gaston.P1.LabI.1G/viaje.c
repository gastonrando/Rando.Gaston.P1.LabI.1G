#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "viaje.h"
#include "destino.h"
#include "micro.h"
#include "chofer.h"

int inicializarViajes(eViaje viajes[], int tam)
{

    int todoOk = 0;
    if (viajes != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            viajes[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreViajes(eViaje viajes[], int tam)
{
    int indice = -1;
    if(viajes != NULL && tam > 0)
    {

        for (int i = 0; i < tam; i++)
        {
            if (viajes[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaViajes(eViaje viajes[], int tamV, eMicro micros[], int tamMic, eEmpresa empresas[], int tamEmp, eTipo tipos[], int tamTip,
               eDestino destinos[], int tamDes, eChofer choferes[], int tamC, int* pIdViajes)
{
    int todoOk = 0;
    int indice;

    eViaje auxViajes;

    if (viajes != NULL && tamV > 0 && micros != NULL && tamMic > 0 && pIdViajes != NULL && empresas != NULL && tamEmp > 0 && tipos != NULL && tamTip > 0 &&
            destinos != NULL && tamDes > 0)
    {

        system("cls");
        printf("  ***Alta Viajes*** \n\n");
        indice = buscarLibreViajes(viajes, tamV);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxViajes.id = *pIdViajes;
            (*pIdViajes)++;


            mostrarMicros(micros, tamMic, tipos, tamTip, empresas, tamEmp, choferes, tamC);
            printf("Ingrese id del micro: ");
            scanf("%d", &auxViajes.idMicro);
            while (buscarMicrosId(micros, tamMic, auxViajes.idMicro) == -1)
            {
                printf("Error. Ingrese id del micro: ");
                scanf("%d", &auxViajes.idMicro);
            }

            mostrarDestinos(destinos, tamDes);
            printf("Ingrese id del destino: ");
            scanf("%d", &auxViajes.idDestino);

            while ( !validarIdDestino(auxViajes.idDestino, destinos, tamDes))
            {
                printf("Error, ingrese id de comida valido: ");
                scanf("%d", &auxViajes.idDestino);
            }

            printf("Ingrese fecha: ");
            scanf("%d/%d/%d", &auxViajes.fecha.dia, &auxViajes.fecha.mes, &auxViajes.fecha.anio );

            auxViajes.isEmpty=0;

            viajes[indice] = auxViajes;

            todoOk = 1;
        }
    }
    return todoOk;
}



void mostrarViaje(eViaje unViaje, eMicro micros[], int tamM, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    char descEmpresa[20];
    char descTipo[20];
    char descDestino[20];
    int indice;
    float precio;

    indice= buscarMicrosId(micros, tamM, unViaje.idMicro);

    if (cargarDescripcionDestino(destinos, tamD, unViaje.idDestino, descDestino) ==1 &&
            cargarDescripcionEmpresas(empresas, tamE,  micros[indice].idEmpresa, descEmpresa)== 1 &&
            cargarDescripcionTipos(tipos, tamT,  micros[indice].idTipo, descTipo)== 1 &&
            cargarPrecio(destinos, tamD, unViaje.idDestino, &precio) == 1)
    {

        printf(" %d     %d      %8s      %-10s       %-10s       %10.2f     %002d/%002d/%d\n",
               unViaje.id,
               unViaje.idMicro,
               descTipo,
               descEmpresa,
               descDestino,
               precio,
               unViaje.fecha.dia,
               unViaje.fecha.mes,
               unViaje.fecha.anio

              );
    }

}


int mostrarViajes(eViaje viajes[], int tamV, eMicro micros[], int tamM, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if (viajes != NULL && tamV > 0 && micros != NULL && tamM > 0 && empresas != NULL && tamE > 0 &&
            destinos != NULL && tamD > 0 && tipos != NULL && tamT >0)
    {

        //system("cls");
        printf("                     ***Lista de Viajes  ***\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf(" ID        Micro        Tipo        Empresa         Destino             Precio      Fecha\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < tamV; i++)
        {

            if (!viajes[i].isEmpty)
            {
                mostrarViaje(viajes[i], micros, tamM, destinos, tamD, empresas, tamE, tipos, tamT);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay Viajes para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

//mostrar viajes del micro

int mostrarViajesMicro(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                       eChofer choferes [], int tamC, eDestino destinos[], int tamDes,
                       eViaje viajes[], int tamV)
{
// limpiar pantalla
// mostrar subitulo del informe
// muestra localidades
// pide y valida id localidad


    int todoOk = 0;
    int idMicro;
    int flag = 1;
    int indice;

    if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp)
    {
        system("cls");
        printf("                     ***Viajes del Micro  ***\n\n");
        mostrarMicros(lista, tam, tipos, tamTip, empresas, tamEmp, choferes, tamC);
        printf("Ingrese id del micro del cual quiere ver viajes realizados: ");
        scanf("%d", &idMicro);

        while ( buscarMicrosId(lista, tam, idMicro) ==-1 )
        {
            printf("Error, Ingrese id del micro del cual quiere ver viajes realizados: ");
            scanf("%d", &idMicro);
        }

        mostrarViajesIdMicros(idMicro, lista, tam, tipos, tamTip, empresas, tamEmp, choferes, tamC, destinos, tamDes, viajes, tamV);

        todoOk = 1;
    }
    return todoOk;

}

int mostrarViajesIdMicros(int idMicro, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                          int tamEmp, eChofer choferes[], int tamC, eDestino destinos[], int tamDes,
                          eViaje viajes[], int tamV)
{
    // muesta los micros con ese tipo

    int todoOk = 0;
    int flag = 1;
    char descEmpresa[20];

    if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp > 0)
    {


        /*while ( busca(idEmpresa, empresas, tamEmp) )
        {
            printf("Error, ingrese id de Empresa valido: ");
            scanf("%d", &idEmpresa);
        }*/


        printf("----------------------------------------------------------------------------------------------------------\n");
        printf(" ID        Micro        Tipo        Empresa         Destino             Precio      Fecha\n");
        printf("----------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < tamV; i++)
        {
            if (!viajes[i].isEmpty && viajes[i].idMicro == idMicro)
            {
                mostrarViaje(viajes[i],lista,tam, destinos, tamDes, empresas, tamEmp, tipos, tamTip);   // (lista[i], tipos, tamTip, empresas, tamEmp, clientes, tamC;
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay viajes en %d.\n", idMicro);

        }
        todoOk = 1;
    }
    return todoOk;
}

//pedir micro y que se sumen los importes de los viajes

int microSumaViajes(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                    eChofer choferes [], int tamC, eDestino destinos[], int tamDes,
                    eViaje viajes[], int tamV)
{
// limpiar pantalla
// mostrar subitulo del informe
// muestra localidades
// pide y valida id localidad


    int todoOk = 0;
    int idMicro;
    int flag = 1;
    int indice;

    if (lista != NULL && tam > 0 && viajes !=NULL && tamV)
    {
        system("cls");
        printf("                     ***Viajes del Micro  ***\n\n");
        mostrarMicros(lista, tam, tipos, tamTip, empresas, tamEmp, choferes, tamC);
        printf("Ingrese id del micro del cual quiere ver suma de precios por viajes realizados: ");
        scanf("%d", &idMicro);

        while ( buscarMicrosId(lista, tam, idMicro) ==-1 )
        {
            printf("Error, Ingrese id del micro del cual quiere ver suma de precios por viajes realizados: ");
            scanf("%d", &idMicro);
        }

        mostrarSumaViajesMicro(idMicro, lista, tam, tipos, tamTip, empresas, tamEmp, choferes, tamC, destinos, tamDes, viajes, tamV);

        todoOk = 1;
    }
    return todoOk;

}

int mostrarSumaViajesMicro(int idMicro, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                           int tamEmp, eChofer choferes[], int tamC, eDestino destinos[], int tamDes,
                           eViaje viajes[], int tamV)
{
    // muesta los micros con ese tipo

    int todoOk = 0;
    int flag = 1;
    char descEmpresa[20];
    int idDestinos;
    float acumuladorPrecio =0;

    if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp > 0)
    {

        for (int i = 0; i < tamV; i++)
        {
            if (!viajes[i].isEmpty && viajes[i].idMicro == idMicro)
            {
                for(int j =0; j< tamDes; j++)
                {
                    if(destinos[j].id == viajes[i].idDestino )
                    {
                        acumuladorPrecio+= destinos[j].precio;
                        flag = 0;
                    }
                }
            }
        }
        if (flag)
        {
            printf("salio mal en %d.\n", idMicro);

        }
        else
        {
            printf("Precio total del micro elegido: %.2f \n", acumuladorPrecio);
        }
        todoOk = 1;
    }
    return todoOk;
}


