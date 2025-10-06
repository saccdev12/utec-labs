#include<iostream>
using namespace std;
#include "string.h"
#include "estructuras.h"
#include "prototipos.h"

tipoRet crearProducto(producto &listaProducto){
	listaProducto = creoProducto();
	return OK;
}
tipoRet comprar(producto &listaProducto, cadena parametro[]){
	if (atoi(parametro[2]) <= 0 || atoi(parametro[3]) <= 0) {
		cout<<"La cantidad o precio debe ser mayor a 0"<<endl;
		return ERROR;
	}
	listaProducto = comprarProducto(listaProducto, parametro);
	return OK;
}

tipoRet vender(producto &listaProducto, cadena parametro[]){
	return NO_IMPLEMENTADO;
}
	
tipoRet listar(producto listaProducto){
	if (esVacioProducto(listaProducto)){
		cout << "No hay productos para mostrar"<<endl;
		return ERROR;
	}
	while (!esVacioProducto(listaProducto)){
		cout << listaProducto->nombre << endl;
		listaProducto = listaProducto->sigP;
	}
	return OK;
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
