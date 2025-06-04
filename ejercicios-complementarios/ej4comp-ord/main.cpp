#include<iostream>
#include "ej4comp-ord.h"
using namespace std;

int main () {
	Persona personas[N];
	for (int i=0;i<N;i++){
		personas [i]=leerPersona();
	}
	for (int i=0;i<N;i++){
		imprimirPersona(personas[i]);
	}
	ordenaArreglo(personas);
	for (int i=0;i<N;i++){
		imprimirPersona(personas[i]);
	}
	return 0;
}
