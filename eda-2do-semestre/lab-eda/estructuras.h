#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#define P 5
#define T 256
typedef char *cadena;

typedef struct _linea {
	unsigned int numero = 1;//no agarra negativos
	cadena textoLinea = new char[T] ;
	_linea *sig = NULL;
}*lineas;

typedef struct _version {
	cadena idVersion = new char[T];        // p.ej. "1.2.3"
	lineas textoVersion = NULL;             // lista de líneas (puede ser NULL)
	_version *padre = NULL;  // versión de la que depende
	_version *primerHijo = NULL;
	_version *sigHermano = NULL;
} *Version;

typedef struct _archivo {
	cadena nombre = new char[T];           // nombre del archivo (ej. "curriculum.txt")
	Version primeraVersion = NULL;  // raíz del árbol de versiones
} *Archivo;

typedef enum _opcion{
	CrearVersion, MostrarVersiones, InsertarLinea, BorrarLinea, MostrarCambios, BorrarVersion, MostrarTexto, VersionIndependiente, ayuda, error, salir, limpiar
}opciones;


typedef enum _retorno{
	OK, ERROR, NO_IMPLEMENTADO
}TipoRet;

#endif
