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
	// 1. Verificaci�n de par�metros b�sicos
	if (a == NULL || 	version == NULL || strlen(version) == 0) {
		return ERROR;
	}
	
	// --- MANEJO ESPECIAL PARA LA VERSI�N RA�Z "1" ---
	if (a->primeraVersion == NULL) {
		if (strcmp(version, "1") != 0) {
			cout << "ERROR: El archivo no tiene versiones. La primera debe ser '1'." << endl;
			return ERROR;
		}
		
		// Creaci�n de la versi�n ra�z "1" (como se explic� en el paso anterior)
		Version nuevaV = new _version;
		strcpy(nuevaV->idVersion, "1");
		nuevaV->primerHijo = NULL;
		nuevaV->sigHermano = NULL;
		nuevaV->padre = NULL;
		nuevaV->textoVersion = NULL;
		
		a->primeraVersion = nuevaV;
		cout << "Versi�n ra�z '1' inicializada exitosamente." << endl;
		return OK;
	}
	// ------------------------------------------------------------------
	
	// 2. Verificar que el nuevo ID no exista (para versiones > "1")
	if (existencia_Version(a->primeraVersion, version) != NULL) {
		cout << "ERROR: La versi�n '" << version << "' ya existe." << endl;
		return ERROR;
	}
	
	// 3. Determinar la Versi�n Base/Padre y validar la secuencia
	
	cadena idVersionBase = NULL; // Versi�n de la que copiaremos el texto
	Version versionBase = NULL;
	
	char *punto = strrchr(version, '.');
	
	if (punto != NULL) {
		// A. ES UNA SUBVERSI�N (ej. "2.1")
		
		// a. Extraer el ID del padre (ej. "2")
		idVersionBase = new char[T]; // Usamos T para asegurarnos de que el buffer sea suficiente
		strncpy(idVersionBase, version, punto - version);
		idVersionBase[punto - version] = '\0'; // Terminador nulo
		
		// b. Extraer el n�mero de secuencia (ej. "1" de "2.1")
		int nroSecuencia = atoi(punto + 1); 
		
		// La versi�n base debe existir
		versionBase = existencia_Version(a->primeraVersion, idVersionBase);
		
		if (versionBase == NULL) {
			cout << "ERROR: La versi�n base '" << idVersionBase << "' no existe para crear '" << version << "'." << endl;
			delete[] idVersionBase;
			return ERROR;
		}
		
		// c. CONTROL DE SECUENCIALIDAD DE SUBVERSIONES
		if (nroSecuencia <= 0) {
			cout << "ERROR: El n�mero de secuencia debe ser positivo (ej. '1.1', '2.2')." << endl;
			delete[] idVersionBase;
			return ERROR;
		}
		
		if (nroSecuencia > 1) {
			// ... (restablece variables)
			char idAnterior[T]; 
			char nro[10]; // Buffer para el n�mero 'nroSecuencia - 1' (ej. '1')
			
			// PASO 1: Copiar la base (ej. "1")
			strcpy(idAnterior, idVersionBase); 
			
			// PASO 2: Agregar el punto (idAnterior ahora es "1.")
			strcat(idAnterior, "."); 
			
			// PASO 3: Convertir el n�mero (Secuencia-1, ej. 1) a cadena (nro es "1")
			itoa_simple(nroSecuencia - 1, nro);
			
			// PASO 4: Agregar el n�mero (idAnterior ahora es "1.1")
			strcat(idAnterior, nro);
			
			if (existencia_Version(a->primeraVersion, idAnterior) == NULL) {
				cout << "ERROR: No se puede crear '" << version << "'. Primero debe existir la versi�n '" << idAnterior << "'." << endl;
				delete[] idVersionBase;
				return ERROR;
			}
		}
		// *Si es nroSecuencia == 1, no necesita la anterior (es la primera subversi�n).
		
	} else {
		// B. ES UNA VERSI�N PRINCIPAL (ej. "2", "3")
		
		int nroSecuencia = atoi(version);
		
		// La base para copiar el texto es siempre la versi�n ra�z "1"
		idVersionBase = new char[2];
		strcpy(idVersionBase, "1"); 
		versionBase = a->primeraVersion; 
		
		// CONTROL DE SECUENCIALIDAD DE VERSIONES PRINCIPALES
		if (nroSecuencia <= 1) {
			// Esto ya se maneja en el caso especial de la ra�z.
			cout << "ERROR: Versi�n principal inv�lida. Debe ser 2 o superior." << endl;
			delete[] idVersionBase;
			return ERROR;
		}
		
		// Verificar que la versi�n principal anterior (ej. "2" requiere que exista "1")
		char idAnterior[T];
		snprintf(idAnterior, T, "%d", nroSecuencia - 1);
		
		if (existencia_Version(a->primeraVersion, idAnterior) == NULL) {
			cout << "ERROR: No se puede crear '" << version << "'. Primero debe existir la versi�n '" << idAnterior << "'." << endl;
			delete[] idVersionBase;
			return ERROR;
		}
	}
	
	// 4. Crear la nueva versi�n (sin cambios en esta parte, usa version y versionBase)
	Version nuevaV = new _version;
	strcpy(nuevaV->idVersion, version);
	nuevaV->primerHijo = NULL;
	nuevaV->sigHermano = NULL;
	nuevaV->textoVersion = NULL;
	
	// 5. Enlazar el nuevo nodo (L�gica de hijos/hermanos previamente definida)
	if (punto != NULL) {
		// Subversi�n (ej. "2.1"): Se enlaza como hijo de 'versionBase' ("2")
		// ... (L�gica de enlazar como hijo/hermano de versionBase->primerHijo)
		nuevaV->padre = versionBase;
		
		if (versionBase->primerHijo == NULL) {
			versionBase->primerHijo = nuevaV;
		} else {
			Version temp = versionBase->primerHijo;
			while (temp->sigHermano != NULL) {
				temp = temp->sigHermano;
			}
			temp->sigHermano = nuevaV;
		}
	} else {
		// Versi�n principal (ej. "2"): Se enlaza como hermana de la �ltima versi�n principal
		// ... (L�gica de enlazar como hermana de a->primeraVersion)
		nuevaV->padre = NULL; 
		
		Version temp = a->primeraVersion;
		while (temp->sigHermano != NULL) {
			temp = temp->sigHermano;
		}
		temp->sigHermano = nuevaV;
	}
	
	// 6. Copiar el texto (L�gica de copia de l�neas)
	lineas lineaActualBase = versionBase->textoVersion;
	lineas *punteroAlUltimo = &(nuevaV->textoVersion);
	
	while (lineaActualBase != NULL) {
		lineas nuevaLinea = new _linea;
		nuevaLinea->numero = lineaActualBase->numero;
		
		// Asignar memoria y copiar
		nuevaLinea->textoLinea = new char[strlen(lineaActualBase->textoLinea) + 1];
		strcpy(nuevaLinea->textoLinea, lineaActualBase->textoLinea);
		
		nuevaLinea->sig = NULL;
		
		*punteroAlUltimo = nuevaLinea;
		punteroAlUltimo = &(nuevaLinea->sig);
		
		lineaActualBase = lineaActualBase->sig;
	}
	
	// Liberar la memoria temporal del ID base
	if (idVersionBase != NULL) {
		delete[] idVersionBase;
	}
	
	cout << "Versi�n '" << version << "' creada exitosamente." << endl;
	return OK;
}
TipoRet borrarVersion(Archivo &a, cadena version){
// 1. Verificaciones iniciales
		if (a == NULL || version == NULL || strlen(version) == 0) {
			return ERROR;
	}
		
		// No se puede borrar la versi�n ra�z
		if (strcmp(version, "1") == 0) {
			cout << "ERROR: No se puede borrar la versi�n ra�z ('1')." << endl;
			return ERROR;
		}
		
		// 2. Buscar la versi�n a borrar (v)
		Version v = existencia_Version(a->primeraVersion, version);
		if (v == NULL) {
			cout << "ERROR: No existe la versi�n '" << version << "'." << endl;
			return ERROR;
		}
		
		// 3. Verificar si tiene hijos
		if (v->primerHijo != NULL) {
			cout << "ERROR: La versi�n '" << version << "' no se puede borrar porque tiene subversiones dependientes." << endl;
			return ERROR;
		}
		
		// 4. Encontrar el nodo padre para desenlazar
		// NOTA: Para versiones principales (ej. "2", "3", etc.), el padre ser� la �ltima versi�n principal (ej. "1")
		//       o la ra�z misma (a->primeraVersion) si no tiene padre expl�cito.

		
		// Si la versi�n es hermana de la ra�z, 'encontrarPadre' podr�a devolver la versi�n anterior ("1" para "2").
		// Para la re-numeraci�n, necesitamos el nodo antes de 'v' o su padre directo.
		
		Version nodoAnterior = NULL;
		Version nodoPadre = NULL;
		
		// L�gica para encontrar el padre directo y el nodo anterior:
		if (v->padre != NULL) {
			// Es una subversi�n (1.2, padre es 1)
			nodoPadre = v->padre;
			nodoAnterior = nodoPadre->primerHijo;
			if (nodoAnterior != v) {
				while (nodoAnterior != NULL && nodoAnterior->sigHermano != v) {
					nodoAnterior = nodoAnterior->sigHermano;
				}
			} else {
				nodoAnterior = NULL; // Es el primer hijo
			}
		} else {
			// Es una versi�n principal (
			// nodoPadre = a->primeraVersion (usamos la ra�z para iterar)
			nodoPadre = a->primeraVersion; 
			nodoAnterior = nodoPadre;
			if (nodoAnterior != v) {
				while (nodoAnterior != NULL && nodoAnterior->sigHermano != v) {
					nodoAnterior = nodoAnterior->sigHermano;
				}
			} else {
				nodoAnterior = NULL; // No deber�a ser la ra�z "1", ya lo verificamos arriba.
			}
			
		}
		
		// 5. Desenlazar la versi�n
		
		// Caso A: Es el primer nodo de la lista de hermanos/hijos
		if (nodoAnterior == NULL) {
			// Si es subversi�n:
			if (nodoPadre->primerHijo == v) {
				nodoPadre->primerHijo = v->sigHermano;
			} else {
				// Es versi�n principal:
				// Asumiremos que si nodoAnterior es NULL, y no es hijo, es un caso de error o la versi�n "1" (ya excluida).
				return ERROR; 
			}
		} else { 
			// Caso B: Es un hermano
			nodoAnterior->sigHermano = v->sigHermano;
		}
		
		// 6. RE-NUMERACI�N: Verificar y re-numerar los hermanos siguientes si es una subversi�n
		
		char *punto = strrchr(version, '.');
		Version siguiente = v->sigHermano; // El nodo que toma el lugar de 'v'
		
		if (punto != NULL) {
			// Solo re-numeramos si es una subversi�n (ej. borramos 1.2, queremos que 1.3 sea 1.2)
			
			// a. Extraer el prefijo del padre 
			char idPrefijo[T];
			size_t len_prefijo = punto - version;
			strncpy(idPrefijo, version, len_prefijo);
			idPrefijo[len_prefijo] = '\0';
			
			// b. Obtener el n�mero de secuencia del nodo borrado
			int nroSecuenciaInicial = atoi(punto + 1); // Este es el primer n�mero que debe usarse 
			
			// c. Recorrer los hermanos restantes y re-numerar
			while (siguiente != NULL) {
				
				//  CONSTRUCCI�N DEL NUEVO ID 
				
				char nuevoId[T];
				char nro[10]; // Buffer para el n�mero de secuencia
				
				// 1. Convertir la secuencia actual (ej. 2) a cadena (nro es "2")
				itoa_simple(nroSecuenciaInicial, nro);
				
				// 2. Copiar el prefijo (ej. "1")
				strcpy(nuevoId, idPrefijo); 
				
				// 3. Agregar el punto (nuevoId es "1.")
				strcat(nuevoId, "."); 
				
				// 4. Agregar el n�mero de secuencia (nuevoId es "1.2")
				strcat(nuevoId, nro);
				
				// FIN DE CONSTRUCCI�N DEL NUEVO ID 
				
				// IMPORTANTE: Liberar la memoria del ID antiguo antes de reasignar
				if (siguiente->idVersion != NULL) {
					delete[] siguiente->idVersion;
				}
				siguiente->idVersion = new char[T]; // Reasignar memoria para el nuevo ID
				
				// Copiar el nuevo ID construido
				strcpy(siguiente->idVersion, nuevoId);
				
				nroSecuenciaInicial++; // Incrementar para el siguiente hermano (1.3 -> 1.4, se convierte a 1.3)
				siguiente = siguiente->sigHermano;
			}
		}
		
		// 7. Liberar la memoria del nodo borrado
		liberarVersion(v);
		
		cout << "Versi�n borrada exitosamente." << endl;
		return OK;
}

TipoRet mostrarVersiones(Archivo a){
	int espaciador = 5; 
	if(a == nullptr){
		cout << "ERROR : Archivo no existente" << endl;
		return ERROR;
	}else{
		cout << a->nombre << endl;
		if(a->primeraVersion != nullptr){
			mostrarArbol(a->primeraVersion,espaciador);
			return OK;
		}else{
			cout << "No hay versiones creadas" << endl;
			return OK;
		}
	}
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
		cout << "ERROR: La versi�n tiene subversiones, no es editable." << endl;
		return ERROR;
	}
	lineas auxLineas = aux->textoVersion;
	unsigned int x=0;
	while(auxLineas != NULL){
		x++;
		auxLineas=auxLineas->sig;
	}
	
	if (nroLinea < 1 || nroLinea > x+1){
		cout << "ERROR: N�mero de l�nea inv�lido." << endl;
		return ERROR;
	}
	//paso todas las pruebas 
	lineas aInsetar = new _linea;
	strcpy(aInsetar->textoLinea, linea);
	aInsetar->numero = nroLinea;
	aInsetar->sig = NULL;
	//registro de los cambios
	cambio registros = new _cambio;
	registros->numero = nroLinea;
	strcpy(registros->textoLinea,linea);
	strcpy(registros->tipo_Operacion,"IL");
	cambio recorrer = aux->tipo_cambio;
	if(recorrer == nullptr){
		aux->tipo_cambio = registros;
	}else{
		while(recorrer->sig != nullptr){
			recorrer = recorrer->sig;
		}
		recorrer->sig = registros;
	}
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
		cout << "ERROR: No existe la version indicada." << endl;
		return ERROR;
	}
	
	// No se puede borrar si tiene subversiones
	if (v->primerHijo != NULL) {
		cout << "ERROR: La version tiene subversiones, no es editable." << endl;
		return ERROR;
	}
	
	// Si no hay lineas, nada que borrar
	if (v->textoVersion == NULL) {
		cout << "ERROR: La version no contiene lineas." << endl;
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
		cout << "ERROR: Numero de linea invalido." << endl;
		return ERROR;
	}
	
	// Eliminar la linea correspondiente
	lineas actual = v->textoVersion;
	lineas anterior = NULL;
	
	for (unsigned int i = 1; i < nroLinea; i++) {
		anterior = actual;
		actual = actual->sig;
	}
	//registro de los cambios
	cambio registros = new _cambio; // Nota: Quit� todos los __fpurge(stdin);
	registros->numero = nroLinea;
	strcpy(registros->tipo_Operacion,"BL");
	
	// * �SOLUCI�N! Copiar el texto de la l�nea a borrar *
	// El puntero 'actual' tiene la informaci�n correcta en este punto.
	strcpy(registros->textoLinea, actual->textoLinea); 
	
	// Enlazar el registro de cambio
	cambio recorrer = v->tipo_cambio;
	if(recorrer == nullptr){
		v->tipo_cambio = registros;
	}else{
		while(recorrer->sig != nullptr){
			recorrer = recorrer->sig;
		}
		recorrer->sig = registros;
	}
	
	// Caso 1: borrar la primera linea
	if (anterior == NULL) {
		v->textoVersion = actual->sig;
	} else { // Caso 2: borrar una linea intermedia o final
		anterior->sig = actual->sig;
	}
	
	// Liberaci�n de memoria de la l�nea borrada
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
	if(a == NULL || version == nullptr){
		cout << "Error:No existe la version " << version << "en el archivo" <<endl;
		return ERROR;
	}
	Version v = existencia_Version(a->primeraVersion,version);
	if (v == nullptr){
		cout << " Error:Version no existente" << endl;
		return ERROR;
	}
	cambio aux = v->tipo_cambio;
	while(aux != nullptr){
		cout << aux->tipo_Operacion <<  "-" << aux->numero << "  " << aux->textoLinea << endl;
		aux = aux->sig;
	}
	return OK;
}

TipoRet BorrarArchivo(Archivo &a){
	a = eliminarInfoArchivo(a);
	cout<<"El archivo fue borrado con exito Gracias por usarnos"<<endl;
	return OK;
}

TipoRet versionIndependiente(Archivo &a, cadena version){
	return NO_IMPLEMENTADO;
}
