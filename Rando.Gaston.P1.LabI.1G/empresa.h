#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct{

int id;
char descripcion[20];

}eEmpresa;

#endif // EMPRESA_H_INCLUDED

int mostrarEmpresas( eEmpresa empresas[], int tam );
int validarIdEmpresa( int id, eEmpresa empresas[], int tam );
int cargarDescripcionEmpresas( eEmpresa empresas[], int tamEmp,int idEmp, char descripcion[] );
