#include<iostream>
#include "ejercicio3.h"

int igualesI(int num1[], int num2[], int tamanio){
	for(int i=0; i<tamanio; i++){
		if(num2[i]!=num1[i]){
			return 0;
		}
	}
	return 1;
}
	
int igualesR(int num1[], int num2[], int tamanio){
	// caso base
	if(tamanio == 0){
		return 1;
	}
	// caso base
	if(num1[tamanio-1] != num2[tamanio-1]){
		return 0;
	}
	
	// caso recursivo
	return igualesR(num1, num2, tamanio-1);
}	
