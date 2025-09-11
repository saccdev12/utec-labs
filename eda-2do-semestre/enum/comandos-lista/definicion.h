#ifndef DEFINICION_H
#define DEFINICION_H

typedef char *cadena;

typedef struct _nodo{
	cadena texto = new char[100];
	_nodo *sig;
}*lista;

typedef enum _accion{
	crear,mostrar,insertar, contarNodos, limpiar, ayuda, fin, error
}accion;

typedef enum _tipoRetorno{
	OK, ERROR, NO_IMPLEMENTADO
}tipoRetorno;

#endif