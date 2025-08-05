#include<iostream>
using namespace std;
#include "coso.h"

int main() {
	int entrada_primaria, entrada_secundaria, contador = 0;
	float promedio = 0;
	int suma = 0;
	
	Estudiante arreglo_estudiantes[30];
	
	while (true) {
		// Menú Principal
		printf("\n--- Menu Principal ---\n");
		printf("1.- Ingreso de notas (max. 30)\n");
		printf("2.- Estadisticas\n");
		printf("3.- Fin\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &entrada_primaria);
		
		if (entrada_primaria == 3) {
			break;
		}
		
		switch (entrada_primaria) {
		case 1:
			if (contador >= 30) {
				printf("Ya se ingresaron las 30 notas.\n");
				break;
			}
			
			while (contador < 30) {
				printf("\nIngrese su nombre: ");
				scanf("%s", arreglo_estudiantes[contador].nombre);
				int nota;
				do {
					printf("Ingrese su calificación (1-5): ");
					scanf("%d", &nota);
				} while (nota < 1 || nota > 5);
				arreglo_estudiantes[contador].calificacion = nota;
				contador++;
				
				char seguir;
				if (contador < 30) {
					printf("Desea ingresar otra nota? (s/n): ");
					scanf(" %c", &seguir);
					if (seguir != 's' && seguir != 'S'){
						break;
					}
				}
			}
			break;
			
		case 2:
			if (contador == 0) {
				printf("No hay notas ingresadas.\n");
				break;
			}
			
			do {
				printf("\n--- Menu Estadisticas ---\n");
				printf("1.- Promedio sobre notas ingresadas\n");
				printf("2.- Mayor nota ingresada\n");
				printf("3.- Menor nota ingresada\n");
				printf("4.- Cantidad de notas insuficientes (<3)\n");
				printf("5.- Cantidad de notas suficientes (>=3)\n");
				printf("6.- Fin\n");
				printf("Seleccione una opción: ");
				scanf("%d", &entrada_secundaria);
				
				switch (entrada_secundaria) {
				case 1:
					suma = 0;
					for (int i = 0; i < contador; i++) {
						suma += arreglo_estudiantes[i].calificacion;
					}
					promedio = (float)suma / contador;
					printf("Promedio: %.2f\n", promedio);
					break;
					
				case 2: {
					int mayor = arreglo_estudiantes[0].calificacion;
					for (int i = 1; i < contador; i++) {
						if (arreglo_estudiantes[i].calificacion > mayor)
							mayor = arreglo_estudiantes[i].calificacion;
					}
					printf("Mayor nota: %d\n", mayor);
					printf("Estudiantes con esa nota:\n");
					for (int i = 0; i < contador; i++) {
						if (arreglo_estudiantes[i].calificacion == mayor)
							printf("%s\n", arreglo_estudiantes[i].nombre);
					}
					break;
				}
				
				case 3: {
					int menor = arreglo_estudiantes[0].calificacion;
					for (int i = 1; i < contador; i++) {
						if (arreglo_estudiantes[i].calificacion < menor)
							menor = arreglo_estudiantes[i].calificacion;
					}
					printf("Menor nota: %d\n", menor);
					printf("Estudiantes con esa nota:\n");
					for (int i = 0; i < contador; i++) {
						if (arreglo_estudiantes[i].calificacion == menor)
							printf("%s\n", arreglo_estudiantes[i].nombre);
					}
					break;
				}
				
				case 4: {
					int cantidad = 0;
					for (int i = 0; i < contador; i++) {
						if (arreglo_estudiantes[i].calificacion < 3)
							cantidad++;
					}
					printf("Cantidad de notas insuficientes: %d\n", cantidad);
					break;
				}
				
				case 5: {
					int cantidad = 0;
					for (int i = 0; i < contador; i++) {
						if (arreglo_estudiantes[i].calificacion >= 3)
							cantidad++;
					}
					printf("Cantidad de notas suficientes: %d\n", cantidad);
					break;
				}
				
				case 6:
					printf("Volviendo al menu principal...\n");
					break;
					
				default:
					printf("Opcion invalida.\n");
				}
			} while (entrada_secundaria != 6);
			break;
			
		default:
			printf("Opcion invalida.\n");
		}
	}
	
	printf("Programa finalizado.\n");
}

