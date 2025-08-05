#include <iostream>
#include "repaso.h"
using namespace std;

int main() {
	int opcion, contador = 0;
	Estudiante estudiantes[29];
	
	while (true) {
		printf("\nMENU PRINCIPAL\n");
		printf("1. Ingresar notas\n2. Estadisticas\n3. Salir\nOpcion: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			ingresarNotas(estudiantes, &contador);
			break;
		case 2:
			mostrarEstadisticas(estudiantes, contador);
			break;
		case 3:
			return 0;
		default:
			printf("Opcion invalida\n");
		}
	}
}

