#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include "estructuras.h"

// Funciones principales
void muestroRetorno(TipoRet retorno);
void help();
Archivo CrearArchivo(cadena nombre);
TipoRet BorrarArchivo(Archivo &a);
TipoRet crearVersion(Archivo &a, cadena version);
TipoRet borrarVersion(Archivo &a, cadena version);
TipoRet mostrarVersiones(Archivo a);
TipoRet insertarLinea(Archivo &a, cadena version, cadena linea, unsigned int nroLinea);
TipoRet borrarLinea(Archivo &a, cadena version, unsigned int nroLinea);
TipoRet mostrarTexto(Archivo a, cadena version);
TipoRet mostrarCambios(Archivo a, cadena version);
TipoRet iguales(Archivo a, cadena version1, cadena version2, bool &iguales);
TipoRet versionIndependiente(Archivo &a, cadena version);

// Funciones auxiliares
Version existencia_Version(Version v, cadena id);
Archivo eliminarInfoArchivo(Archivo a);
void borrarLinea_Recursivo(lineas &a);
void borrarVersion_Recursivo(Version &a);
void itoa_simple(int n, char res[]);
void mostrarArbol(Version a, int nivel);
void liberarLineas(lineas &l);
void liberarVersion(Version &v);
Version encontrarPadre(Version v, cadena idHijo);
bool validarFormatoVersion(cadena version);
void copiarTextoVersion(Version destino, Version origen);
int obtenerUltimaVersionPrincipal(Archivo a);

#endif
