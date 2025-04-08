#include <stdio.h>

int main() {
	float num, saldo = 0.0;
	char transaccion;
	
	printf("Ingrese tipo de transacción y cantidad (ejemplo: A 1200.35):\n");
	scanf(" %c %f", &transaccion, &num);
	
	if (transaccion == 'A') {
		saldo = num;
		
		// Leemos la siguiente transacción
		scanf(" %c", &transaccion);
		
		while (transaccion != 'X') {
			scanf(" %f", &num);  // Leer el monto solo si no es 'X'
			
			switch (transaccion) {
			case 'D':
				saldo += num;
				break;
			case 'R':
				saldo -= num;
				break;
			default:
				printf("Transacción no válida: %c\n", transaccion);
				break;
			}
			
			printf("Ingrese siguiente transacción (D o R) y el monto, o X para terminar:\n");
			scanf(" %c", &transaccion);
		}
		
		printf("El saldo final es: %.2f\n", saldo);
	} else {
		printf("La primera línea debe comenzar con 'A'.\n");
	}
	
	return 0;
}




/*#include <stdio.h>

int main() {
	float num, saldo = 0.0;
	char transaccion;
	
	printf("Por favor ingrese el tipo de transacción y la cantidad (ejemplo: A 1200.35):      \n");
	scanf("%c%f", &transaccion, &num);  
	if (transaccion=='A'){
	saldo=num;
	while (transaccion !='X') {
		scanf("%c",&transaccion);
		switch (transaccion) {
		case 'D':
			scanf("%f",&num);
			saldo += num;
			break;
		case 'R':
			scanf("%f",&num);
			saldo -= num;
			break;
		default:
			printf("Transacción no válida: %c\n", transaccion);
			break;
		}
		
		printf("Ingrese siguiente transacción (o 'X' para terminar)  y el monto (separados por un espacio):\n ");
		scanf("%c %f", &transaccion,&num);  
		
		
		}
	
	
	printf("El saldo final es: %f \n", saldo);
	}else {
		printf (" No funciona ");
	}
	return 0;
}/*

