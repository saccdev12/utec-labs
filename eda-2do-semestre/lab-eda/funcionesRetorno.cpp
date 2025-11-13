#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

#include "estructuras.h"
#include "prototipos.h"

void muestroRetorno(TipoRet retorno) {
    switch (retorno) {
        case OK:
            cout << "OK" << endl;
            break;
        case ERROR:
            cout << "ERROR" << endl;
            break;
        case NO_IMPLEMENTADO:
            cout << "NO IMPLEMENTADA" << endl;
            break;
    }
}

void help() {
    cout << "\n=== COMANDOS DISPONIBLES ===" << endl;
    cout << "CrearVersion(archivo, \"version\")" << endl;
    cout << "BorrarVersion(archivo, \"version\")" << endl;
    cout << "MostrarVersiones(archivo)" << endl;
    cout << "InsertarLinea(archivo, \"version\", \"texto\", numero_linea)" << endl;
    cout << "BorrarLinea(archivo, \"version\", numero_linea)" << endl;
    cout << "MostrarTexto(archivo, \"version\")" << endl;
    cout << "MostrarCambios(archivo, \"version\")" << endl;
    cout << "Iguales(archivo, \"version1\", \"version2\")" << endl;
    cout << "VersionIndependiente(archivo, \"version\")" << endl;
    cout << "ayuda - Muestra esta ayuda" << endl;
    cout << "limpiar - Limpia la pantalla" << endl;
    cout << "salir - Termina el programa" << endl;
    cout << "=============================" << endl;
}

TipoRet crearVersion(Archivo &a, cadena version) {
    if (a == nullptr || version == nullptr || !validarFormatoVersion(version)) {
        cout << "ERROR: Parámetros inválidos o formato de versión incorrecto" << endl;
        return ERROR;
    }
    
    if (existencia_Version(a->primeraVersion, version) != nullptr) {
        cout << "ERROR: La versión '" << version << "' ya existe." << endl;
        return ERROR;
    }
    
    // Crear primera versión (1)
    if (a->primeraVersion == nullptr) {
        if (strcmp(version, "1") != 0) {
            cout << "ERROR: La primera versión debe ser '1'" << endl;
            return ERROR;
        }
        
        Version nuevaV = new _version;
        nuevaV->idVersion = new char[strlen(version) + 1];
        strcpy(nuevaV->idVersion, version);
        nuevaV->primerHijo = nullptr;
        nuevaV->sigHermano = nullptr;
        nuevaV->padre = nullptr;
        nuevaV->textoVersion = nullptr;
        nuevaV->tipo_cambio = nullptr;
        
        a->primeraVersion = nuevaV;
        cout << "Versión '" << version << "' creada exitosamente" << endl;
        return OK;
    }
    
    // Verificar padre existe para subversiones
    char *punto = strrchr(version, '.');
    if (punto != nullptr) {
        cadena idPadre = new char[punto - version + 1];
        strncpy(idPadre, version, punto - version);
        idPadre[punto - version] = '\0';
        
        Version padre = existencia_Version(a->primeraVersion, idPadre);
        if (padre == nullptr) {
            cout << "ERROR: La versión padre '" << idPadre << "' no existe" << endl;
            delete[] idPadre;
            return ERROR;
        }
        delete[] idPadre;
    }
    
    // Crear nueva versión
    Version nuevaV = new _version;
    nuevaV->idVersion = new char[strlen(version) + 1];
    strcpy(nuevaV->idVersion, version);
    nuevaV->primerHijo = nullptr;
    nuevaV->sigHermano = nullptr;
    nuevaV->textoVersion = nullptr;
    nuevaV->tipo_cambio = nullptr;
    
    // Enlazar según tipo de versión
    if (punto != nullptr) {
        cadena idPadre = new char[punto - version + 1];
        strncpy(idPadre, version, punto - version);
        idPadre[punto - version] = '\0';
        
        Version padre = existencia_Version(a->primeraVersion, idPadre);
        nuevaV->padre = padre;
        
        if (padre->primerHijo == nullptr) {
            padre->primerHijo = nuevaV;
        } else {
            Version temp = padre->primerHijo;
            while (temp->sigHermano != nullptr) {
                temp = temp->sigHermano;
            }
            temp->sigHermano = nuevaV;
        }
        delete[] idPadre;
    } else {
        nuevaV->padre = nullptr;
        Version temp = a->primeraVersion;
        while (temp->sigHermano != nullptr) {
            temp = temp->sigHermano;
        }
        temp->sigHermano = nuevaV;
    }
    
    cout << "Versión '" << version << "' creada exitosamente" << endl;
    return OK;
}

TipoRet borrarVersion(Archivo &a, cadena version) {
    if (a == nullptr || version == nullptr) {
        return ERROR;
    }
    
    if (strcmp(version, "1") == 0) {
        cout << "ERROR: No se puede borrar la versión raíz '1'" << endl;
        return ERROR;
    }
    
    Version v = existencia_Version(a->primeraVersion, version);
    if (v == nullptr) {
        cout << "ERROR: No existe la versión '" << version << "'" << endl;
        return ERROR;
    }
    
    if (v->primerHijo != nullptr) {
        cout << "ERROR: La versión tiene subversiones, no se puede borrar" << endl;
        return ERROR;
    }
    
    // Encontrar y desenlazar
    Version padre = v->padre;
    if (padre != nullptr) {
        if (padre->primerHijo == v) {
            padre->primerHijo = v->sigHermano;
        } else {
            Version temp = padre->primerHijo;
            while (temp != nullptr && temp->sigHermano != v) {
                temp = temp->sigHermano;
            }
            if (temp != nullptr) {
                temp->sigHermano = v->sigHermano;
            }
        }
    } else {
        if (a->primeraVersion == v) {
            a->primeraVersion = v->sigHermano;
        } else {
            Version temp = a->primeraVersion;
            while (temp != nullptr && temp->sigHermano != v) {
                temp = temp->sigHermano;
            }
            if (temp != nullptr) {
                temp->sigHermano = v->sigHermano;
            }
        }
    }
    
    liberarVersion(v);
    cout << "Versión '" << version << "' borrada exitosamente" << endl;
    return OK;
}

TipoRet mostrarVersiones(Archivo a) {
    if (a == nullptr) {
        cout << "ERROR: Archivo no existente" << endl;
        return ERROR;
    }
    
    cout << a->nombre << endl << endl;
    
    if (a->primeraVersion != nullptr) {
        mostrarArbol(a->primeraVersion, 0);
        return OK;
    } else {
        cout << "No hay versiones creadas" << endl;
        return OK;
    }
}

TipoRet insertarLinea(Archivo &a, cadena version, cadena linea, unsigned int nroLinea) {
    if (a == nullptr || version == nullptr || linea == nullptr) {
        return ERROR;
    }
    
    Version aux = existencia_Version(a->primeraVersion, version);
    if (aux == nullptr) {
        cout << "No existe la versión" << endl;
        return ERROR;
    }
    
    if (aux->primerHijo != nullptr) {
        cout << "ERROR: La versión tiene subversiones, no es editable" << endl;
        return ERROR;
    }
    
    // Calcular cantidad de líneas
    lineas auxLineas = aux->textoVersion;
    unsigned int x = 0;
    while (auxLineas != nullptr) {
        x++;
        auxLineas = auxLineas->sig;
    }
    
    if (nroLinea < 1 || nroLinea > x + 1) {
        cout << "ERROR: Número de línea inválido" << endl;
        return ERROR;
    }
    
    // Crear nueva línea
    lineas aInsertar = new _linea;
    aInsertar->textoLinea = new char[strlen(linea) + 1];
    strcpy(aInsertar->textoLinea, linea);
    aInsertar->numero = nroLinea;
    aInsertar->sig = nullptr;
    
    // Registrar cambio
    cambio registro = new _cambio;
    registro->numero = nroLinea;
    registro->textoLinea = new char[strlen(linea) + 1];
    strcpy(registro->textoLinea, linea);
    registro->tipo_Operacion = new char[3];
    strcpy(registro->tipo_Operacion, "IL");
    registro->sig = nullptr;
    
    if (aux->tipo_cambio == nullptr) {
        aux->tipo_cambio = registro;
    } else {
        cambio temp = aux->tipo_cambio;
        while (temp->sig != nullptr) {
            temp = temp->sig;
        }
        temp->sig = registro;
    }
    
    // Insertar en lista
    if (aux->textoVersion == nullptr) {
        aux->textoVersion = aInsertar;
    } else if (nroLinea == 1) {
        aInsertar->sig = aux->textoVersion;
        aux->textoVersion = aInsertar;
    } else {
        lineas anterior = aux->textoVersion;
        for (unsigned int i = 1; i < nroLinea - 1; i++) {
            anterior = anterior->sig;
        }
        aInsertar->sig = anterior->sig;
        anterior->sig = aInsertar;
    }
    
    // Renumerar líneas
    lineas acomodador = aux->textoVersion;
    unsigned int contador = 1;
    while (acomodador != nullptr) {
        acomodador->numero = contador++;
        acomodador = acomodador->sig;
    }
    
    return OK;
}

TipoRet borrarLinea(Archivo &a, cadena version, unsigned int nroLinea) {
    if (a == nullptr || version == nullptr) {
        return ERROR;
    }
    
    Version v = existencia_Version(a->primeraVersion, version);
    if (v == nullptr) {
        cout << "ERROR: No existe la versión indicada" << endl;
        return ERROR;
    }
    
    if (v->primerHijo != nullptr) {
        cout << "ERROR: La versión tiene subversiones, no es editable" << endl;
        return ERROR;
    }
    
    if (v->textoVersion == nullptr) {
        cout << "ERROR: La versión no contiene líneas" << endl;
        return ERROR;
    }
    
    // Calcular total de líneas
    lineas aux = v->textoVersion;
    unsigned int total = 0;
    while (aux != nullptr) {
        total++;
        aux = aux->sig;
    }
    
    if (nroLinea < 1 || nroLinea > total) {
        cout << "ERROR: Número de línea inválido" << endl;
        return ERROR;
    }
    
    // Encontrar línea a borrar
    lineas actual = v->textoVersion;
    lineas anterior = nullptr;
    
    for (unsigned int i = 1; i < nroLinea; i++) {
        anterior = actual;
        actual = actual->sig;
    }
    
    // Registrar cambio
    cambio registro = new _cambio;
    registro->numero = nroLinea;
    registro->textoLinea = new char[strlen(actual->textoLinea) + 1];
    strcpy(registro->textoLinea, actual->textoLinea);
    registro->tipo_Operacion = new char[3];
    strcpy(registro->tipo_Operacion, "BL");
    registro->sig = nullptr;
    
    if (v->tipo_cambio == nullptr) {
        v->tipo_cambio = registro;
    } else {
        cambio temp = v->tipo_cambio;
        while (temp->sig != nullptr) {
            temp = temp->sig;
        }
        temp->sig = registro;
    }
    
    // Borrar línea
    if (anterior == nullptr) {
        v->textoVersion = actual->sig;
    } else {
        anterior->sig = actual->sig;
    }
    
    delete[] actual->textoLinea;
    delete actual;
    
    // Renumerar líneas restantes
    lineas reenum = v->textoVersion;
    unsigned int nuevoNumero = 1;
    while (reenum != nullptr) {
        reenum->numero = nuevoNumero++;
        reenum = reenum->sig;
    }
    
    return OK;
}

TipoRet mostrarTexto(Archivo a, cadena version) {
    if (a == nullptr) {
        return ERROR;
    }
    
    Version arquivo = existencia_Version(a->primeraVersion, version);
    if (arquivo == nullptr) {
        cout << "No existe la versión buscada en: " << a->nombre << endl;
        return ERROR;
    }
    
    cout << a->nombre << " - " << arquivo->idVersion << endl << endl;
    
    lineas auxLineas = arquivo->textoVersion;
    if (auxLineas == nullptr) {
        cout << "No contiene líneas" << endl;
    } else {
        while (auxLineas != nullptr) {
            cout << auxLineas->numero << "\t" << auxLineas->textoLinea << endl;
            auxLineas = auxLineas->sig;
        }
    }
    return OK;
}

TipoRet mostrarCambios(Archivo a, cadena version) {
    if (a == nullptr || version == nullptr) {
        cout << "ERROR: Parámetros inválidos" << endl;
        return ERROR;
    }
    
    Version v = existencia_Version(a->primeraVersion, version);
    if (v == nullptr) {
        cout << "ERROR: Versión no existente" << endl;
        return ERROR;
    }
    
    cout << a->nombre << " - " << version << endl << endl;
    
    cambio aux = v->tipo_cambio;
    if (aux == nullptr) {
        cout << "No se realizaron modificaciones" << endl;
    } else {
        while (aux != nullptr) {
            cout << aux->tipo_Operacion << "\t" << aux->numero;
            if (strcmp(aux->tipo_Operacion, "IL") == 0) {
                cout << "\t" << aux->textoLinea;
            }
            cout << endl;
            aux = aux->sig;
        }
    }
    return OK;
}

TipoRet iguales(Archivo a, cadena version1, cadena version2, bool &iguales) {
    if (a == nullptr || version1 == nullptr || version2 == nullptr) {
        return ERROR;
    }
    
    Version v1 = existencia_Version(a->primeraVersion, version1);
    Version v2 = existencia_Version(a->primeraVersion, version2);
    
    if (v1 == nullptr || v2 == nullptr) {
        cout << "ERROR: Una o ambas versiones no existen" << endl;
        return ERROR;
    }
    
    lineas l1 = v1->textoVersion;
    lineas l2 = v2->textoVersion;
    iguales = true;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->numero != l2->numero || strcmp(l1->textoLinea, l2->textoLinea) != 0) {
            iguales = false;
            break;
        }
        l1 = l1->sig;
        l2 = l2->sig;
    }
    
    if (l1 != nullptr || l2 != nullptr) {
        iguales = false;
    }
    
    cout << "Las versiones " << (iguales ? "SON iguales" : "NO son iguales") << endl;
    return OK;
}

TipoRet BorrarArchivo(Archivo &a) {
    a = eliminarInfoArchivo(a);
    cout << "El archivo fue borrado con éxito" << endl;
    return OK;
}

TipoRet versionIndependiente(Archivo &a, cadena version) {
    cout << "Función VersionIndependiente no implementada" << endl;
    return NO_IMPLEMENTADO;
}