#include<iostream>
#include "medallero.h"
using namespace std;
int main () {
	int entrada_primaria, entrada_secundaria, contador = 0;
	char nombre_main[LARGO_NOMBRE];
	Pais array_paises[206];
	
	do{
		// Menu Principal
		printf("\n--- Menu Principal ---\n");
		printf("1.- Ingreso pais (206 maximo)\n");
		printf("2.- Modificar medallas\n");
		printf("3.- Listado del medallero ordenado por oro\n");
		printf("4.- Fin\n");
		printf("seleccione una opcion: \n");
		scanf("%d", &entrada_primaria);
		
		if (entrada_primaria == 4) {
			break;
		}
		
		switch (entrada_primaria){
		case 1:
			ingreser_pais(array_paises,array_paises[contador].nombre,contador);
			break;
		case 2:
			modificar_medallas(array_paises,contador);
			break;
		case 3:
			imprimir_oro(array_paises,contador);
			break;
		case 4:
			break;
		}
		
	}while(entrada_primaria != 4);;
	
}
