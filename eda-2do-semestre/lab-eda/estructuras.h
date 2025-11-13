#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#define P 5
#define T 256
typedef char *cadena;

typedef struct _linea {
	unsigned int numero = 1;//no agarra negativos
	cadena textoLinea = new char[T] ;
	_linea *sig = nullptr;
}*lineas;


typedef struct _cambio {
	unsigned int numero = 1;//no agarra negativos
	cadena textoLinea = new char[T] ;
	cadena tipo_Operacion = new char[T] ;
	_cambio *sig = nullptr;
}*cambio;
typedef struct _version {
	cadena idVersion = new char[T];        // p.ej. "1.2.3"
	lineas textoVersion = nullptr;             // lista de l�neas (puede ser nullptr)
	_version *padre = nullptr;  // versi�n de la que depende
	_version *primerHijo = nullptr;
	_version *sigHermano = nullptr;
	cambio tipo_cambio = nullptr;
} *Version;

typedef struct _archivo {
	cadena nombre = new char[T];           // nombre del archivo (ej. "curriculum.txt")
	Version primeraVersion = nullptr;  // ra�z del �rbol de versiones
} *Archivo;

typedef enum _opcion{
	CrearVersion, MostrarVersiones, InsertarLinea, BorrarLinea, MostrarCambios, BorrarVersion, MostrarTexto, VersionIndependiente, ayuda, error, salir, limpiar
}opciones;


typedef enum _retorno{
	OK, ERROR, NO_IMPLEMENTADO
}TipoRet;

#endif
