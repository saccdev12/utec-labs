#include "ej10comp.h"
#include <iostream>
using namespace std;

int main () {
	int matriz1[M][N], matriz2[M][N], suma[M][N];
	inicializarMatriz(matriz1);
	inicializarMatriz(matriz2);
	printf("La matriz 1 es: \n");
	mostrarMatriz(matriz1);
	printf("");
	printf("La matriz 2 es: \n");
	printf("");
	mostrarMatriz(matriz2);
	sumarMatrices(matriz1, matriz2, suma);
	printf("La suma de las matrices resultantes es: \n");
	mostrarMatriz(suma);
	return 0;
}
