#include<iostream>
#include "ejecomplementariasarrays1.h"
using namespace std;

int main () {
	int numeros[N];
	int valor;
	inicializarArreglo(numeros);
	imprimeArreglo(numeros,N);
	printf ("\ningrese un numero para ver si esta ");
	scanf("%d",&valor);
	bool esta=comprobarArreglo(numeros,valor);
	if (esta){
		printf ("El valor esta en la posicion:%d.",indiceElemento(numeros,valor));
	}else{
		printf("El numero no esta ");
	}
	return 0;
}

