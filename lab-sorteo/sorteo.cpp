#include <iostream>
#include "sorteo.h"

int generarCopa(int i){
	return (i%3)+1;
}
	
	void jugar(){
		int saldo=1000;
		int contador_de_aciertos=0;
		int copaelegida;
		int rondas=0;
		int apuesta;
		
		while(saldo>0){
			int copa_con_moneda = generarCopa(rondas);
			
			printf("O O O\n");
			printf("1 2 3\n");
			printf("Copa?:\n");
			scanf("%d",&copaelegida);
			
			printf("Apuesta?:\n");
			scanf(" %d",&apuesta);
			
			
			if (contador_de_aciertos == 2 && copaelegida == copa_con_moneda) { //estafa
				saldo -= apuesta;
				contador_de_aciertos = 0;
				printf("O     O\n");
				printf("No ha acertado\n");
			} else if (copaelegida == copa_con_moneda) { //acierto
				saldo += apuesta;
				contador_de_aciertos++;
				for (int i = 1; i <= 3; i++) {
					if (i == copa_con_moneda) printf(".  ");
					else printf("O  ");
				}
				printf("\nHa acertado\n");
			}else  { //no acierto
				saldo -= apuesta;
				contador_de_aciertos = 0;
				for (int i = 1; i <= 3; i++) {
					if (i == copa_con_moneda) printf(".  ");
					else printf("O  ");
				}
				printf("\nNo ha acertado\n");
			}
			
			printf("Saldo: %d\n", saldo);
			rondas++;
		}
		printf("Gracias por jugar\n");
		
	}
