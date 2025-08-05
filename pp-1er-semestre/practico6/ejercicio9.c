#include <stdio.h>

int main() {
	int numleido;
	printf("Ingrese un numero entero");
	scanf ("%d",&numleido);
	int esPrimo=1;
	if (numleido>=3){
		int contador =2;
		while( (esPrimo==1) && (contador<numleido)){
			if (numleido%contador==0){
				esPrimo=0;
			}else
				contador++;
			
		}
	}
	if (esPrimo==1){
		printf("Elnumero leido: %d es primo",numleido);
	}else{
		printf("Elnumero leido : %d no es primo",numleido);
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

	
	
	
	
	
	
/*#include <stdio.h>
int main() {
	int n,divisor;
	printf(" Ingrese un numero:  /n");
	scanf(" %d",&n);
	divisor=n-1;
	while ((divisor>1) && (n%divisor!==)) {
		divisor--:
	}
	if ((divisor>1) || (n==1)) {
		printf("El numero no es primo");
	}else {
		printf ("El numero es primo");
	}
	return 0;
}*/

