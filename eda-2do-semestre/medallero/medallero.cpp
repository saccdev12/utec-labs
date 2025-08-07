#include "medallero.h"
#include<iostream>
#include<string.h>
void ingresar_medallas(Pais array_paises[],int contador){
	char seguir;
	bool continuacion=true;
	int aux;
	printf("---Ingresa la clase de medallas---\n");
	printf("1.-Oro\n");
	printf("2.-PLata\n");
	printf("3.Bronce\n");
	scanf("%d",&aux);
	do{
		switch(aux){
		case 1:
			printf("Ingrese la cantidad de medallas\n");
			scanf("%d",&aux);
			array_paises[contador].medalla_oro=aux;
			break;
		case 2:
			printf("Ingrese la cantidad de medallas\n");
			scanf("%d",&aux);
			array_paises[contador].medalla_plata=aux;
			break;
		case 3:
			printf("Ingrese la cantidad de medallas\n");
			scanf("%d",&aux);
			array_paises[contador].medalla_bronce=aux;
			break;
		default:
			printf("Medallas no registradas\n");
			break;
		}
		if(continuacion==true){
			printf("Quiere continuar agregando medallas?(s/n): \n");
			scanf(" %c", &seguir);
			if (seguir != 's' && seguir != 'S'){
				continuacion = false;
				break;
			}
		}
		printf("Ingrese codigo de medalla: \n");
		scanf("%d",&aux);
	} while(continuacion==true );
}
	void ingreser_pais(Pais array_paises[],char nombre_pais[],int &contador){
		bool aux = true;
		char string_aux[LARGO_NOMBRE]={""};
		while(aux == true){
			if(contador>=CANTIDAD_PAISES){
				printf("Ya llegaste al maximo de paises.\n");
				break;
			}
			while(contador<CANTIDAD_PAISES){
				printf("Ingrese el nombre del pais.\n");
				scanf(" %s",string_aux);
				strcpy(array_paises[contador].nombre,string_aux);
				ingresar_medallas(array_paises,contador);
				contador++;
				char seguir;
				if (contador <CANTIDAD_PAISES) {
					printf("Desea ingresar otro pais? (s/n): ");
					scanf(" %c", &seguir);
					if (seguir != 's' && seguir != 'S'){
						aux = false;
						break;
					}
					
				}
				break;
			}
		}
	}	
		/*
		void modificar_medallas(Pais array_paises[],int contador){
		bool continuacion=true;
		char seguir;
		char string_aux[LARGO_NOMBRE];
		printf("Ingrese el nombre del pais a modificar.\n");
		scanf(" %s",string_aux);
		do{
		for(int i=0;1<contador;i++){
		if((strcmp(array_paises[i].nombre,string_aux)==0)){
		
		printf("---Modificacion de medallas del pais %s.---\n",string_aux);
		ingresar_medallas(array_paises,contador);
		printf("Quiere continuar acambiando medallas?(s/n): \n");
		scanf(" %c", &seguir);
		if (seguir != 's' && seguir != 'S'){
		continuacion = false;
		}
		}
		}	
		}while(continuacion==true);	
		}
		*/
		
		
		void modificar_medallas(Pais array_paises[], int contador) {
			bool continuacion = true;
			char seguir;
			char string_aux[LARGO_NOMBRE];
			bool encontrado = false;
			
			printf("Ingrese el nombre del pais a modificar.\n");
			scanf(" %s", string_aux);
			
			for(int i = 0; i < contador; i++) {
				if((strcmp(array_paises[i].nombre, string_aux) == 0)) {
					encontrado = true;
					do {
						printf("---Modificacion de medallas del pais %s.---\n", string_aux);
						ingresar_medallas(array_paises, i);  // Nota: usar i en lugar de contador
						printf("Quiere continuar cambiando medallas?(s/n): \n");
						scanf(" %c", &seguir);
						if (seguir != 's' && seguir != 'S') {
							continuacion = false;
						}
					} while(continuacion == true);
					break;  // Salir del for una vez encontrado y modificado
				}
			}
			
			if(!encontrado) {
				printf("Pais no encontrado.\n");
			}
		}		
		
		void imprimir_oro(Pais array_paises[],int contador){
			Pais pais_aux;
			for(int i=0;i<contador-1;i++){
				for(int j=0;j<contador-1;j++){
					if(array_paises[j].medalla_oro < array_paises[j+1].medalla_oro){
						pais_aux=array_paises[j];
						array_paises[j]=array_paises[j+1];
						array_paises[j+1]=pais_aux;
					}
				}
			}
			for(int i=0;i<contador;i++){
				printf("-Medallas de Oro del pais: %s\n",array_paises[i].nombre);
				printf("\n---%d---\n",array_paises[i].medalla_oro);
			}
			
		}
			
