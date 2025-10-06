#include<iostream>
using namespace std;
#include "string.h"
#include "estructuras.h"
#include "prototipos.h"
void help(){
	cout << "Los comandos son: inicio, compro, vendo, listo, salgo, limpio"<<endl;
}

producto creoProducto(){
	return NULL;
}

bool esVacioProducto(producto listaProducto){
	return listaProducto == NULL;
}


producto comprarProducto(producto listaProducto, cadena parametro[]){
	producto auxP,nuevoProducto;
	auxP = listaProducto;
	while (!esVacioProducto(auxP) && (strcmp(auxP->nombre,parametro[1])!=0)){
		auxP = auxP->sigP;
	}
	//cargo el producto
	if (esVacioProducto(auxP)){
		nuevoProducto = new _nodoProducto;
		strcpy(nuevoProducto->nombre,parametro[1]); 
		nuevoProducto->sigP = listaProducto;
		listaProducto = nuevoProducto;
	}else{
		nuevoProducto = auxP;
	}
	//cargo cantidad y precio 
	return listaProducto;
}

