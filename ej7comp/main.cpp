#include "ej7comp.h"
#include<iostream>
using namespace std;

int main () {
	int tablero [largotab][largotab];
	int filamaxima, suma;
	largotablero(tablero);
	imprimirtablero(tablero);
	filamaxima = filamayor(tablero, suma);
	printf("\n la fila maxima es: %d y su suma da: %d ", filamaxima, suma);
	return 0;
}

