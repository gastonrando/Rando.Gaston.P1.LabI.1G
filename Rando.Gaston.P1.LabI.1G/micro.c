#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "micro.h"
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"
#include "destino.h"
#include "viaje.h"




char menu()
{

    char opcion;
    system("cls");
    printf("     *** ABM Micros ***\n");
    printf(" A- ALTA MICRO\n");
    printf(" B- MODIFICAR MICRO\n");
    printf(" C- BAJA MICRO\n");
    printf(" D- LISTAR MICRO\n");
    printf(" E- LISTAR EMPRESAS\n");
    printf(" F- LISTAR TIPOS\n");
    printf(" G- LISTAR DESTINOS\n");
    printf(" H- ALTA VIAJE\n");
    printf(" I- LISTAR VIAJES\n");
    printf(" J- INFORMES\n");
    printf(" K- SALIR\n");
    printf(" Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);

    return opcion;
}

void mostrarMicro(eMicro unMicro, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                  eChofer choferes[], int tamC)
{
    char descTipos[20];
    char desEmpresas[20];
    char desChofer[20];


    if (cargarDescripcionTipos( tipos, tamTip, unMicro.idTipo, descTipos) == 1 &&
            cargarDescripcionEmpresas(empresas, tamEmp, unMicro.idEmpresa, desEmpresas) == 1 &&
            cargarDescripcionChofer(choferes, tamC, unMicro.idChofer, desChofer)==1)
    {
        printf(" %d     %-10s     %-10s  %d         %-10s  \n",
               unMicro.id,
               desEmpresas,
               descTipos,
               unMicro.capacidad,
               desChofer
              );
    }

}

int mostrarMicros(eMicro listaMicros[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                  eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int flag = 1;
    if (listaMicros != NULL && tam > 0 && tipos != NULL && tamTip > 0 && empresas != NULL && tamEmp > 0 )
    {
        system("cls");
        printf("                     ***Lista de Micros  ***\n");
        printf("------------------------------------------------------------\n");
        printf(" ID        Empresa      Tipo     Capacidad      Chofer     \n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!listaMicros[i].isEmpty)
            {
                mostrarMicro(listaMicros[i], tipos, tamTip, empresas, tamEmp, choferes, tamC);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay micros para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}


int inicializarMicros(eMicro listaMicros[], int tamMic)
{

    int todoOk = 0;
    if (listaMicros != NULL && tamMic > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tamMic; i++)
        {
            listaMicros[i].isEmpty = 1;
        }
    }
    return todoOk;

}

int buscarLibre(eMicro listaMicros[], int tamMic)
{
    int indice = -1;
    for (int i = 0; i < tamMic; i++)
    {
        if (listaMicros[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaMicro(eMicro listaMicros[], int tamMic, eEmpresa empresas[], int tamEmp, eTipo tipos[], int tamTip,
              eChofer choferes[], int tamC,int* pIdChoferes, int* pIdMicros)
{
    int todoOk = 0;
    int indiceMicro;
    int nextIdChofer;
    eMicro auxMicro;

    if (listaMicros != NULL && tamMic > 0 && empresas != NULL && tamEmp > 0  &&
            tipos != NULL && tamTip > 0 )
    {
        system("cls");
        printf("  ***Alta Micros*** \n\n");
        indiceMicro = buscarLibre(listaMicros, tamMic);

        if (indiceMicro == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxMicro.id = *pIdMicros;
            (*pIdMicros)++;

            auxMicro.idChofer= *pIdChoferes;
            nextIdChofer=*pIdChoferes;
            altaChoferes(choferes, tamC, &nextIdChofer);
            (*pIdChoferes)++;


            mostrarEmpresas(empresas, tamEmp);
            printf("Ingrese id de la empresa: ");
            scanf("%d", &auxMicro.idEmpresa);

            while ( !validarIdEmpresa(auxMicro.idEmpresa, empresas, tamEmp) )
            {
                printf("Error, ingrese id de la empresa valido: ");
                scanf("%d", &auxMicro.idEmpresa);
            }

            mostrarTipos(tipos, tamTip);
            printf("Ingrese id del Tipo de micro: ");
            scanf("%d", &auxMicro.idTipo);

            while ( !validarIdTipos(auxMicro.idTipo, tipos, tamTip) )
            {
                printf("Error, ingrese id del Tipo de micro valido: ");
                scanf("%d", &auxMicro.idTipo);
            }

            printf("Ingrese la capacidad del micro (1-50): ");
            scanf("%d", &auxMicro.capacidad);
            while(auxMicro.capacidad < 1 || auxMicro.capacidad > 50 )
            {
                printf("Invalido! Ingrese la capacidad del micro (1-50): ");
                scanf("%d", &auxMicro.capacidad);
            }

            auxMicro.isEmpty = 0;

            listaMicros[indiceMicro] = auxMicro;

            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarMicrosId(eMicro listaMicros[], int tam, int Id)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (listaMicros[i].id == Id && listaMicros[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarMicro(eMicro listaMicro[], int tamMic, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                   eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    eMicro auxMicro;
    if (listaMicro != NULL && tamMic > 0 && empresas != NULL && tamEmp > 0  &&
            tipos != NULL && tamTip > 0)
    {
        system("cls");
        printf("   *** Modificar Micro *** \n\n");


        mostrarMicros(listaMicro, tamMic, tipos, tamTip, empresas, tamEmp, choferes, tamC);
        printf("\nIngrese id: ");
        scanf("%d", &id);

        indice = buscarMicrosId(listaMicro, tamMic, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch ( menuModificar(listaMicro,tamMic, indice, tipos, tamTip, empresas, tamEmp, choferes, tamC))
                {
                case 1:
                    mostrarTipos(tipos, tamTip);
                    printf("Modificar id tipos: ");
                    scanf("%d", &auxMicro.idTipo);
                    while ( !validarIdTipos(auxMicro.idTipo, tipos, tamTip) )
                    {
                        printf("Error, ingrese id del Tipo de micro valido: ");
                        scanf("%d", &auxMicro.idTipo);
                    }


                    printf("Confirma cambio de id tipo? (S/N)\n");


                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        listaMicro[indice].idTipo= auxMicro.idTipo;
                    }
                    else
                    {
                        printf("Edicion cancelada\n");
                    }
                    break;
                case 2:
                    printf("Modificar capacidad: ");
                    printf("Ingrese la capacidad del micro (1-50): ");
                    scanf("%d", &auxMicro.capacidad);
                    while(auxMicro.capacidad < 1 || auxMicro.capacidad > 50)
                    {
                        printf("Invalido! Ingrese la capacidad del micro (1-50): ");
                        scanf("%d", &auxMicro.capacidad);
                    }
                    printf("Confirma cambio de capacidad? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        listaMicro[indice].capacidad = auxMicro.capacidad;
                    }
                    else
                    {
                        printf("Edicion cancelada\n");
                    }
                    break;

                case 3:
                    printf("Esta seguro que quiere salir? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = toupper(salir);
                    if (salir == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                }
                //system("pause");
            }
            while(seguir == 's');

            todoOk = 1;
        }
    }
    return todoOk;
}

int menuModificar(eMicro listaMicro[], int tamMic, int indice, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                  eChofer choferes[], int tamC)
{
    int opcion = 0;
    system("cls");
    printf("     *** Modificar Tipos ***\n\n");
    mostrarMicro(listaMicro[indice],tipos, tamTip,empresas,tamEmp, choferes, tamC);
    printf("\n1- Editar tipo\n");
    printf("2- Editar Capacidad\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}



int bajaMicro(eMicro listaMicros[], int tamMic, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
              eChofer choferes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if (listaMicros != NULL && tamMic > 0)
    {
        system("cls");
        printf("   *** Baja Micro *** \n\n");
        mostrarMicros(listaMicros,tamMic,tipos,tamTip, empresas, tamEmp, choferes, tamC);
        printf("\nIngrese id: ");
        scanf("%d", &id);

        indice = buscarMicrosId(listaMicros, tamMic, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarMicro(listaMicros[indice],tipos, tamTip,empresas,tamEmp, choferes, tamC);
            printf("Confirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma=tolower(confirma);
            if (confirma == 's')
            {
                listaMicros[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario.\n");
            }
        }
    }
    return todoOk;
}

int ordenarMicro(eMicro lista[], int tam, eEmpresa empresas[], int tamEmp)
{
    int todoOk = 0;
    char desEmpresasI [20];
    char desEmpresasJ [20];

    eMicro auxMicro;
    if (lista != NULL && tam > 0)
    {

        for (int i = 0; i < tam -1; i++)
        {

            for (int j = i+1; j < tam; j++)
            {
                cargarDescripcionEmpresas(empresas, tamEmp, lista[i].idEmpresa, desEmpresasI );
                cargarDescripcionEmpresas(empresas, tamEmp, lista[j].idEmpresa, desEmpresasJ );

                if ( strcmp(desEmpresasI, desEmpresasJ) > 0 ||
                        (strcmp(desEmpresasI, desEmpresasJ) == 0 && lista[i].capacidad > lista[j].capacidad))
                {
                    auxMicro = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMicro;
                }
            }
        }
        todoOk = 1;

    }

    return todoOk;
}

int mostrarMicrosTipo(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                      eChofer choferes [], int tamC)
{
// limpiar pantalla
// mostrar subitulo del informe
// muestra localidades
// pide y valida id localidad


    int todoOk = 0;
    int idTipo;

    if (lista != NULL && tam > 0 && tipos !=NULL && tamTip)
    {
        system("cls");
        printf("                     ***Micros de un Tipo  ***\n\n");
        mostrarTipos(tipos,tamTip);
        printf("Ingrese id de Tipo de micro: ");
        scanf("%d", &idTipo);

        while ( !validarIdTipos(idTipo, tipos, tamTip) )
        {
            printf("Error, ingrese id de Tipo de micro valido: ");
            scanf("%d", &idTipo);
        }
        mostrarMicrosIdTipos(idTipo, lista, tam, tipos, tamTip,empresas, tamC, choferes, tamC);

        todoOk = 1;
    }
    return todoOk;

}

int mostrarMicrosIdTipos(int idTipos, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                         int tamEmp, eChofer choferes[], int tamC)
{
    // muesta los micros con ese tipo

    int todoOk = 0;
    int flag = 1;
    char descTipo[20];

    if (lista != NULL && tam > 0 && tipos !=NULL && tamTip > 0)
    {


        while ( !validarIdTipos(idTipos, tipos, tamTip) )
        {
            printf("Error, ingrese id de tipo valido: ");
            scanf("%d", &idTipos);
        }


        printf("------------------------------------------------------------\n");
        printf(" ID       Empresa       Tipo    Capacidad      Chofer\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idTipo == idTipos )
            {
                mostrarMicro(lista[i], tipos, tamTip, empresas, tamEmp, choferes, tamC);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionTipos(tipos,tamTip,idTipos,descTipo);
            printf("No hay micros en %s.\n", descTipo);

        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosEmpresa(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                         eChofer choferes [], int tamC)
{
// limpiar pantalla
// mostrar subitulo del informe
// muestra localidades
// pide y valida id localidad


    int todoOk = 0;
    int idEmpresa;

    if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp)
    {
        system("cls");
        printf("                     ***Micros de un Empresa  ***\n\n");
        mostrarEmpresas(empresas,tamTip);
        printf("Ingrese id de Empresa de micro: ");
        scanf("%d", &idEmpresa);

        while ( !validarIdEmpresa(idEmpresa, empresas, tamEmp) )
        {
            printf("Error, ingrese id de Empresa de micro valido: ");
            scanf("%d", &idEmpresa);
        }
        mostrarMicrosIdEmpresas(idEmpresa, lista, tam, tipos, tamTip,empresas, tamC, choferes, tamC);

        todoOk = 1;
    }
    return todoOk;

}

int mostrarMicrosIdEmpresas(int idEmpresa, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                            int tamEmp, eChofer choferes[], int tamC)
{
    // muesta los micros con ese tipo

    int todoOk = 0;
    int flag = 1;
    char descEmpresa[20];

    if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp > 0)
    {


        while ( !validarIdEmpresa(idEmpresa, empresas, tamEmp) )
        {
            printf("Error, ingrese id de Empresa valido: ");
            scanf("%d", &idEmpresa);
        }


        printf("------------------------------------------------------------\n");
        printf(" ID       Empresa       Tipo    Capacidad      Chofer\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idEmpresa ==idEmpresa )
            {
                mostrarMicro(lista[i], tipos, tamTip, empresas, tamEmp, choferes, tamC);
                flag = 0;
            }
        }
        if (flag)
        {
            cargarDescripcionEmpresas(empresas,tamEmp,idEmpresa,descEmpresa);
            printf("No hay micros en %s.\n", descEmpresa);

        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMicrosAllEmpresa(eMicro micros[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                            eChofer choferes[], int tamC)
{

    int todoOk = 0;


    if (micros != NULL && tam > 0 && tipos !=NULL && tamTip)
    {
        system("cls");
        printf("                     ***Micros por Empresa***\n\n");

        for (int i = 0; i < tamEmp; i++)
        {
            printf("Empresas: %s \n", empresas[i].descripcion );
            mostrarMicrosIdEmpresas(empresas[i].id, micros, tam, tipos, tamTip,empresas, tamEmp, choferes, tamC );
            printf("\n");
        }

        todoOk = 1;
    }

    return todoOk;

}

//elegir empresa y tipo y ver cuanto hay de ese tipo

int informeMicroEmpresasVIP  (eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                              int tamEmp, eChofer choferes[], int tamC)
{

    int todoOk = 0;
    //int auxContadorEmpresa = 0;
    int auxContadorTipo[tamEmp] ;
    //int opcionEmpresa;
    int opcionTipo = 5003;
    int flagCoincidencia;

    for(int i=1; i<tamEmp; i++)
    {

        auxContadorTipo[i] = 0;
    }

    if (empresas != NULL && tam > 0 )
    {

        if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp>0)
        {
            system("cls");
            printf("                  ***Cantidad de Micros de tipo VIP por empresa***\n\n");

            for (int i = 0; i < tamEmp; i++)
            {

                for (int j=0; j<tam; j++)
                {
                    flagCoincidencia=0;

                    if( (!lista[j].isEmpty && lista[j].idEmpresa == empresas[i].id) &&
                            (!lista[j].isEmpty  && opcionTipo== lista[j].idTipo))
                    {
                        auxContadorTipo[i]++;
                        flagCoincidencia=1;
                    }

                }

            }
            for (int i=0; i< tamEmp; i++)
            {
                if(auxContadorTipo[i] >0 )
                {
                    printf("\n\n---------------------------------------------- \n");
                    printf("Empresa: %s \n", empresas[i].descripcion);
                    printf("Cantidad de Micros VIP: %d \n\n",auxContadorTipo[i]);
                    printf("---------------------------------------------- \n");
                }
            }
        }

        todoOk = 1;
    }

    return todoOk;


}

int empresaMenorCantMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamEmp)  //uso vectores paralelos
{

    int todoOk = 0;
    float auxContador[tamEmp];
    int menor;

    for(int i=1; i<tamEmp; i++)
    {

        auxContador[i] = 0;
    }

    if (empresas != NULL && tam > 0 )
    {

        if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp)
        {
            system("cls");
            printf("\n                   *** Empresa con menor cantidad de micros ***\n\n");

            for (int i = 0; i < tamEmp; i++)
            {

                for (int j=0; j<tam; j++)
                {
                    if(!lista[j].isEmpty && lista[j].idEmpresa == empresas[i].id)


                        auxContador[i]++;
                }
            }

        }

        for (int i=0; i<tamEmp; i++)
        {
            if( i==0 || auxContador[i]<menor)
            {
                menor=auxContador[i];
            }
        }
        printf("Empresa con menor cantidad de micros es: \n\n");
        for (int i=0; i<tamEmp; i++)
        {
            if(auxContador[i]== menor)
            {

                printf("%s con %d \n", empresas[i].descripcion, menor);

            }
        }


        todoOk = 1;
    }

    return todoOk;

}


int empresaMayorCapacidad(eMicro lista[], int tam, eEmpresa empresas[], int tamEmp)  //uso vectores paralelos
{

    int todoOk = 0;
    float auxAcuCap[tamEmp];
    int mayor;

    for(int i=1; i<tamEmp; i++)
    {

        auxAcuCap[i] = 0;
    }

    if (empresas != NULL && tam > 0 )
    {

        if (lista != NULL && tam > 0 && empresas !=NULL && tamEmp)
        {
            system("cls");
            printf("\n                     *** Empresas con Mayor Capacidad ***\n\n");

            for (int i = 0; i < tamEmp; i++)
            {

                for (int j=0; j<tam; j++)
                {
                    if(!lista[j].isEmpty && lista[j].idEmpresa == empresas[i].id)


                        auxAcuCap[i]+=lista[j].capacidad;
                }
            }

        }

        for (int i=0; i<tamEmp; i++)
        {
            if( i==0 || auxAcuCap[i]>mayor)
            {
                mayor=auxAcuCap[i];
            }
        }
        printf("Empresa con mayor capacidad: \n\n");
        for (int i=0; i<tamEmp; i++)
        {
            if(auxAcuCap[i]== mayor)
            {

                printf("%s\n", empresas[i].descripcion);

            }
        }


        todoOk = 1;
    }

    return todoOk;

}

