#include "ej8comppp.h"
#include <iostream>
using namespace std;

int main () {
	int matriz[N][N];
	inicializarMatriz(matriz);
	mostrarMatriz(matriz);
	int f1, f2;
	printf("Ingrese las filas a intercambiar");
	scanf("%d %d", &f1, &f2);
	intercambiarFilas(matriz, f1, f2);
	mostrarMatriz(matriz);
	return 0;
}

