#include<iostream>
using namespace std;
#include "estructuras.h"

tipoRet crearProducto(producto &listaProducto){
	return NO_IMPLEMENTADO;
}
tipoRet comprar(producto &listaProducto, char *parametro[]){
	return NO_IMPLEMENTADO;
}
tipoRet vender(producto &listaProducto, char *parametro[]){
	return NO_IMPLEMENTADO;
}
tipoRet listar(producto listaProducto){
	return NO_IMPLEMENTADO;
}
	
void muestroRetorno(tipoRet retorno){
	switch (retorno){
	case OK:
		cout << "OK"<< endl;
		break;
	case ERROR:
		cout << "ERROR" << endl;
		break;
	case NO_IMPLEMENTADO:
		cout << "NO IMPLEMENTADA"<<endl;
	}
}