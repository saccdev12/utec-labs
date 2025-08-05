#include <stdio.h>

int main() {
	
	char n1, n2, n3, n4;
	printf("Ingrese un número de 4 dígitos: ");
    n1 = getchar();
	n2 = getchar();
	n3 = getchar();
	n4 = getchar();
	
	printf("Los dígitos son: %c %c %c %c", n1, n2, n3, n4);
	
	return 0;
}
