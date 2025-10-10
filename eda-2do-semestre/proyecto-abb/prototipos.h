#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
#include "estructura.h"

//Creo el arbol inicializando en NULL su puntero.
arbol creoArbol();

bool esVacio(arbol a);

//Inserta un nuevo nodo con el valor v segun ABB.
void insertar(arbol &a, int v);

//Muestra el contenido del ABB en Orden.
void inorden(arbol a);

void preorden(arbol a);

void postorden(arbol a);

int valor(arbol a);






#endif
