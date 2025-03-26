#include <stdio.h>

int main() {
	
	int numero;
	printf("Ingrese un número de 4 dígitos: ");
	scanf("%d", &numero);
	int unidad, decena, centena, miles;
	unidad = numero % 10;
	decena = (numero/10)%10;
	centena = (numero/100)%10;
	miles = (numero/1000)%10;
	printf("Los dígitos son: %d %d %d %d", miles, centena, decena, unidad);
	return 0;
}