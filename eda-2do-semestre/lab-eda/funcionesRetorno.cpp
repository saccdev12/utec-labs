#include<iostream>
#include<stdio_ext.h>
using namespace std;
#include "estructuras.h"
#include "string.h"
#include"prototipos.h"
void muestroRetorno(TipoRet retorno){
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
	
void help(){
	cout<<"InsertarLinea(nombre_archivo,\"version\",\"argumento\",linea)"<<endl<<"MostrarTexto(Nombre_archivo,\"version\")"<<endl;
	cout<<"BorrarLinea(Nombre_archivo,\"version\",\"linea\")"<<"mostrarCambios()"<<endl;
	cout<<"CrearVersion(Nombre_archivo,\"version\")"<<endl<<"MostrarVersiones(nombre_archivo)"<<endl<<"BorrarVersion(Nombre_archivo,\"version\")"<<endl;
	cout<<"VersionIndependiente(Nombre_archivo,\"version\")"<<endl<<"ayuda, salir, limpiar"<<endl;
}
	

TipoRet crearVersion(Archivo &a, cadena version){
	return NO_IMPLEMENTADO;
}
TipoRet borrarVersion(Archivo &a, cadena version){
	return NO_IMPLEMENTADO;
}
TipoRet mostrarVersiones(Archivo a){
	return NO_IMPLEMENTADO;
}
	
TipoRet insertarLinea(Archivo &a,cadena version, cadena linea,unsigned int nroLinea){
	
	if (a == NULL || version == NULL || linea == NULL){
		return ERROR;
	}
	Version aux = existencia_Version(a->primeraVersion,version);
	if (aux==NULL){
		cout<<"No existe la version "<< endl;
		return ERROR;
	}
	if (aux->primerHijo != NULL) {
		cout << "ERROR: La versión tiene subversiones, no es editable." << endl;
		return ERROR;
	}
	lineas auxLineas = aux->textoVersion;
	unsigned int x=0;
	while(auxLineas != NULL){
		x++;
		auxLineas=auxLineas->sig;
	}
	
	if (nroLinea < 1 || nroLinea > x+1){
		cout << "ERROR: Número de línea inválido." << endl;
		return ERROR;
	}
	//paso todas las pruebas 
	lineas aInsetar = new _linea;
	strcpy(aInsetar->textoLinea, linea);
	aInsetar->numero = nroLinea;
	aInsetar->sig = NULL;
	//si no hay nada 
	if (aux->textoVersion == NULL) {
		aux->textoVersion = aInsetar;
		return OK;
	}
	//ppio
	if (nroLinea == 1) {
		aInsetar->sig = aux->textoVersion;
		aux->textoVersion = aInsetar;
	}else{
		lineas anterior = aux->textoVersion;
		for (unsigned int i = 1; i < nroLinea - 1; i++) {
			anterior = anterior->sig;
		}
		aInsetar->sig = anterior->sig;
		anterior->sig = aInsetar;
	}
	lineas acomodador_numLineas = aux->textoVersion;
	int nominador = 1;
	while (acomodador_numLineas != NULL) {
		acomodador_numLineas->numero = nominador++;
		acomodador_numLineas = acomodador_numLineas->sig;
	}
	return OK;
	
}
TipoRet borrarLinea(Archivo &a, cadena version, unsigned int nroLinea){
	// Verificaciones iniciales
	if (a == NULL || version == NULL) {
		return ERROR;
	}
	
	// Buscar la version
	Version v = existencia_Version(a->primeraVersion, version);
	if (v == NULL) {
		cout << "ERROR: No existe la versiÃ³n indicada." << endl;
		return ERROR;
	}
	
	// No se puede borrar si tiene subversiones
	if (v->primerHijo != NULL) {
		cout << "ERROR: La versiÃ³n tiene subversiones, no es editable." << endl;
		return ERROR;
	}
	
	// Si no hay lineas, nada que borrar
	if (v->textoVersion == NULL) {
		cout << "ERROR: La versiÃ³n no contiene lÃ­neas." << endl;
		return ERROR;
	}
	
	// Calcular cantidad de lineas
	lineas aux = v->textoVersion;
	unsigned int total = 0;
	while (aux != NULL) {
		total++;
		aux = aux->sig;
	}
	
	if (nroLinea < 1 || nroLinea > total) {
		cout << "ERROR: NÃºmero de lÃ­nea invÃ¡lido." << endl;
		return ERROR;
	}
	
	// Eliminar la linea correspondiente
	lineas actual = v->textoVersion;
	lineas anterior = NULL;
	
	for (unsigned int i = 1; i < nroLinea; i++) {
		anterior = actual;
		actual = actual->sig;
	}
	
	// Caso 1: borrar la primera linea
	if (anterior == NULL) {
		v->textoVersion = actual->sig;
	} else { // Caso 2: borrar una linea intermedia o final
		anterior->sig = actual->sig;
	}
	
	delete[] actual->textoLinea;
	delete actual;
	
	// Reajustar numeracion
	lineas reenum = v->textoVersion;
	unsigned int nuevoNumero = 1;
	while (reenum != NULL) {
		reenum->numero = nuevoNumero++;
		reenum = reenum->sig;
	}
	
	return OK;
}
	
	


TipoRet mostrarTexto(Archivo a, cadena version){
	if(a==NULL){
		
		return ERROR;
	}
	Version arquivo = existencia_Version(a->primeraVersion,version);
	if(arquivo==NULL){
		cout<<"No esxiste la version buscada en : "<<a->nombre<<endl;
		return ERROR;
	}
	cout << a->nombre << " - " << arquivo->idVersion << endl;
	
	lineas auxLineas = arquivo->textoVersion;
	if (auxLineas==NULL){
		cout<<"No tiene Lineas"<<endl;
		return OK;
	}
	while(auxLineas!=NULL){
		cout<<auxLineas->numero<< " | " <<  auxLineas->textoLinea<<endl;
		auxLineas=auxLineas->sig;
	}
	return OK;
}
	
TipoRet mostrarCambios(Archivo a, cadena version){
	return NO_IMPLEMENTADO;
}

TipoRet BorrarArchivo(Archivo &a){
	a = eliminarInfoArchivo(a);
	cout<<"El archivo fue borrado con exito Gracias por usarnos"<<endl;
	return OK;
}

TipoRet versionIndependiente(Archivo &a, cadena version){
	return NO_IMPLEMENTADO;
}

