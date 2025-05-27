#include "ej5comp.h"
#include <iostream>

void inicializarMatriz(int matriz[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("Ingrese valor para [%d][%d]", i,j);
			scanf("%d", &matriz[i][j]);
		}		
	}
}
	
void mostrarMatriz(int matriz[N][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("[%d]", matriz[i][j]);
		}	
		printf("\n");
	}
} 	

	void intercambiarFilas (int matriz[N][N], int fila1, int fila2){
		for(int j = 0; j < N; j++){
			int aux = matriz[fila1][j];
			matriz[fila1][j] = matriz[fila2][j];
			matriz[fila2][j] = aux;
		}
	}
		
