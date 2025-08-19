#include <iostream>
#include "ejercicio1.h"

int ocurrencia_Iterativa(int numeros[], int valor, int tamanio){
	int aux = 0;
	for(int i=0; i<tamanio; i++){
		if(numeros[i]==valor){
			aux++;
		}
	}
	return aux;
}

int ocurrencia_Recursiva(int numeros[], int valor, int tamanio){
	if(tamanio < 0){
		return 0;
	}else{
		if(numeros[tamanio]==valor){
			return 1 + ocurrencia_Recursiva(numeros, valor, tamanio - 1);
		}else{
			return ocurrencia_Recursiva(numeros, valor, tamanio - 1);
		}
	}
}

