#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define P 5
#define T 256

typedef char *cadena;

typedef struct _linea {
    unsigned int numero;
    cadena textoLinea;
    _linea *sig;
} *lineas;

typedef struct _cambio {
    unsigned int numero;
    cadena textoLinea;
    cadena tipo_Operacion;
    _cambio *sig;
} *cambio;

typedef struct _version {
    cadena idVersion;
    lineas textoVersion;
    _version *padre;
    _version *primerHijo;
    _version *sigHermano;
    cambio tipo_cambio;
} *Version;

typedef struct _archivo {
    cadena nombre;
    Version primeraVersion;
} *Archivo;

typedef enum _opcion {
    CrearVersion, MostrarVersiones, InsertarLinea, BorrarLinea, 
    MostrarCambios, BorrarVersion, MostrarTexto, VersionIndependiente, 
    ayuda, error, salir, limpiar, Iguales
} opciones;

typedef enum _retorno {
    OK, ERROR, NO_IMPLEMENTADO
} TipoRet;

#endif