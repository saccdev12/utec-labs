#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
#include "estructuras.h"

void muestroRetorno(TipoRet retorno);
void help();

Archivo CrearArchivo(cadena nombre);
TipoRet BorrarArchivo(Archivo &a);
TipoRet CrearVersion(Archivo &a, cadena version);
TipoRet BorrarVersion(Archivo &a, cadena version);
TipoRet MostrarVersiones(Archivo a);
TipoRet InsertarLinea(Archivo &a, cadena version, cadena linea, unsigned int nroLinea);
TipoRet BorrarLinea(Archivo &a, cadena version, unsigned int nroLinea);
TipoRet MostrarTexto(Archivo a, cadena version);
TipoRet MostrarCambios(Archivo a, cadena version);
TipoRet Iguales(Archivo a, cadena version1, cadena version2, bool &iguales);
TipoRet VersionIndependiente(Archivo &a, cadena version);

Version existencia_Version(Version v,cadena id);
Archivo eliminarInfoArchivo(Archivo a);

#endif
