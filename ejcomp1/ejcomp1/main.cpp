#include<iostream>
#include "ejecomplementariasarrays1.h"
using namespace std;

int main () {
	int numeros[N];
	inicializarArreglo(numeros);
	imprimeArreglo(numeros,N);
	
	printf("Ingrese un número para ver si está");
	int valor;
	scanf("%d", &valor);
	bool esta = estaEnArreglo(numeros, valor);
	if(esta){
		printf("El valor está en la posición: %d", indiceElemento(numeros, valor));
	}
	else{
		printf("El número no está");
	}
	return 0;
}

