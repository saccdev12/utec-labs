#include "ej7comp.h"
#include <iostream>

void largotablero(int m[][largotab]){
	printf("Cargando Matriz \n");
	for (int i=0; i<largotab; i++){
		for (int j=0; j<largotab; j++){
			printf("Ingrese la posicion [%d][%d]", i, j);
			scanf("%d", &m[i][j]);
		}
	}
}

void imprimirtablero(int m[][largotab]){
	for (int i=0; i<largotab; i++){
		for (int j=0; j<largotab; j++){
			printf("[%d]", m[i][j]);
		}
	printf("\n");	
	}
}	

int filamayor(int m[][largotab], int &sumafila){
	int filamax, suma;
	for (int i=0; i<largotab; i++){
		suma = 0;
		for (int j=0; j<largotab; j++){
			suma = suma + m[i][j];
		}
		if (i == 0){
			filamax = 0;
			sumafila = suma;
		}else{
			if (suma > sumafila){
				sumafila = suma;
				filamax = i;
			}
		}
	}
}	
	
	
