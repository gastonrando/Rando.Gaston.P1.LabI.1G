#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "empresa.h"
#include "tipo.h"
#include "chofer.h"


typedef struct{

int id;
int idEmpresa;
int idTipo;
int capacidad;
int idChofer;
int isEmpty;

} eMicro;


#endif // MICRO_H_INCLUDED


char menu();
int inicializarMicros(eMicro listaMicros[], int tamMic);
int buscarLibre(eMicro listaMicros[], int tamMic);
int altaMicro(eMicro listaMicros[], int tamMic, eEmpresa empresas[], int tamEmp, eTipo tipos[], int tamTip,
              eChofer choferes[], int tamC,int* pIdChoferes, int* pIdMicros);
int buscarMicrosId(eMicro listaMicros[], int tam, int Id);
int modificarMicro(eMicro listaMicro[], int tamMic, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                   eChofer choferes[], int tamC);
int mostrarMicros(eMicro listaMicros[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                  eChofer choferes[], int tamC);
int menuModificar(eMicro listaMicro[], int tamMic, int indice, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                  eChofer choferes[], int tamC);
void mostrarMicro(eMicro unMicro, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                  eChofer choferes[], int tamC);
int ordenarMicro(eMicro lista[], int tam, eEmpresa empresas[], int tamEmp);
int bajaMicro(eMicro listaMicros[], int tamMic, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
              eChofer choferes[], int tamC);
int mostrarMicrosTipo(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                      eChofer choferes [], int tamC);
int mostrarMicrosIdTipos(int idTipos, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                         int tamEmp, eChofer choferes[], int tamC);
int mostrarMicrosEmpresa(eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                        eChofer choferes [], int tamC);
int mostrarMicrosIdEmpresas(int idEmpresa, eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                         int tamEmp, eChofer choferes[], int tamC);
int mostrarMicrosAllEmpresa(eMicro micros[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[], int tamEmp,
                         eChofer choferes[], int tamC);
int informeMicroEmpresasVIP (eMicro lista[], int tam, eTipo tipos[], int tamTip, eEmpresa empresas[],
                                      int tamEmp, eChofer choferes[], int tamC);
int empresaMayorCapacidad(eMicro lista[], int tam, eEmpresa empresas[], int tamEmp);

int empresaMenorCantMicros(eMicro lista[], int tam, eEmpresa empresas[], int tamEmp);
