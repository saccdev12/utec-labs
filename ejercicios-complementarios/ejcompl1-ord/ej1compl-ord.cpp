#include "ej1compl-ord.h"
#include <iostream>

void cargoArreglo(int a[]){
	for(int i=0; i<N; i++){
		printf("Ingrese el numero a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void imprimeArreglo(int a[]){
	for(int i=0; i<N; i++){
		printf(" %d ", a[i]);
	}
}	

void burbuja(int a[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1; j++){
			if(a[j]>a[j+1]){
				intercambio(a[j], a[j+1]);
			}
		}
	}
}

void intercambio(int &a, int &b){
	int aux;
	aux = a;
	a = b;
	b = aux;
}
	
void SortPorSeleccion (int A[], int n){
	int i, j, sel, clave_sel;
	
	for(i=0; i<n; i++){
		sel = i;
		clave_sel = A[i];
		for(j=i+1;j<n; j++ ){
			if (A[j]<clave_sel){
				clave_sel = A[j];
				sel = j;
			}
		}
		intercambio(A[i], A[sel]);
	}
}
	
int busquedaBinaria(int A[], int clave, int n){
	int izq = 0, medio, der = n;
	
	do{
		medio = (izq + der)/2;
		if(izq > der)
			medio = -1;
		else if (A[medio] < clave)
			izq = medio + 1;
		else der = medio - 1;
	}while(A[medio] != clave && medio != -1);
	
	return medio;
}
