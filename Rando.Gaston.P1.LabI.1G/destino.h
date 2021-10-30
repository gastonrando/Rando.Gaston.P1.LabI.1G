#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct{

int id;
char descripcion[20];
float precio;

}eDestino;

#endif // DESTINO_H_INCLUDED

int mostrarDestinos( eDestino destinos[], int tam );
int validarIdDestino( int id, eDestino destinos[], int tam );
int cargarDescripcionDestino( eDestino destinos[], int tamDes,int idDes, char descripcion[] );
int cargarPrecio( eDestino destinos[], int tamDes,int idDes, float* pPrecio);
