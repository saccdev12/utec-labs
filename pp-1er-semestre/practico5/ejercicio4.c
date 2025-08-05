#include <stdio.h>

int main() {
	int valor, digito;
	printf("Ingrese un n�mero de 4 d�gitos: \n");
	scanf("%d", &valor);
	printf("Ingrese un n�mero de 1 d�gito \n");
	scanf("%d", &digito);
	int c1, c2, c3, c4;
	c4= valor%10;
	c3= (valor/10)%10;
	c2= (valor/100)%10;
	c1= (valor/1000)%10;
	if (digito == c1 || digito == c2 || digito ==c3 || digito == c4){
		printf("%d \n", valor);
		if (c1 == digito){
			printf("+");
		}else {
			printf(" ");
		}
		if (c2 == digito){
			printf("+");
		}else {
			printf(" ");
		}
		if (c3 == digito){
			printf("+");
		}else {
			printf(" ");
		}
		if (c4 == digito){
			printf("+");
		}else {
			printf(" ");
		}
	}else{
		printf("El dígito: %d no aparece en: %d", digito, valor);
	}
	return 0;
}

