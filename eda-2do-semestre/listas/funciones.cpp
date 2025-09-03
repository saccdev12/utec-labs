#include<iostream>
using namespace std;
#include "definicion.h"
// esta funci�n devuelve la lista vac�a.
lista creo_vacia(){
	return NULL;
}

//devuelve true si la lista es vac�a y false si no lo es.
bool es_vacia(lista l){
	if (l == NULL)
		return true;
	else
		return false;
}

//inserta un nuevo nodo al principio de la lista con el valor x.
lista insertoPrincipio(lista l, int x){
	lista nuevoNodo;
	nuevoNodo = new nodo;
	nuevoNodo->valor = x;
	nuevoNodo->sig = l;
	return nuevoNodo;
}
	
void insertoPrincipio2(lista &l, int x){
	lista nuevoNodo;
	nuevoNodo = new nodo;
	nuevoNodo->valor = x;
	nuevoNodo->sig = l;
	l = nuevoNodo;
		
}
// devuelve el valor del elemento en la primer posici�n de la lista.
//Precondici�n: se puede utilizar esta operaci�n solo si l no es vac�a.
int primero(lista l){
	return l->valor;
}

//imprime los elementos de la lista	
void imprimoRecursivo(lista l){
	if (!es_vacia(l)){
		cout << l->valor << " - ";
		imprimoRecursivo(l->sig);
	}
}
	
void imprimoIterativo(lista l){
	while (!es_vacia(l)){
		cout << l->valor << " - ";
		l=l->sig;
	}
}

	
//devuelve la cantidad de nodos de una lista
int cantidadNodos(lista l){
	if (!es_vacia(l))
		return 1 + cantidadNodos(l->sig);
	else
		return 0;
}
	
int cantidadNodosIterativo(lista l){
	int contador = 0;
	while (!es_vacia(l)){
		contador++;
		l = l->sig;
	}
	return contador;
}
	
int sumaNodos(lista l){
	if (!es_vacia(l))
		return l->valor + sumaNodos(l->sig);
	else
		return 0;
}

//precondicion: la lista existe
int ultimo(lista l){
	if (es_vacia(l->sig)){
		return l->valor;
	}else{
		return ultimo(l->sig);
	}	
}

//devuelve la ubicion del valor de un nodo dentro de la lista.
int lugar(lista l, int v){
	int ubicacion = 0;
	while (!es_vacia(l)){
		ubicacion++;
		if (l->valor == v){
			return ubicacion;
		}else{
			l = l->sig;
		}
	}
	return 0;
}
	
//inserto nodo al final
lista insertoFinal(lista l, int v){
	lista aux;
	aux = l;
	while (!es_vacia(l->sig)){
		l=l->sig;
	}
	lista nuevoNodo;
	nuevoNodo = new nodo;
	nuevoNodo->valor = v;
	nuevoNodo->sig = NULL;
	l->sig = nuevoNodo;
	return aux;
}

//Insertar despues de un nodo existente en la lista
//Precondicion: lista existe.
void insertarDespuesde(lista l, int v, int x){
	if (lugar(l,v) == 0){
		cout << "Valor "<<v<< " no se encuentra en al lista"<<endl;
		return;
	}
	lista aux;
	aux = l;
	while (aux->valor != v){
		aux = aux->sig;
	}
	lista nuevoNodo;
	nuevoNodo = new nodo;
	nuevoNodo->valor = x;
	nuevoNodo->sig = aux->sig;
	aux->sig = nuevoNodo;
}
	
//Insertar antes de un nodo existente en la lista
//Precondicion: lista existe.
void insertarAntesde(lista &l, int v, int x){
	lista aux;
	aux = l;
	if (lugar(aux,v) == 0){
		cout << "Valor "<<v<< " no se encuentra en al lista"<<endl;
		return;
	}
	if (aux->valor == v){
		insertoPrincipio2(l,x);
		return;
	}
	while ((aux->sig)->valor != v){
		aux = aux->sig;
	}
	lista nuevoNodo;
	nuevoNodo = new nodo;
	nuevoNodo->valor = x;
	nuevoNodo->sig = aux->sig;
	aux->sig = nuevoNodo;
	
}
//devuelve la direccion de memoria del nodo cuyo valor es v
lista dirNodo(lista l, int v){
	while (!es_vacia(l) && l->valor != v){
		l = l->sig;
	}
	return l;
}
//elimino el primer nodo de la lista
lista eliminoPrincipio(lista l){
	if(es_vacia(l)){
		cout << "Lista vacia"<<endl;
		return l;
	}
	lista aborrar;
	aborrar = l;
	l = l->sig;
	delete aborrar;
	return l;
}
