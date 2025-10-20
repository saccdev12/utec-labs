#ifndef PROTOTIPO_H
#define PROTOTIPO_H

arboln crearArbol();
//Inicia el nuevo arbol agregando creando la raiz con el valor 0

void insertarNodo(arboln &a, int valorPadre, int valor);
//Inserta un nuevo nodo al arbol. dependiendo del valorPadre el cual debe existir

void mostrarArbol(arboln a);

arboln buscarNodo(arboln a, int valor);
//Busca nodo con el valor recibido por parametro. devuelve direccion del mismo si existe

bool EsVacio(arboln a);
//devuelve true si el arbol no existe.

void mostrarHijos(arboln a);
//muestra los hijos de la dirección del arbol o subarbol recibido. Debe existir 

int cantidadNodos(arboln a);
//devuelve la cantidad de nodos del arbol/subarbol

void eliminoArbol(arboln a);
//elimina el arbol por completo liberando los espacios de memoria.

#endif
