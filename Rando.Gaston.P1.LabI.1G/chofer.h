#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct{

int id;
char nombre[20] ;
char sexo;
int isEmpty;

}eChofer;


#endif // CHOFER_H_INCLUDED

int cargarDescripcionChofer( eChofer choferes[], int tamCli ,int idcliente, char nombre[] );
int mostrarChofer( eChofer choferes[], int tam );
int validarIdChoferes( int id, eChofer choferes[], int tam );
int inicializarChoferes(eChofer choferes[], int tam);
int buscarLibreChoferes(eChofer choferes[], int tam);
int altaChoferes(eChofer choferes[], int tamC, int* pId);
