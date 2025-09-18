#include<iostream>
using namespace std;
#include "definicion.h"

cabezal creolista(cabezal l){
	l.primero = NULL;
	l.ultimo = NULL;
	return l;
}
bool esvacio(listaDoble puntero){
	if (puntero == NULL){
		return true;
	}else{
		return false;
	}
}
void imprimo_ppio_fin(listaDoble primero){
	if (esvacio(primero)){
		cout << endl;
		return;
	}else{
		cout << "  " << primero->valor ;
		imprimo_ppio_fin(primero->sig);
	}
}
void imprimo_fin_ppio(listaDoble ultimo){
	if (esvacio(ultimo)){
		cout << endl;
		return;
	}else{
		cout << "  " << ultimo->valor ;
		imprimo_fin_ppio(ultimo->ant);
	}	
}
	
cabezal insertarPpio(cabezal l, int v){
	listaDoble nuevoNodo = new _nodo;
	nuevoNodo->ant = NULL;
	nuevoNodo->valor = v;
	nuevoNodo->sig = NULL;
	if (esvacio(l.primero) && esvacio(l.ultimo)){
		l.ultimo = nuevoNodo;
	}else{
		nuevoNodo->sig = l.primero;
		l.primero->ant = nuevoNodo;
	}
	l.primero = nuevoNodo;
	
	return l;
}
	
cabezal insertarFin(cabezal l, int v){
	listaDoble nuevoNodo = new _nodo;
	nuevoNodo->ant = NULL;
	nuevoNodo->valor = v;
	nuevoNodo->sig = NULL;
	if (esvacio(l.primero) && esvacio(l.ultimo)){
		l.primero = nuevoNodo;
	}else{
		nuevoNodo->ant = l.ultimo;
		l.ultimo->sig = nuevoNodo;
	}
	l.ultimo = nuevoNodo;
	return l;
}

TipoRet crearLista(cabezal &l){
	l = creolista(l);
	cout << "Lista creada"<<endl;
	return OK;
}
TipoRet insertar_al_principio(cabezal &l,int valor){
	l = insertarPpio(l,valor);
	return OK;
}
TipoRet insertar_al_final(cabezal &l,int valor){
	l = insertarFin(l,valor);
	return OK;
}
TipoRet mostrar_ppio_fin(listaDoble primero){
	if (esvacio(primero)){
		cout << "Lista Vacia" << endl;
		return ERROR;
	}
	imprimo_ppio_fin(primero);
	return OK;
}
TipoRet mostrar_fin_ppio(listaDoble ultimo){
	if (esvacio(ultimo)){
		cout << "Lista Vacia" << endl;
		return ERROR;
	}
	imprimo_fin_ppio(ultimo);
	return OK;
}
TipoRet borrar_principio(cabezal &l){
	return NO_IMPLEMENTADO;
}
TipoRet borrar_ultimo(cabezal &l){
	return NO_IMPLEMENTADO;
}
void mostrarRetorno(TipoRet retorno){
	switch (retorno){
	case OK:
		cout << "OK" << endl;
		break;
	case ERROR:
		cout << "ERROR"<<endl;
		break;
	case NO_IMPLEMENTADO:
		cout << "NO IMPLEMENTADO"<< endl;
		break;
	}
}