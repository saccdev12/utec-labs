#include<iostream>
#include "ejcomp6.h"
using namespace std;

int main () {
	int numeros[N];
	bool respuesta;
	inicializarArreglo(numeros);
	respuesta = estaOrdenadoAscendente(numeros);
	if(respuesta){
		printf ("\n El arreglo esta ordenado ascendentemente. ");
	}else{
		printf ("\n El arreglo NO esta ordenado ascendentemente. ");
	}
	return 0;
}

