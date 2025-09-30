#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define T 30
typedef char *cadena;

typedef struct _nodoStock{
	int cantidad;
	float precio;
	_nodoStock *sigS; //puntero al siguiente stock
	_nodoStock *antS; //puntero al anterior stock
}*stock;

typedef struct _nodoProducto{
	cadena nombre = new char[T];
	stock primero = NULL; //cabezal stock principio
	stock ultimo = NULL; //cabezal stock final
	_nodoProducto *sigP; //puntero al siguiente producto
}*producto;

typedef enum _opciones{
	inicio, compro, vendo, listo, salgo, ayuda, error, limpio
}opciones;

typedef enum _retorno{
	OK, ERROR, NO_IMPLEMENTADO
}tipoRet;

#endif