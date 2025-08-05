#include <stdio.h>

int main() {
	int a, b, c, d, resultado;
	printf("Ingrese los coeficientes del polinomio: ");
	scanf("%d%d%d", &a, &b, &c);
	printf("Ingrese n: ");
	scanf("%d", &d);
	resultado = a*d*d+b*d+c;
	printf("El resultado es %dn2+%dn+%d, para d=%d, es %d", a,b,c,d, resultado);
	
	return 0;
	
}