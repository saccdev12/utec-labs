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
		// 1. Verificar el archivo y la cadena de la nueva versión.
		if (a == NULL || version == NULL || strlen(version) == 0) {
			return ERROR;
		}
		
		// El parámetro 'nuevaVersion' contiene el ID de la versión padre (según la ayuda en tu main).
		// Buscamos la versión padre.
		Version versionPadre = existencia_Version(a->primeraVersion, version);
		
		if (versionPadre == NULL) {
			cout << "ERROR: No existe la versión padre ('" << version << "') para crear una nueva versión." << endl;
			return ERROR;
		}
		
		char nuevoId[T];
		int nroHijo = 1;
		
		// Buscar el último hermano para determinar el número de hijo
		if (versionPadre->primerHijo != NULL) {
			Version temp = versionPadre->primerHijo;
			while (temp->sigHermano != NULL) {
				temp = temp->sigHermano;
				nroHijo++;
			}
			nroHijo++; // El número del nuevo hijo
		}
		
		// Construir el nuevo ID (Ej: "1.2" si el padre es "1" y es el segundo hijo)
		snprintf(nuevoId, T, "%s.%d", versionPadre->idVersion, nroHijo);
		
		// 3. Verificar si el nuevo ID ya existe (aunque con la lógica de ID automático no debería pasar).
		if (existencia_Version(a->primeraVersion, nuevoId) != NULL) {
			cout << "ERROR: El ID de versión generado ('" << nuevoId << "') ya existe." << endl;
			return ERROR;
		}
		
		// 4. Crear la nueva versión
		Version nuevaV = new _version;
		strcpy(nuevaV->idVersion, nuevoId); // Usamos el ID generado
		nuevaV->padre = versionPadre;
		nuevaV->primerHijo = NULL;
		nuevaV->sigHermano = NULL;
		nuevaV->textoVersion = NULL; // Inicialmente sin texto
		
		// 5. Enlazar el nuevo nodo en el árbol de versiones (como hijo o hermano)
		if (versionPadre->primerHijo == NULL) {
			// Es el primer hijo
			versionPadre->primerHijo = nuevaV;
		} else {
			// Enlazar como último hermano
			Version temp = versionPadre->primerHijo;
			while (temp->sigHermano != NULL) {
				temp = temp->sigHermano;
			}
			temp->sigHermano = nuevaV;
		}
		
		// 6. Copiar el texto de la versión padre a la nueva versión
		lineas lineaActualPadre = versionPadre->textoVersion;
		lineas *punteroAlUltimo = &(nuevaV->textoVersion); // Puntero al final de la lista de la nueva versión (al principio es &nuevaV->textoVersion)
		
		while (lineaActualPadre != NULL) {
			// Crear un nuevo nodo de línea
			lineas nuevaLinea = new _linea;
			nuevaLinea->numero = lineaActualPadre->numero;
			// *IMPORTANTE:* Copiar la cadena de texto de la línea
			// Como 'textoLinea' ya es una 'cadena' (char*), necesitamos asegurarnos de que el constructor o la asignación
			// cree un nuevo arreglo de char para evitar que ambas versiones compartan la misma memoria.
			// Asumiendo que has corregido el constructor de _linea (ver sección 2):
			strcpy(nuevaLinea->textoLinea, lineaActualPadre->textoLinea);
			
			nuevaLinea->sig = NULL;
			
			// Enlazar el nuevo nodo al final de la lista de la nueva versión
			*punteroAlUltimo = nuevaLinea;
			punteroAlUltimo = &(nuevaLinea->sig);
			
			lineaActualPadre = lineaActualPadre->sig;
		}
		
		cout << "Versión '" << nuevoId << "' creada exitosamente como hijo de '" << versionPadre->idVersion << "'." << endl;
		return OK;
	}
TipoRet borrarVersion(Archivo &a, cadena version){
	// 1. Verificaciones iniciales
	if (a == NULL || version == NULL || strlen(version) == 0) {
		return ERROR;
	}
	
	// No se puede borrar la versión raíz
	if (strcmp(version, "1") == 0) {
		cout << "ERROR: No se puede borrar la versión raíz ('1')." << endl;
		return ERROR;
	}
	
	// 2. Buscar la versión a borrar (v)
	Version v = existencia_Version(a->primeraVersion, version);
	if (v == NULL) {
		cout << "ERROR: No existe la versión '" << version << "'." << endl;
		return ERROR;
	}
	
	// 3. Verificar si tiene hijos
	if (v->primerHijo != NULL) {
		cout << "ERROR: La versión '" << version << "' no se puede borrar porque tiene subversiones dependientes." << endl;
		return ERROR;
	}
	
	// 4. Encontrar el nodo padre para desenlazar
	Version padre = encontrarPadre(a->primeraVersion, version);
	
	if (padre == NULL) {
		// Esto no debería pasar si "1" no se puede borrar, pero es una buena verificación.
		cout << "ERROR interno: No se pudo encontrar el padre de la versión a borrar." << endl;
		return ERROR;
	}
	
	// 5. Desenlazar la versión
	
	// Caso A: Es el primer hijo del padre
	if (padre->primerHijo == v) {
		padre->primerHijo = v->sigHermano;
	} 
	// Caso B: Es un hermano
	else {
		Version temp = padre->primerHijo;
		while (temp != NULL && temp->sigHermano != v) {
			temp = temp->sigHermano;
		}
		// Si lo encontró, temp apunta al hermano anterior
		if (temp != NULL) {
			temp->sigHermano = v->sigHermano;
		}
	}
	
	// 6. Liberar la memoria del nodo y sus líneas
	liberarVersion(v);
	
	cout << "Versión borrada exitosamente." << endl;
	return OK;
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

