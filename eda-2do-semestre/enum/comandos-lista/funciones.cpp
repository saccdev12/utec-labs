#include<iostream>
#include "string.h"
using namespace std;
#include "definicion.h"

void muestroRetorno(tipoRetorno retorno){
	switch (retorno){
	case OK:
		cout << "OK";
		break;
	case ERROR:
		cout << "ERROR";
		break;
	case NO_IMPLEMENTADO:
		cout << "NO IMPLEMENTADO";
	}
	cout << endl;
}

	
void finalizo(){
	cout << "Gracias por utilizar comando 1.0 - Todos los derechos reservados " << endl;
}


tipoRetorno resultadoCrear(lista l){
	return NO_IMPLEMENTADO;
}
tipoRetorno resultadoInsertar(lista l){
	return NO_IMPLEMENTADO;
}
tipoRetorno resultadoMostrar(lista l){
	return NO_IMPLEMENTADO;
}
tipoRetorno resultadoContarNodos(lista l){
	return NO_IMPLEMENTADO;
}

void help(){
	cout << "Comando permitidos: crear - mostrar - insertar - contarNodos - limpiar - ayuda - fin"<<endl;
}
