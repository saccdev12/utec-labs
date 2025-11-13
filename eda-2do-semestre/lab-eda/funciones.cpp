#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <limits>
using namespace std;

#include "estructuras.h"
#include "prototipos.h"

Archivo CrearArchivo(cadena nombre) {
    Archivo a = new _archivo;
    a->nombre = new char[strlen(nombre) + 1];
    strcpy(a->nombre, nombre);
    a->primeraVersion = nullptr;
    return a;
}

Version existencia_Version(Version v, cadena id) {
    if (v == nullptr) return nullptr;
    
    if (strcmp(v->idVersion, id) == 0) return v;
    
    Version encontrada = existencia_Version(v->primerHijo, id);
    if (encontrada != nullptr) return encontrada;
    
    return existencia_Version(v->sigHermano, id);
}

Archivo eliminarInfoArchivo(Archivo a) {
    if (a == nullptr) return nullptr;
    
    if (a->primeraVersion != nullptr) {
        borrarVersion_Recursivo(a->primeraVersion);
    }
    
    if (a->nombre != nullptr) {
        delete[] a->nombre;
    }
    
    delete a;
    return nullptr;
}

void borrarLinea_Recursivo(lineas &a) {
    if (a == nullptr) return;
    
    borrarLinea_Recursivo(a->sig);
    
    if (a->textoLinea != nullptr) {
        delete[] a->textoLinea;
    }
    delete a;
    a = nullptr;
}

void borrarVersion_Recursivo(Version &a) {
    if (a == nullptr) return;
    
    borrarVersion_Recursivo(a->primerHijo);
    borrarVersion_Recursivo(a->sigHermano);
    
    // Liberar líneas de texto
    borrarLinea_Recursivo(a->textoVersion);
    
    // Liberar cambios
    cambio actualCambio = a->tipo_cambio;
    while (actualCambio != nullptr) {
        cambio siguiente = actualCambio->sig;
        if (actualCambio->textoLinea != nullptr) delete[] actualCambio->textoLinea;
        if (actualCambio->tipo_Operacion != nullptr) delete[] actualCambio->tipo_Operacion;
        delete actualCambio;
        actualCambio = siguiente;
    }
    
    if (a->idVersion != nullptr) {
        delete[] a->idVersion;
    }
    
    delete a;
    a = nullptr;
}

void liberarLineas(lineas &l) {
    lineas actual = l;
    while (actual != nullptr) {
        lineas siguiente = actual->sig;
        if (actual->textoLinea != nullptr) {
            delete[] actual->textoLinea;
        }
        delete actual;
        actual = siguiente;
    }
    l = nullptr;
}

void liberarVersion(Version &v) {
    if (v != nullptr) {
        liberarLineas(v->textoVersion);
        
        // Liberar cambios
        cambio actual = v->tipo_cambio;
        while (actual != nullptr) {
            cambio siguiente = actual->sig;
            if (actual->textoLinea != nullptr) delete[] actual->textoLinea;
            if (actual->tipo_Operacion != nullptr) delete[] actual->tipo_Operacion;
            delete actual;
            actual = siguiente;
        }
        
        if (v->idVersion != nullptr) {
            delete[] v->idVersion;
        }
        delete v;
        v = nullptr;
    }
}

Version encontrarPadre(Version v, cadena idHijo) {
    if (v == nullptr) return nullptr;
    
    Version temp = v->primerHijo;
    while (temp != nullptr) {
        if (strcmp(temp->idVersion, idHijo) == 0) {
            return v;
        }
        Version padre = encontrarPadre(temp, idHijo);
        if (padre != nullptr) return padre;
        temp = temp->sigHermano;
    }
    
    return encontrarPadre(v->sigHermano, idHijo);
}

void mostrarArbol(Version a, int nivel) {
    if (a == nullptr) return;
    
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << a->idVersion << endl;
    
    mostrarArbol(a->primerHijo, nivel + 1);
    mostrarArbol(a->sigHermano, nivel);
}

void itoa_simple(int n, char res[]) {
    if (n == 0) {
        res[0] = '0';
        res[1] = '\0';
        return;
    }
    
    int i = 0;
    bool negativo = false;
    
    if (n < 0) {
        negativo = true;
        n = -n;
    }
    
    while (n != 0) {
        res[i++] = n % 10 + '0';
        n = n / 10;
    }
    
    if (negativo) {
        res[i++] = '-';
    }
    
    res[i] = '\0';
    
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = res[start];
        res[start] = res[end];
        res[end] = temp;
        start++;
        end--;
    }
}

bool validarFormatoVersion(cadena version) {
    if (version == nullptr || strlen(version) == 0) return false;
    
    if (version[0] == '.' || version[strlen(version)-1] == '.') {
        return false;
    }
    
    for (size_t i = 0; i < strlen(version); i++) {
        if (!isdigit(version[i]) && version[i] != '.') {
            return false;
        }
    }
    
    return true;
}

void copiarTextoVersion(Version destino, Version origen) {
    if (destino == nullptr || origen == nullptr) return;
    
    liberarLineas(destino->textoVersion);
    
    lineas actualOrigen = origen->textoVersion;
    lineas *ultimoDestino = &(destino->textoVersion);
    
    while (actualOrigen != nullptr) {
        lineas nuevaLinea = new _linea;
        nuevaLinea->numero = actualOrigen->numero;
        nuevaLinea->textoLinea = new char[strlen(actualOrigen->textoLinea) + 1];
        strcpy(nuevaLinea->textoLinea, actualOrigen->textoLinea);
        nuevaLinea->sig = nullptr;
        
        *ultimoDestino = nuevaLinea;
        ultimoDestino = &(nuevaLinea->sig);
        
        actualOrigen = actualOrigen->sig;
    }
}

int obtenerUltimaVersionPrincipal(Archivo a) {
    if (a == nullptr || a->primeraVersion == nullptr) return 0;
    
    Version actual = a->primeraVersion;
    int maxVersion = 1;
    
    while (actual != nullptr) {
        if (strchr(actual->idVersion, '.') == nullptr) {
            int versionNum = atoi(actual->idVersion);
            if (versionNum > maxVersion) {
                maxVersion = versionNum;
            }
        }
        actual = actual->sigHermano;
    }
    
    return maxVersion;
}