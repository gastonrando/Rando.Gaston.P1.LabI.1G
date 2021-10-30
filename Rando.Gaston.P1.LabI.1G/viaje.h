#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include "fecha.h"
#include "destino.h"
#include "micro.h"
#include "empresa.h"
#include "tipo.h"

typedef struct{

int id;
int idMicro;
int idDestino;
eFecha fecha;
int isEmpty;

}eViaje;

#endif // VIAJE_H_INCLUDED



int inicializarViajes(eViaje viajes[], int tam);
int buscarLibreViajes(eViaje viajes[], int tam);
int altaViajes(eViaje viajes[], int tamV, eMicro micros[], int tamMic, eEmpresa empresas[], int tamEmp, eTipo tipos[], int tamTip,
               eDestino destinos[], int tamDes, eChofer choferes[], int tamC, int* pIdViajes);
void mostrarViaje(eViaje unViaje, eMicro micros[], int tamM, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int mostrarViajes(eViaje viajes[], int tamV, eMicro micros[], int tamM, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int mostrarViajesMicro(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                         eChofer choferes [], int tamC, eDestino destinos[], int tamDes,
                         eViaje viajes[], int tamV);

int mostrarViajesIdMicros(int idMicro, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                          int tamEmp, eChofer choferes[], int tamC, eDestino destinos[], int tamDes,
                          eViaje viajes[], int tamV);
int microSumaViajes(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                         eChofer choferes[], int tamC, eDestino destinos[], int tamDes,
                         eViaje viajes[], int tamV);
int mostrarSumaViajesMicro(int idMicro, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                            int tamEmp, eChofer choferes[], int tamC, eDestino destinos[], int tamDes,
                            eViaje viajes[], int tamV);
