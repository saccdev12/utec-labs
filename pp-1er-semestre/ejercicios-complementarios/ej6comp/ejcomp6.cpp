#include "ejcomp6.h"
#include<iostream>

void inicializarArreglo(int a[]) {
	for (int i = 0; i < N; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &a[i]);
	}
}

void imprimeArreglo(int a[]) {
	for (int i = 0; i < N; i++) {
		printf("%d ", a[i]);  // Agregué un espacio para mejor legibilidad
	}
}

bool estaOrdenadoAscendente(int a[]) {
	for (int i = 0; i < N - 1; i++) {  // Cambiado a N-1 para no salir del arreglo
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;  // Mover fuera del bucle
}		
