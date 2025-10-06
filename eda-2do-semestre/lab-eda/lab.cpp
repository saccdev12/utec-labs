#include "lab-proto.h"
#include "lab-struct.h"
#include <iostream>
#include <cstring>

using namespace std;

// Implementación de Linea
Linea::Linea(const char* txt, unsigned int num) : numero(num), siguiente(nullptr) {
    texto = new char[strlen(txt) + 1];
    strcpy(texto, txt);
}

Linea::~Linea() {
    delete[] texto;
}

// Implementación de Modificacion
Modificacion::Modificacion(char t, unsigned int num, const char* txt) : 
    tipo(t), numeroLinea(num), siguiente(nullptr) {
    if (txt) {
        texto = new char[strlen(txt) + 1];
        strcpy(texto, txt);
    } else {
        texto = nullptr;
    }
}

Modificacion::~Modificacion() {
    delete[] texto;
}

// Implementación de Version
Version::Version(const char* versionId, Version* parent) : 
    padre(parent), primeraSubversion(nullptr), siguienteVersion(nullptr), numLineas(0) {
    id = new char[strlen(versionId) + 1];
    strcpy(id, versionId);
    lineas = nullptr;
    modificaciones = nullptr;
}

Version::~Version() {
    delete[] id;
    
    // Liberar líneas
    Linea* actualLinea = lineas;
    while (actualLinea) {
        Linea* temp = actualLinea;
        actualLinea = actualLinea->siguiente;
        delete temp;
    }
    
    // Liberar modificaciones
    Modificacion* actualMod = modificaciones;
    while (actualMod) {
        Modificacion* temp = actualMod;
        actualMod = actualMod->siguiente;
        delete temp;
    }
    
    // Liberar subversiones recursivamente
    Version* actualSub = primeraSubversion;
    while (actualSub) {
        Version* temp = actualSub;
        actualSub = actualSub->siguienteVersion;
        delete temp;
    }
}

void Version::insertarLinea(unsigned int nroLinea, const char* texto) {
    Linea* nuevaLinea = new Linea(texto, nroLinea);
    
    if (!lineas || nroLinea == 1) {
        nuevaLinea->siguiente = lineas;
        lineas = nuevaLinea;
    } else {
        Linea* actual = lineas;
        Linea* anterior = nullptr;
        
        while (actual && actual->numero < nroLinea) {
            anterior = actual;
            actual = actual->siguiente;
        }
        
        if (anterior) {
            anterior->siguiente = nuevaLinea;
        }
        nuevaLinea->siguiente = actual;
    }
    
    // Renumerar líneas
    Linea* temp = lineas;
    unsigned int contador = 1;
    while (temp) {
        temp->numero = contador++;
        temp = temp->siguiente;
    }
    
    numLineas++;
}

void Version::borrarLinea(unsigned int nroLinea) {
    if (!lineas) return;
    
    Linea* actual = lineas;
    Linea* anterior = nullptr;
    
    while (actual && actual->numero != nroLinea) {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if (!actual) return;
    
    if (anterior) {
        anterior->siguiente = actual->siguiente;
    } else {
        lineas = actual->siguiente;
    }
    
    delete actual;
    numLineas--;
    
    // Renumerar líneas restantes
    actual = lineas;
    unsigned int contador = 1;
    while (actual) {
        actual->numero = contador++;
        actual = actual->siguiente;
    }
}

void Version::agregarModificacion(char tipo, unsigned int nroLinea, const char* texto) {
    Modificacion* nuevaMod = new Modificacion(tipo, nroLinea, texto);
    nuevaMod->siguiente = modificaciones;
    modificaciones = nuevaMod;
}

Linea* Version::obtenerLinea(unsigned int nroLinea) {
    Linea* actual = lineas;
    while (actual && actual->numero != nroLinea) {
        actual = actual->siguiente;
    }
    return actual;
}

void Version::construirTextoCompleto() {
    // Si tiene padre, copiar su texto primero
    if (padre) {
        // Implementar copia del texto del padre
    }
    
    // Aplicar modificaciones
    // Implementar aplicación de modificaciones
}

// Implementación de Archivo
Archivo::Archivo(const char* nom) : primeraVersion(nullptr), contadorVersiones(0) {
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

Archivo::~Archivo() {
    delete[] nombre;
    
    Version* actual = primeraVersion;
    while (actual) {
        Version* temp = actual;
        actual = actual->siguienteVersion;
        delete temp;
    }
}

Version* Archivo::buscarVersion(const char* versionId) {
    return buscarVersionRecursivo(primeraVersion, versionId);
}

Version* Archivo::buscarVersionRecursivo(Version* actual, const char* versionId) {
    if (!actual) return nullptr;
    
    if (strcmp(actual->id, versionId) == 0) {
        return actual;
    }
    
    // Buscar en hermanos
    Version* encontrado = buscarVersionRecursivo(actual->siguienteVersion, versionId);
    if (encontrado) return encontrado;
    
    // Buscar en subversiones
    return buscarVersionRecursivo(actual->primeraSubversion, versionId);
}

bool Archivo::versionTieneSubversiones(Version* version) {
    return version && version->primeraSubversion != nullptr;
}

void Archivo::reordenarVersiones(Version* padre) {
    // Implementar reordenamiento de versiones hermanas
}

// Implementación de funciones principales
Archivo* CrearArchivo(char* nombre) {
    return new Archivo(nombre);
}

TipoRet BorrarArchivo(Archivo* &a) {
    if (!a) return ERROR;
    
    delete a;
    a = nullptr;
    return OK;
}

TipoRet CrearVersion(Archivo* &a, char* version) {
    if (!a || !version) return ERROR;
    
    // Verificar formato válido
    if (!validarFormatoVersion(version)) {
        cout << "ERROR: Formato de versión inválido" << endl;
        return ERROR;
    }
    
    // Buscar si ya existe
    Version* versionExistente = a->buscarVersion(version);
    if (versionExistente) {
        // Implementar inserción con corrimiento
        cout << "ERROR: Versión ya existe - funcionalidad no implementada" << endl;
        return NO_IMPLEMENTADA;
    }
    
    // Crear nueva versión
    Version* nuevaVersion = new Version(version);
    
    // Si es versión de primer nivel
    if (strchr(version, '.') == nullptr) {
        nuevaVersion->siguienteVersion = a->primeraVersion;
        a->primeraVersion = nuevaVersion;
    } else {
        // Buscar padre
        char padre[100];
        obtenerPadreVersion(version, padre);
        Version* versionPadre = a->buscarVersion(padre);
        
        if (!versionPadre) {
            delete nuevaVersion;
            cout << "ERROR: Versión padre no existe" << endl;
            return ERROR;
        }
        
        nuevaVersion->padre = versionPadre;
        nuevaVersion->siguienteVersion = versionPadre->primeraSubversion;
        versionPadre->primeraSubversion = nuevaVersion;
    }
    
    a->contadorVersiones++;
    return OK;
}

TipoRet BorrarVersion(Archivo* &a, char* version) {
    if (!a || !version) return ERROR;
    
    // Buscar versión
    Version* versionAEliminar = a->buscarVersion(version);
    if (!versionAEliminar) {
        cout << "ERROR: Versión no existe" << endl;
        return ERROR;
    }
    
    // Implementar eliminación con reordenamiento
    cout << "ERROR: Funcionalidad no implementada completamente" << endl;
    return NO_IMPLEMENTADA;
}

TipoRet MostrarVersiones(Archivo* a) {
    if (!a) return ERROR;
    
    cout << a->nombre << endl << endl;
    
    if (!a->primeraVersion) {
        cout << "No hay versiones creadas" << endl;
        return OK;
    }
    
    // Implementar mostrar jerárquico
    cout << "ERROR: Funcionalidad de mostrar versiones no implementada completamente" << endl;
    return NO_IMPLEMENTADA;
}

TipoRet InsertarLinea(Archivo* &a, char* version, char* linea, unsigned int nroLinea) {
    if (!a || !version || !linea) return ERROR;
    
    Version* versionObj = a->buscarVersion(version);
    if (!versionObj) {
        cout << "ERROR: Versión no existe" << endl;
        return ERROR;
    }
    
    if (a->versionTieneSubversiones(versionObj)) {
        cout << "ERROR: La versión tiene subversiones" << endl;
        return ERROR;
    }
    
    if (nroLinea < 1 || nroLinea > versionObj->numLineas + 1) {
        cout << "ERROR: Número de línea inválido" << endl;
        return ERROR;
    }
    
    versionObj->insertarLinea(nroLinea, linea);
    versionObj->agregarModificacion('I', nroLinea, linea);
    
    return OK;
}

TipoRet BorrarLinea(Archivo* &a, char* version, unsigned int nroLinea) {
    if (!a || !version) return ERROR;
    
    Version* versionObj = a->buscarVersion(version);
    if (!versionObj) {
        cout << "ERROR: Versión no existe" << endl;
        return ERROR;
    }
    
    if (a->versionTieneSubversiones(versionObj)) {
        cout << "ERROR: La versión tiene subversiones" << endl;
        return ERROR;
    }
    
    if (nroLinea < 1 || nroLinea > versionObj->numLineas) {
        cout << "ERROR: Número de línea inválido" << endl;
        return ERROR;
    }
    
    versionObj->borrarLinea(nroLinea);
    versionObj->agregarModificacion('B', nroLinea);
    
    return OK;
}

TipoRet MostrarTexto(Archivo* a, char* version) {
    if (!a || !version) return ERROR;
    
    Version* versionObj = a->buscarVersion(version);
    if (!versionObj) {
        cout << "ERROR: Versión no existe" << endl;
        return ERROR;
    }
    
    cout << a->nombre << " - " << version << endl << endl;
    
    if (!versionObj->lineas) {
        cout << "No contiene líneas" << endl;
        return OK;
    }
    
    Linea* actual = versionObj->lineas;
    while (actual) {
        cout << actual->numero << "\t" << actual->texto << endl;
        actual = actual->siguiente;
    }
    
    return OK;
}

TipoRet MostrarCambios(Archivo* a, char* version) {
    if (!a || !version) return ERROR;
    
    Version* versionObj = a->buscarVersion(version);
    if (!versionObj) {
        cout << "ERROR: Versión no existe" << endl;
        return ERROR;
    }
    
    cout << a->nombre << " - " << version << endl << endl;
    
    if (!versionObj->modificaciones) {
        cout << "No se realizaron modificaciones" << endl;
        return OK;
    }
    
    Modificacion* actual = versionObj->modificaciones;
    while (actual) {
        if (actual->tipo == 'I') {
            cout << "IL\t" << actual->numeroLinea << "\t" << (actual->texto ? actual->texto : "") << endl;
        } else {
            cout << "BL\t" << actual->numeroLinea << endl;
        }
        actual = actual->siguiente;
    }
    
    return OK;
}

TipoRet Iguales(Archivo* a, char* version1, char* version2, bool &iguales) {
    if (!a || !version1 || !version2) return ERROR;
    
    Version* v1 = a->buscarVersion(version1);
    Version* v2 = a->buscarVersion(version2);
    
    if (!v1 || !v2) {
        cout << "ERROR: Una o ambas versiones no existen" << endl;
        return ERROR;
    }
    
    // Implementar comparación completa
    iguales = false;
    cout << "ERROR: Comparación de versiones no implementada completamente" << endl;
    return NO_IMPLEMENTADA;
}

TipoRet VersionIndependiente(Archivo* &a, char* version) {
    cout << "ERROR: Versión independiente no implementada" << endl;
    return NO_IMPLEMENTADA;
}

// Funciones auxiliares
bool validarFormatoVersion(const char* version) {
    if (!version || strlen(version) == 0) return false;
    if (version[0] == '.' || version[strlen(version)-1] == '.') return false;
    
    for (unsigned int i = 0; i < strlen(version); i++) {
        if (!isdigit(version[i]) && version[i] != '.') return false;
    }
    
    return true;
}

void obtenerPadreVersion(const char* version, char* padre) {
    const char* lastDot = strrchr(version, '.');
    if (!lastDot) {
        padre[0] = '\0';
        return;
    }
    
    strncpy(padre, version, lastDot - version);
    padre[lastDot - version] = '\0';
}