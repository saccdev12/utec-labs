#include<iostream>
using namespace std;
#include "estructuras.h"
#include "prototipos.h"
#include "string.h"
int main (int argc, char *argv[]) {
	producto listaProducto = NULL;
	cadena comando = new char[100];
	cout << ">";
	cin.getline(comando,100);
	char delim[] = "( \" , \" )"; //defino los limitadores en su respectivo orden
	char *parametro[T]; //defino arreglo con 4 punteros a char
	int contador = 0;
	parametro[contador] = strtok(comando,delim);
	contador++;
	parametro[contador] = strtok(NULL,delim);
	while (parametro[contador]!=NULL){
		contador++;
		parametro[contador] = strtok(NULL,delim);
	}
	opciones opcion;
	while (strcmp(parametro[0],"salgo")!= 0){
		opcion = error;
		if (strcmp(parametro[0],"inicio")==0){
			opcion = inicio;
		}
		if (strcmp(parametro[0],"compro")==0){
			opcion = compro;
		}
		if (strcmp(parametro[0],"vendo")==0){
			opcion = vendo;
		}
		if (strcmp(parametro[0],"listo")==0){
			opcion = listo;
		}
		if (strcmp(parametro[0],"ayuda")==0){
			opcion = ayuda;
		}
		if (strcmp(parametro[0],"limpio")==0){
			opcion = limpio;
		}
		switch (opcion){
		case inicio:
			muestroRetorno(crearProducto(listaProducto));
			break;
		case compro:
			muestroRetorno(comprar(listaProducto,parametro));
			break;
		case vendo:
			muestroRetorno(vender(listaProducto,parametro));
			break;
		case listo:
			muestroRetorno(listar(listaProducto));
			break;
		case limpio:
			system("clear");
			break;
		case ayuda:
			help();
			break;
		default:
			muestroRetorno(ERROR);
		}
		cout << ">";
		cin.getline(comando,100);
		int contador = 0;
		parametro[contador] = strtok(comando,delim);
		contador++;
		parametro[contador] = strtok(NULL,delim);
		while (parametro[contador]!=NULL){
			contador++;
			parametro[contador] = strtok(NULL,delim);
		}

	}
	return 0;
}
