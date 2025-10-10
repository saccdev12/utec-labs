#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include "prototipos.h"

typedef struct _nodo{
	_nodo *hijoIzq = NULL;
	int valor;
	_nodo *hijoDer = NULL;
}*arbol;

#endif
