#include <stdio.h>

int main() {
	int num1, num2, resultado;
	char operacion;
	
	printf("Ingrese dos números enteros y una de las operaciones (+ o *): ");
	scanf("%d %d %c", &num1, &num2, &operacion);
	
	if (operacion == '+') {
		resultado = num1 + num2;
		printf("El resultado de %d + %d es: %d\n", num1, num2, resultado);
	} else if (operacion == '*') {
		resultado = num1 * num2;
		printf("El resultado de %d * %d es: %d\n", num1, num2, resultado);
	} else {
		printf("La operación no es válida. Solo se permite '+' o '*'.\n");
	}
	
	return 0;
}