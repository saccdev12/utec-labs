/*#include <stdio.h>

int main() {
	int num,cont=0,sumanum=0;
	float prom;
	printf ("Por favor coloque un n�mero entero: \n");
	scanf ("%d",&num);
	do{
	sumanum=sumanum+num;
		cont+=1;
		printf ("Por favor coloque un n�mero entero: \n");
		scanf ("%d",&num);
		
	}while (num>=0);
	prom=sumanum/cont;
	printf("La suma de los n�meros y el promedio de estos mismos dan resultado: %d %f",sumanum,prom);
	
	return 0;
}*/

#include <stdio.h>

int main() {
	int num, cont = 0, sumanum = 0;
	float prom;
	
	printf("Por favor, ingrese un n�mero entero (o -1 para terminar): \n");
	scanf("%d", &num);
	
	while (num >= 0) {
		sumanum += num;
		cont++;
		printf("Por favor, ingrese un n�mero entero (o -1 para terminar): \n");
		scanf("%d", &num);
	}
	
	if (cont > 0) {
		prom = (float)sumanum / cont;
		printf("La suma de los n�meros es: %d\n", sumanum);
		printf("El promedio de los n�meros es: %.2f\n", prom);
	} else {
		printf("No se ingresaron n�meros positivos.\n");
	}
	
	return 0;
}
