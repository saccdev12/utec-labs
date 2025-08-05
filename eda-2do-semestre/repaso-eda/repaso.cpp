#include <iostream>
#include "repaso.h"
using namespace std;

void ingresarNotas(Estudiante estudiantes[], int* contador) {
	if (*contador >= 30) {
		printf("Maximo de estudiantes alcanzado (30)\n");
		return;
	}
	
	printf("Nombre del estudiante: ");
	scanf("%25s", estudiantes[*contador].nombre);
	
	printf("Nota (1-5): ");
	scanf("%d", &estudiantes[*contador].calificacion);
	
	while (estudiantes[*contador].calificacion < 1 || estudiantes[*contador].calificacion > 5) {
		printf("Nota invalida. Ingrese nuevamente (1-5): ");
		scanf("%d", &estudiantes[*contador].calificacion);
	}
	
	(*contador)++;
}

void mostrarEstadisticas(Estudiante estudiantes[], int contador) {
	if (contador == 0) {
		printf("No hay datos ingresados\n");
		return;
	}
	
	int opcion;
	do {
		printf("\n1. Promedio\n2. Mayor nota\n3. Menor nota\n");
		printf("4. Notas <3\n5. Notas >=3\n6. Volver\nOpcion: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			printf("Promedio: %.2f\n", calcularPromedio(estudiantes, contador));
			break;
		case 2:
			encontrarMayorNota(estudiantes, contador);
			break;
		case 3:
			encontrarMenorNota(estudiantes, contador);
			break;
		case 4:
			printf("Notas <3: %d\n", contarInsuficientes(estudiantes, contador));
			break;
		case 5:
			printf("Notas >=3: %d\n", contarSuficientes(estudiantes, contador));
			break;
		case 6:
			break;
		default:
			printf("Opcion invalida\n");
		}
	} while (opcion != 6);
}

float calcularPromedio(Estudiante estudiantes[], int contador) {
	float suma = 0;
	for (int i = 0; i < contador; i++) {
		suma += estudiantes[i].calificacion;
	}
	return suma / contador;
}

void encontrarMayorNota(Estudiante estudiantes[], int contador) {
	int mayor = estudiantes[0].calificacion;
	for (int i = 1; i < contador; i++) {
		if (estudiantes[i].calificacion > mayor) {
			mayor = estudiantes[i].calificacion;
		}
	}
	
	printf("Mayor nota (%d) obtenida por:\n", mayor);
	for (int i = 0; i < contador; i++) {
		if (estudiantes[i].calificacion == mayor) {
			printf("- %s\n", estudiantes[i].nombre);
		}
	}
}

void encontrarMenorNota(Estudiante estudiantes[], int contador) {
	int menor = estudiantes[0].calificacion;
	for (int i = 1; i < contador; i++) {
		if (estudiantes[i].calificacion < menor) {
			menor = estudiantes[i].calificacion;
		}
	}
	
	printf("Menor nota (%d) obtenida por:\n", menor);
	for (int i = 0; i < contador; i++) {
		if (estudiantes[i].calificacion == menor) {
			printf("- %s\n", estudiantes[i].nombre);
		}
	}
}

int contarInsuficientes(Estudiante estudiantes[], int contador) {
	int count = 0;
	for (int i = 0; i < contador; i++) {
		if (estudiantes[i].calificacion < 3) {
			count++;
		}
	}
	return count;
}

int contarSuficientes(Estudiante estudiantes[], int contador) {
	int count = 0;
	for (int i = 0; i < contador; i++) {
		if (estudiantes[i].calificacion >= 3) {
			count++;
		}
	}
	return count;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
