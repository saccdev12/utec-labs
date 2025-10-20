#include<iostream>
#include<stdio_ext.h>
using namespace std;

#include"prototipos.h"
#include "estructuras.h"
#include "string.h"

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
	while(strcmp(parametro[0],"Salir")!= 0){
		__fpurge(stdin);
		opcion = error;
		__fpurge(stdin);
		if (strcmp(parametro[0],"InsertarLinea")==0){
			opcion = InsertarLinea;
		}
		if (strcmp(parametro[0],"BorrarLinea")==0){
			opcion = BorrarLinea;
		}
		if (strcmp(parametro[0],"MostrarTexto")==0){
			opcion = MostrarTexto;
		}
		if (strcmp(parametro[0],"CrearVersion")==0){
			opcion = CrearVersion;
		}
		if (strcmp(parametro[0],"BorrarVersion")==0){
			opcion = BorrarVersion;
		}
		if (strcmp(parametro[0],"MostrarVersiones")==0){
			opcion = MostrarVersiones;
		}
		if (strcmp(parametro[0],"MostrarCambios")==0){
			opcion = MostrarCambios;
		}
		if (strcmp(parametro[0],"VersionIndependiente")==0){
			opcion = VersionIndependiente;
		}
		if (strcmp(parametro[0],"limpiar")==0){
			opcion = limpiar;
		}
		if (strcmp(parametro[0],"ayuda")==0){
			opcion = ayuda;
		}
		
		
		
		switch (opcion){
		case InsertarLinea:
			muestroRetorno(insertarLinea(a,parametro[2],parametro[3],atoi(parametro[4])));
			break;
		case MostrarTexto:
			muestroRetorno(mostrarTexto(a,parametro[2]));
		    break;
		case BorrarLinea:
			muestroRetorno(borrarLinea(a,parametro[2],atoi(parametro[3])));
			break;
		case CrearVersion:
			muestroRetorno(crearVersion(a,parametro[2]));
			break;
		case MostrarVersiones:
			muestroRetorno(mostrarVersiones(a));
			break;
		case BorrarVersion:
			muestroRetorno(borrarVersion(a,parametro[2]));
			break;
		case MostrarCambios:
			muestroRetorno(mostrarCambios(a, parametro[2]));
			break;
		case VersionIndependiente:
			muestroRetorno(versionIndependiente(a, parametro[2]));
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
