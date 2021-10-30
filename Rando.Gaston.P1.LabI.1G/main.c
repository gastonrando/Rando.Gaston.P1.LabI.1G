#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "destino.h"
#include "empresa.h"
#include "micro.h"
#include "tipo.h"
#include "viaje.h"
#include "dataHarcodeo.h"
#include "chofer.h"
#include "informes.h"


#define TAM_MIC 100
#define TAM_EMP 4
#define TAM_TIP 4
#define TAM_DES 4
#define TAM_V 200
#define TAM_C 100

int main()
{

    eEmpresa empresas[TAM_EMP]=
    {
        {1000, "Plusmar"},
        {1001, "Flecha Bus"},
        {1002, "Tas"},
        {1003, "El Rapido"}
    };

    eTipo tipos[TAM_TIP] =
    {
        {5000, "Comun"},
        {5001, "CocheCama"},
        {5002, "Doble"},
        {5003, "VIP"},
    };

    eDestino destinos[TAM_DES] =
    {
        {20000, "Calafate", 22250},
        {20001, "Bariloche", 103000},
        {20002, "Iguazu", 84400,},
        {20003, "Mendoza", 95600}
    };

    char seguir = 's';
    char salir;
    int nextIdMicros = 100;
    int nextIdViajes = 30000;
    int nextIdChofer = 50000;

    //si se retira el hardcodeo se deben de pasar las banderas flagmicro y flagviaje a 0
    int flagMicro = 5;
    int flagViaje = 5;
    char seguirInformes = 's';
    char salirInfromes;


    eMicro listaMicros[TAM_MIC];
    eViaje viajes[TAM_V];
    eChofer choferes[TAM_C];

    if ( !inicializarMicros(listaMicros, TAM_MIC) )
    {
        printf("Error al iniciar lista\n");
    }

    if ( !inicializarViajes(viajes, TAM_V))
    {
        printf("Error al iniciar Viajes\n");
    }
    if ( !inicializarChoferes(choferes, TAM_C))
    {
        printf("Error al iniciar Chofer\n");
    }

    harcodearMicros(listaMicros, TAM_MIC, 10, &nextIdMicros);
    hardcodearViajes(viajes, TAM_V, 12, &nextIdViajes);
    hardcodearChoferes(listaMicros, TAM_MIC, choferes, TAM_C,10, &nextIdChofer);

    do
    {
        switch(menu())
        {

        case 'a':
            if(!altaMicro(listaMicros, TAM_MIC, empresas, TAM_EMP, tipos, TAM_TIP, choferes, TAM_C,&nextIdChofer, &nextIdMicros))
            {
                printf("No se pudo realizar el alta\n");

            }
            else
            {
                printf("Alta exitosa\n");
                flagMicro++;
            }


            break;
        case 'b':
            if(flagMicro !=0 )
            {
                if(!modificarMicro(listaMicros, TAM_MIC, tipos, TAM_TIP, empresas, TAM_EMP, choferes, TAM_C))
                {
                    printf("No se pudo modificar\n");
                }
                else
                {
                    printf("Cambios realizados con exito\n");
                }
            }
            else
            {

                printf("\nDebe de realizar un alta primero\n\n");
            }

            break;
        case 'c':
            if(flagMicro !=0 )
            {
                if(!bajaMicro(listaMicros, TAM_MIC, tipos, TAM_TIP, empresas, TAM_EMP, choferes, TAM_C))
                {
                    printf("No se pudo realizar la baja\n");
                }
                else
                {
                    printf("Baja exitosa\n");
                    flagMicro--;
                }
            }
            else
            {

                printf("\nDebe de realizar un alta primero\n\n");
            }
            break;

        case 'd':
            if(flagMicro !=0 )
            {
                if ( !ordenarMicro(listaMicros, TAM_MIC, empresas,TAM_EMP) )
                {
                    printf("No se pudo ordenar\n");
                }
                else
                {
                    mostrarMicros(listaMicros, TAM_MIC, tipos, TAM_TIP, empresas, TAM_EMP, choferes, TAM_C);
                }
            }
            else
            {

                printf("\nDebe de realizar un alta primero\n\n");
            }



            break;
        case 'e':
            mostrarEmpresas(empresas, TAM_EMP);
            break;
        case 'f':
            mostrarTipos(tipos, TAM_TIP);
            break;
        case 'g':
            mostrarDestinos( destinos, TAM_DES);
            break;
        case 'h':
            if(flagMicro !=0 )
            {
                if(!altaViajes(viajes,TAM_V,listaMicros, TAM_MIC, empresas, TAM_EMP, tipos, TAM_TIP, destinos, TAM_DES, choferes, TAM_C, &nextIdViajes))
                {
                    printf("No se pudo realizar el alta\n");
                }
                else
                {
                    printf("Alta exitosa\n");
                    flagViaje++;
                }
            }
            else
            {

                printf("\nDebe de realizar un alta de micro primero\n\n");
            }

            break;
        case 'i':
            if(flagViaje !=0 )
            {
                mostrarViajes(viajes, TAM_V, listaMicros, TAM_MIC, destinos, TAM_DES, empresas, TAM_DES, tipos, TAM_TIP);
            }
            else
            {

                printf("\nDebe de realizar un alta de viaje primero\n\n");
            }
            break;
        case 'j':
            if(flagMicro!=0 && flagViaje!=0){
                do
                {
                    switch(menuInformes())
                    {
                    case 1:
                        system("cls");
                        if ( !mostrarMicrosEmpresa(listaMicros, TAM_MIC, tipos, TAM_TIP,empresas, TAM_EMP,choferes, TAM_C) )
                        {
                            printf("No se pudieron mostrar micros por tipo\n");
                        }

                        break;
                    case 2:
                        system("cls");
                        if ( !mostrarMicrosTipo(listaMicros, TAM_MIC, tipos, TAM_TIP,empresas, TAM_EMP,choferes, TAM_C) )
                        {
                            printf("No se pudieron mostrar micros por tipo\n");
                        }

                        break;
                    case 3:
                        system("cls");
                        if ( !informeMicroEmpresasVIP(listaMicros, TAM_MIC, tipos, TAM_TIP,empresas, TAM_EMP,choferes, TAM_C) )
                        {
                            printf("No se pudieron mostrar micros por tipo\n");
                        }

                        break;

                    case 4:
                        system("cls");
                        if ( !mostrarMicrosAllEmpresa(listaMicros, TAM_MIC, tipos, TAM_TIP,empresas, TAM_EMP,choferes, TAM_C) )
                        {
                            printf("No se pudieron mostrar micros por tipo\n");
                        }

                        break;
                    case 5:
                        system("cls");
                        if ( !empresaMayorCapacidad(listaMicros, TAM_MIC, empresas, TAM_EMP))
                        {
                            printf("No se pudo mostrar la empresa con mayor capacidad\n");
                        }


                        break;
                    case 6:
                        system("cls");
                        if ( !empresaMenorCantMicros(listaMicros, TAM_MIC, empresas, TAM_EMP))
                        {
                            printf("No se pudo mostrar las empresas con menor cantidad de micros\n");
                        }


                        break;
                    case 7:
                        system("cls");
                        if ( !mostrarViajesMicro(listaMicros, TAM_MIC, tipos, TAM_TIP, empresas, TAM_EMP, choferes, TAM_C, destinos, TAM_DES, viajes, TAM_V))
                        {
                            printf("No se pudieron mostrar los viajes del micro\n");
                        }
                        break;
                    case 8:
                        system("cls");
                        if ( !microSumaViajes(listaMicros, TAM_MIC,tipos, TAM_TIP, empresas, TAM_EMP, choferes, TAM_C, destinos, TAM_DES, viajes, TAM_V))
                        {
                            printf("No se pudieron mostrar los viajes del micro\n");
                        }
                        break;



                    case 9:
                        printf("Esta seguro que quiere salir? (S/N)\n");
                        fflush(stdin);
                        scanf("%c", &salirInfromes);
                        salirInfromes = toupper(salirInfromes);
                        if (salirInfromes == 'S')
                        {
                            seguirInformes = 'n';
                        }
                        else
                        {
                            break;
                        }
                        break;

                    default:
                        printf("Opcion invalida\n");
                        break;
                    }
                    system("pause");

                }
                while(seguirInformes == 's');
            }else{
            printf("debe de ingresar las altas");
        }

              break;
        case 'k':
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
        system("pause");

    }
    while(seguir == 's');

    return 0;
}
