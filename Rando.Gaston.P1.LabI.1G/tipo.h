#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{

int id;
char descripcion[20];

} eTipo;


#endif // TIPO_H_INCLUDED

int validarIdTipos( int id, eTipo tipos[], int tam );
int mostrarTipos( eTipo tipos[], int tam );
int cargarDescripcionTipos( eTipo tipos[], int tamTip,int idTipo, char descripcion[] );
