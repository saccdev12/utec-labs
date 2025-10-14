#include<iostream>
#include<stdio_ext.h>
#include <string.h>
using namespace std;

#include"prototipos.h"
#include "estructuras.h"

int main (int argc, char *argv[]) {
	Archivo a;
	cadena name = new char[T];
	strcpy(name,"c");
	a = CrearArchivo(name);
	cout<<a->nombre<<endl;
	cadena comando = new char[100];
	cadena parametro[P]; //defino arreglo con 4 punteros a char
	__fpurge(stdin);
	while (strlen(comando)==0){
		cout << ">";
		cin.getline(comando,100);
	}
	__fpurge(stdin);
	char delim[] = "(\",\")"; //defino los limitadores en su respectivo orden
	
	int contador = 0;
	parametro[contador] = strtok(comando,delim);
	contador++;
	parametro[contador] = strtok(NULL,delim);
	while (parametro[contador]!=NULL){
		contador++;
		parametro[contador] = strtok(NULL,delim);
	}
	__fpurge(stdin);
	opciones opcion;
	__fpurge(stdin);
	while(strcmp(parametro[0],"salir")!= 0){
		__fpurge(stdin);
		opcion = error;
		__fpurge(stdin);
		if (strcmp(parametro[0],"insertarLinea")==0){
			opcion = insertarLinea;
		}
		if (strcmp(parametro[0],"borrarLinea")==0){
			opcion = borrarLinea;
		}
		if (strcmp(parametro[0],"mostrarTexto")==0){
			opcion = mostrarTexto;
		}
		if (strcmp(parametro[0],"crearVersion")==0){
			opcion = crearVersion;
		}
		if (strcmp(parametro[0],"borrarVersion")==0){
			opcion = borrarVersion;
		}
		if (strcmp(parametro[0],"mostrarVersiones")==0){
			opcion = mostrarVersiones;
		}
		if (strcmp(parametro[0],"mostrarCambios")==0){
			opcion = mostrarCambios;
		}
		if (strcmp(parametro[0],"versionIndependiente")==0){
			opcion = versionIndependiente;
		}
		if (strcmp(parametro[0],"limpiar")==0){
			opcion = limpiar;
		}
		if (strcmp(parametro[0],"ayuda")==0){
			opcion = ayuda;
		}
		
		
		
		switch (opcion){
		case insertarLinea:
			muestroRetorno(InsertarLinea(a,parametro[2],parametro[3],atoi(parametro[4])));
			break;
		case mostrarTexto:
			muestroRetorno(MostrarTexto(a,parametro[2]));
		    break;
		case borrarLinea:
			muestroRetorno(BorrarLinea(a,parametro[2],atoi(parametro[3])));
			break;
		case crearVersion:
			muestroRetorno(CrearVersion(a,parametro[2]));
			break;
		case mostrarVersiones:
			muestroRetorno(MostrarVersiones(a));
			break;
		case borrarVersion:
			muestroRetorno(BorrarVersion(a,parametro[2]));
			break;
		case mostrarCambios:
			muestroRetorno(MostrarCambios(a, parametro[2]));
			break;
		case versionIndependiente:
			muestroRetorno(VersionIndependiente(a, parametro[2]));
			break;
//		case iguales:
//			muestroRetorno(Iguales(a, parametro[2],parametro[3],))
		case ayuda:
			help();
			break;
		case limpiar:
			system("clear");
			break;
		default:
			muestroRetorno(ERROR);
		}
		__fpurge(stdin);
		strcpy(comando,"");
		
		while (strlen(comando)==0){
			cout << ">";
			cin.getline(comando,100);
		}
		int contador = 0;
		parametro[contador] = strtok(comando,delim);
		contador++;
		parametro[contador] = strtok(NULL,delim);
		
		while (parametro[contador]!=NULL){
			contador++;
			parametro[contador] = strtok(NULL,delim);
		}
		
	}
	muestroRetorno(BorrarArchivo(a));
	
	return 0;
}
