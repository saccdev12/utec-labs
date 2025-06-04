#include "ejecomplementariasarrays1.h"
#include<iostream>

bool estaEnArreglo(int a[], int num){
	for(int i=0 ; i<N ; i++){
		if(a[i] == num)
			return true;
	}
	return false;
}

int indiceElemento(int a[], int num){
	for(int i=0 ; i<N ; i++){
		if(a[i] == num)
			return i;
	}
	return -1;
}
	
