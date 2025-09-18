#ifndef DEFINICION_H
#define DEFINICION_H
typedef struct _nodo{
	_nodo *ant;
	int valor;
	_nodo *sig;
}*listaDoble;

typedef struct _cabezal{
	listaDoble primero;
	listaDoble ultimo;
}cabezal;

enum _retorno{
	OK, ERROR, NO_IMPLEMENTADO
};
typedef enum _retorno TipoRet;

#endif