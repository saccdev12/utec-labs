#include "estructej1.h"
#include<iostream>
using namespace std;

int main () {
	Persona lista_de_personas[N];
	for (int i=0; i<N; i++){
		lista_de_personas[i] = leerPersona();
	}
	for (int i=0; i<N; i++){
		imprimirPersona(lista_de_personas[i]);
	}
	return 0;
}

