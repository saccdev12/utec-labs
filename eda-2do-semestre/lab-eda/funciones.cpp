#include<iostream>
#include<stdio_ext.h>
using namespace std;
#include "estructuras.h"
#include "string.h"


Archivo CrearArchivo(cadena nombre){
  Archivo a = new _archivo;
  a->nombre = nombre;
  Version nuevo = new _version;
  strcpy(nuevo->idVersion, "1");
  a->primeraVersion = nuevo;
  return a;
}

  
  
Version existencia_Version(Version v,cadena id){
	
	if (v == nullptr)
		return nullptr;
	
	// Caso base: encontramos la versión
	if (strcmp(v->idVersion,id) == 0)
		return v;
	
	// hijos 
	Version encontrada = existencia_Version(v->primerHijo,id);
	if (encontrada != nullptr)
		return encontrada;
	
	// Si no está en los hijos, buscar en los hermanos
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
	
