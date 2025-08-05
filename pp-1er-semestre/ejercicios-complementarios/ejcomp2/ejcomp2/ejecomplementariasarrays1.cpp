#include "ejecomplementariasarrays1.h"
#include<iostream>

void inicializarArreglo(int a[]){
	for (int i=0;i<N;i++){
		printf ("ingrese un numero:");
		scanf(" %d",&a[i]);
	}
}
void imprimeArreglo (int a[],int tamanio){
	for (int i=0;i<tamanio;i++){
		printf ("%d",a[i]);
	}
}
bool comprobarArreglo(int a[],int puesto){
	for (int i=0;i<N;i++){
		if (a[i]==puesto)
			return true;
    }
	return false;
	}
int indiceElemento(int a[],int num){
	for (int i=0;i<N;i++){
		if (a[i]==num)
			return i+1;
	}
	return -1;
}

