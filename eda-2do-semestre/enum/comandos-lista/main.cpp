#include<iostream>
#include "string.h"
using namespace std;
#include "definicion.h"
#include "prototipo.h"
#define COMANDO 20

int main (int argc, char *argv[]) {
	lista cabezal = NULL;
	cadena comando = NULL;
	comando = new char[COMANDO];
	accion opcion;
	cout << ">";
	cin >> comando;
	while (strcmp(comando,"fin")!=0){
		opcion = error;
		if (strcmp(comando,"crear")==0){
			opcion = crear;
		}
		if (strcmp(comando,"mostrar")==0){
			opcion = mostrar;
		}
		if (strcmp(comando,"insertar")==0){
			opcion = insertar;
		}if (strcmp(comando,"contarNodos")==0){
			opcion = contarNodos;
		}if (strcmp(comando,"limpiar")==0){
			opcion = limpiar;
		}if (strcmp(comando,"ayuda")==0){
			opcion = ayuda;
		}
		switch(opcion){
			case crear:
				muestroRetorno(resultadoCrear(cabezal));
				break;
			case mostrar:
				muestroRetorno(resultadoMostrar(cabezal));
				break;
			case insertar:
				muestroRetorno(resultadoInsertar(cabezal));
				break;
			case contarNodos:
				muestroRetorno(resultadoContarNodos(cabezal));
				break;
			case limpiar:
				system("clear");
				break;
			case ayuda:
				help();
				break;
			default:
				muestroRetorno(ERROR);
		}
		cout << ">";
		cin >> comando;
	}
	finalizo();
	return 0;
}
