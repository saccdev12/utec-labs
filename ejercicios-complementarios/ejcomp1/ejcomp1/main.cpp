#include<iostream>
#include "ejecomplementariasarrays1.h"
using namespace std;

int main () {
	int numeros[N];
	inicializarArreglo(numeros);
	imprimeArreglo(numeros,N);
	
	printf("Ingrese un n�mero para ver si est�");
	int valor;
	scanf("%d", &valor);
	bool esta = estaEnArreglo(numeros, valor);
	if(esta){
		printf("El valor est� en la posici�n: %d", indiceElemento(numeros, valor));
	}
	else{
		printf("El n�mero no est�");
	}
	return 0;
}

