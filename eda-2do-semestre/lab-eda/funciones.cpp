#include<iostream>
#include<stdio_ext.h>
using namespace std;
#include "estructuras.h"
#include "string.h"
#include<iomanip>

Archivo CrearArchivo(cadena nombre){
  Archivo a = new _archivo;
  a->nombre = nombre;
//  Version nuevo = new _version;
//  strcpy(nuevo->idVersion, "1");
  /*a->primeraVersion = nuevo;*/
  return a;
}


Version existencia_Version(Version v,cadena id){
	
	if (v == nullptr)
		return nullptr;
	
	// Caso base: encontramos la versi�n
	if (strcmp(v->idVersion,id) == 0)
		return v;
	
	// hijos 
	Version encontrada = existencia_Version(v->primerHijo,id);
	if (encontrada != nullptr)
		return encontrada;
	
	// Si no est� en los hijos, buscar en los hermanos
	return existencia_Version(v->sigHermano, id);
}

	
Archivo eliminarInfoArchivo(Archivo a){
	if (a == nullptr){
		
		return nullptr;
	}
	delete a;
	a = nullptr;
	return a;
}
void borrarLinea_Recursivo(lineas &a){
	if (a == nullptr){
		return ;
	}
	borrarLinea_Recursivo(a->sig);
	delete a;
	a = nullptr;
}
	
void borrarVersion_Recursivo(Version &a){
	if (a == nullptr){
		return ;
	}
	borrarVersion_Recursivo(a->primerHijo);
	borrarVersion_Recursivo(a->sigHermano);
	borrarLinea_Recursivo(a->textoVersion);
	delete a;
	a = nullptr;
}
	
	
	
	
	
void liberarLineas(lineas &l) {
	lineas actual = l;
	lineas siguiente;
	while (actual != NULL) {
		siguiente = actual->sig;
		// Liberar la cadena de texto de la l�nea
		if (actual->textoLinea != NULL) {
			delete[] actual->textoLinea;
		}
		// Liberar el nodo _linea
		delete actual; 
		actual = siguiente;
	}
	l = NULL; // La lista queda vac�a
}
	
	// Funci�n auxiliar para liberar una �nica versi�n (incluyendo su texto)
void liberarVersion(Version &v) {
	if (v != NULL) {
		// 1. Liberar todas las l�neas de texto
		liberarLineas(v->textoVersion);
		
		// 2. Liberar el idVersion (si tu _version tiene un destructor, esto es autom�tico)
		if (v->idVersion != NULL) {
			delete[] v->idVersion;
		}
		
		// 3. Liberar el nodo _version
		delete v;
		v = NULL;
	}
}
	
	// Funci�n auxiliar para encontrar el padre de una versi�n (�til para desenlazar)
Version encontrarPadre(Version v, cadena idHijo) {
	if (v == NULL) return NULL;
	
	// El padre est� en la misma rama (primerHijo o sigHermano)
	Version temp = v->primerHijo;
	Version padre = NULL;
	
	while (temp != NULL && padre == NULL) {
		if (strcmp(temp->idVersion, idHijo) == 0) {
			return v; // Encontrado como hijo directo
		}
		// Buscar recursivamente en hijos
		padre = encontrarPadre(temp, idHijo); 
		if (padre != NULL) return padre;
		
		temp = temp->sigHermano;
	}
	
	// Si no est� en los hijos directos, buscar en hermanos del nodo actual
	return encontrarPadre(v->sigHermano, idHijo);
}


void mostrarArbol(Version a,int espacio){
	if (a != nullptr){
		cout << setw(espacio) << a->idVersion << endl;
		espacio = espacio + 5;
		mostrarArbol(a->primerHijo,espacio);
		espacio = espacio - 5;
		mostrarArbol(a->sigHermano,espacio);
	}
	return;
	
	
}
	
	
void itoa_simple(int n, char res[]) {
	// Caso especial para 0
	if (n == 0) {
		res[0] = '0';
		res[1] = '\0';
		return;
	}
	
	int i = 0;
	
	// Convertir d�gitos a caracteres en orden inverso
	while (n != 0) {
		res[i++] = n % 10 + '0';
		n = n / 10;
	}
	res[i] = '\0'; // Terminador nulo
	
	// Invertir la cadena para obtener el orden correcto
	int start = 0;
	int end = strlen(res) - 1;
	char temp;
	
	while (start < end) {
		temp = res[start];
		res[start] = res[end];
		res[end] = temp;
		start++;
		end--;
	}
}
