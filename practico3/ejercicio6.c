#include <stdio.h>

int main() {
	
	int numero;
	
	printf("Ingrese un número: ");
	scanf("%d", &numero);
	
	if (numero % 3 == 0 && numero % 5 == 0) {
		printf("El número %d es múltiplo de 3 y 5 a la vez. \n", numero);
	} else if (numero % 3 == 0) {
		printf("El número %d es múltiplo de 3. \n", numero);
	} else if (numero % 5 == 0) {
		printf("El número %d es múltiplo de 5. \n", numero);
	} else {
		printf("El número %d no es múltiplo ni de 3 ni de 5. \n", numero);
	}
	return 0;
}
