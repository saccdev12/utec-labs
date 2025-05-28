#include "ej10comp.h"
#include <iostream>

void inicializarMatriz(int matriz[M][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("Ingrese valor para [%d][%d]", i,j);
			scanf("%d", &matriz[i][j]);
		}		
	}
}
	
void mostrarMatriz(int matriz[M][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("[%d]", matriz[i][j]);
		}	
		printf("\n");
	}
} 	
		
void sumarMatrices (int matriz1 [M][N],int matriz2 [M][N],int suma [M][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
		   suma [i][j] = matriz1 [i][j] + matriz2 [i][j];
		}	
	}
}
