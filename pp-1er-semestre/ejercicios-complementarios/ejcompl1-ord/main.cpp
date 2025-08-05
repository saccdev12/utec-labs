#include "ej1compl-ord.h"
#include <iostream>
using namespace std;

int main () {
	int numeros [N];
	cargoArreglo(numeros);
	printf("Arreglo ingresado: \n");
	imprimeArreglo(numeros);
	SortPorSeleccion(numeros, N);
	printf("\n");
	printf("Areglo ordenado: \n");
	imprimeArreglo(numeros);
	printf("\n");
	printf("Ingrese un numero: \n");
	int posicion, elemento;
	scanf("%d", &elemento);
	posicion = busquedaBinaria(numeros, elemento, N);
	printf("La busqueda da %d", posicion);
	return 0;
}

