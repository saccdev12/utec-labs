#include<iostream>
using namespace std;
#include "prototipos.h"
#include "estructura.h"

//Creo el arbol inicializando en NULL su puntero.
arbol creoArbol(){
	return NULL;
}
	
bool esVacio(arbol a){
	if(a == NULL){
		return true;
	}else{
		return false;
	}
}

//Inserta un nuevo nodo con el valor v segun ABB.	
void insertar(arbol &a, int v){
	if(esVacio(a)){
		a = new _nodo;
		a -> valor = v;
		return;
	}else{
		if(v > a->valor){
			insertar(a->hijoDer, v);
		}else{
			if(v < a->valor){
				insertar(a->hijoIzq, v);
			}
		}
	}
}

//Muestra el contenido del ABB en Orden.	
void inorden(arbol a){
	if(!esVacio(a)){
		inorden(a->hijoIzq);
		cout << a->valor << " - " ;
		inorden(a->hijoDer);
	}
}

void preorden(arbol a){
	if(!esVacio(a)){
		cout << a->valor << " - " ;
		preorden(a->hijoIzq);
		preorden(a->hijoDer);
	}
}
	
void postorden(arbol a){
	if(!esVacio(a)){
		postorden(a->hijoIzq);
		postorden(a->hijoDer);
		cout << a->valor << " - ";
	}
}	

int valor(arbol a){
	return a->valor;
}	
