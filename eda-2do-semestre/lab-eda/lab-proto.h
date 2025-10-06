#ifndef LAB_PROTO_H
#define LAB_PROTO_H

#include "lab-struct.h"

// Operaciones de creación y destrucción
Archivo* CrearArchivo(char* nombre);
TipoRet BorrarArchivo(Archivo* &a);

// Operaciones de versiones
TipoRet CrearVersion(Archivo* &a, char* version);
TipoRet BorrarVersion(Archivo* &a, char* version);
TipoRet MostrarVersiones(Archivo* a);

// Operaciones de texto
TipoRet InsertarLinea(Archivo* &a, char* version, char* linea, unsigned int nroLinea);
TipoRet BorrarLinea(Archivo* &a, char* version, unsigned int nroLinea);
TipoRet MostrarTexto(Archivo* a, char* version);
TipoRet MostrarCambios(Archivo* a, char* version);

// Operaciones de comparación
TipoRet Iguales(Archivo* a, char* version1, char* version2, bool &iguales);

// Operación opcional
TipoRet VersionIndependiente(Archivo* &a, char* version);

// Funciones auxiliares
bool validarFormatoVersion(const char* version);
int compararVersiones(const char* v1, const char* v2);
void obtenerPadreVersion(const char* version, char* padre);
bool esVersionHermanasCompletas(Archivo* a, Version* padre, const char* nuevaVersion);

#endif