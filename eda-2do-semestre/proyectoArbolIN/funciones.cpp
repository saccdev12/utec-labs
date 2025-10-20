#include<iostream>
using namespace std;
#include "estructura.h"
#include "prototipo.h"

arboln crearArbol(){
//Inicia el nuevo arbol agregando creando la raiz con el valor 0
	arboln nuevoNodo = new _arboln;
	nuevoNodo->valor = 0;
	return nuevoNodo;
}
	
void insertarNodo(arboln &a, int valorPadre, int valor){
//Inserta un nuevo nodo al arbol. dependiendo del valorPadre el cual debe existir
return;
}


void mostrarArbol(arboln a){
//muestra el arbol en preorden
	return;
	
}


arboln buscarNodo(arboln a, int valor){
//Busca nodo con el valor recibido por parametro. devuelve direccion del mismo si existe
return NULL;
}

bool EsVacio(arboln a){
//devuelve true si el arbol no existe.
return true;
}
void mostrarHijos(arboln a){
//muestra los hijos de la dirección del arbol o subarbol recibido. Debe existir 
return;
}


int cantidadNodos(arboln a){
//devuelve la cantidad de nodos del arbol/subarbol
	return 0;
}

void eliminoArbol(arboln a){
//elimina el arbol por completo liberando los espacios de memoria.
return;
}
