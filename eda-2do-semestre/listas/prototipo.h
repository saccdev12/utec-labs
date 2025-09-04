#ifndef PROTOTIPO_H
#define PROTOTIPO_H
#include "definicion.h"
// esta funci�n devuelve la lista vac�a.
lista creo_vacia();
	
//devuelve true si la lista es vac�a y false si no lo es.
bool es_vacia(lista l); 
	
//Funcion que inserta un nuevo nodo al principio de la lista con el valor x.
lista insertoPrincipio(lista l, int x);

// Procedimiento que inserta un nuevo nodo al principio de la lista con el valor x.
void insertoPrincipio2(lista &l, int x);


// devuelve el valor del elemento en la primer posici�n de la lista.
//Precondici�n: se puede utilizar esta operaci�n solo si l no es vac�a.
int primero(lista l);

//imprime los elementos de la lista	recursivo
void imprimoRecursivo(lista l);


//imprime los elementos de la lista iterativamente
void imprimoIterativo(lista l);

//devuelve la cantidad de nodos de una lista
int cantidadNodos(lista l);


int cantidadNodosIterativo(lista l);

//devuelve la suma de todos los valores de la lista
int sumaNodos(lista l);

//devuelve el ultimo valor de la lista
//Precondicion: la existe
int ultimo(lista l);

//devuelve la ubicion del valor de un nodo dentro de la lista.
int lugar(lista l, int v);

//inserto nodo al final
lista insertoFinal(lista l, int v);


//Insertar despues de un nodo existente en la lista
//Precondicion: lista existe.
void insertarDespuesde(lista l, int v, int x);


//Insertar antes de un nodo existente en la lista
//Precondicion: lista existe.
void insertarAntesde(lista &l, int v, int x);

//devuelve la direccion de memoria donde se encuentra el nodo
lista dirNodo(lista l, int v);

//elimino 1er nodo lista
lista eliminoPrincipio(lista l);

//elimino ultimo nodo lista
//Precondicion: lista existe
lista eliminoUltimo(lista l);

//elimino nodo con valor
//Precondicion: lista existe
lista eliminoNodo(lista l, int v);


#endif