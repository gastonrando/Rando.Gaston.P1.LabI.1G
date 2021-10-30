#include <string.h>
#include "dataHarcodeo.h"
#include "micro.h"
#include "tipo.h"
#include "empresa.h"
#include "destino.h"
#include "fecha.h"

int idEmpresa [10] ={1000, 1001, 1000, 1003, 1003, 1002, 1001, 1002, 1000, 1002};

int tipos [10] = {5002, 5001, 5000, 5003, 5000, 5002, 5002, 5002, 5000, 5001};

int capacidad [10] = {50, 40, 30, 45, 50, 35, 45, 50, 40, 20};

int harcodearMicros(eMicro micros[], int tamMic, int cantidadACargar, int* pIdMicros)
{
    int contador=-1;

    if(micros!=NULL && tamMic>0 && cantidadACargar>=0 && cantidadACargar<=tamMic && pIdMicros!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            micros[i].id= *pIdMicros;
            (*pIdMicros)++;
            micros[i].capacidad= capacidad[i];
            micros[i].idTipo=tipos[i];
            micros[i].idEmpresa=idEmpresa[i];
            micros[i].isEmpty=0;
            contador++;
        }

    }
    return contador;
}

int micros[15]={100,101,105,103,104,108,109,106,105,107,102,103,102,109,109};

int idsDestinos[15]={20001,20002,20001,20000,20003,20003,20001,20000,20002,20003,20003,20001,20002,20000,20000};

eFecha fechas[15]={{27,12,1991},
                   {26,06,1996},
                   {22,02,2000},
                   {30,11,2001},
                   {03,12,2001},
                   {31,05,2000},
                   {12,10,1997},
                   {01,01,2003},
                   {10,01,2001},
                   {07,01,1995},
                   {13,01,1970},
                   {16,10,1964},
                   {27,03,1984},
                   {19,12,1976},
                   {20,8,2007}
                   };

int hardcodearViajes(eViaje viajes[], int tamV, int cantidad, int* id)
{
    int contador=-1;

	if(viajes!=NULL && tamV>0 && cantidad>=0 && cantidad<=tamV && id!=NULL)
	{
		contador=0;
		for(int i=0; i<cantidad; i++)
		{
			viajes[i].id = *id;
			(*id)++;
            viajes[i].idMicro = micros[i];
			viajes[i].idDestino= idsDestinos[i];
			viajes[i].fecha = fechas[i];
			viajes[i].isEmpty=0;
			contador++;
		}
	}
	return contador;
}

char sexo[11] = {'f','m','f','f','m','m','f','m','f','m'};

char nombres[11][20] = {"Maria", "Steeph", "Gaston", "Sebastian", "Luz", "Lucia", "Nahue", "Bianca", "Lucas", "Gabi"};


int hardcodearChoferes(eMicro micros[], int tamMic, eChofer choferes[], int tamC, int cant, int* pIdChofer)
{
    int contador=-1;
    if(choferes!=NULL && tamC>0 && pIdChofer!=NULL && cant>=0 && cant <=tamC)
    {

        for(int i=0; i < cant; i++)
        {

            choferes[i].id = *pIdChofer;
            micros[i].idChofer= choferes[i].id ;
            (*pIdChofer)++;
            strcpy(choferes[i].nombre, nombres[i]);
            choferes[i].sexo = sexo[i];
            choferes[i].isEmpty=0;
            contador++;

        }
    }
    return contador;
}



