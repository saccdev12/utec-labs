/*#include <stdio.h>

int main() {
	int num,cont=0,sumanum=0;
	float prom;
	printf ("Por favor coloque un número entero: \n");
	scanf ("%d",&num);
	do{
	sumanum=sumanum+num;
		cont+=1;
		printf ("Por favor coloque un número entero: \n");
		scanf ("%d",&num);
		
	}while (num>=0);
	prom=sumanum/cont;
	printf("La suma de los números y el promedio de estos mismos dan resultado: %d %f",sumanum,prom);
	
	return 0;
}*/

#include <stdio.h>

int main() {
	int num, cont = 0, sumanum = 0;
	float prom;
	
	printf("Por favor, ingrese un número entero (o -1 para terminar): \n");
	scanf("%d", &num);
	
	while (num >= 0) {
		sumanum += num;
		cont++;
		printf("Por favor, ingrese un número entero (o -1 para terminar): \n");
		scanf("%d", &num);
	}
	
	if (cont > 0) {
		prom = (float)sumanum / cont;
		printf("La suma de los números es: %d\n", sumanum);
		printf("El promedio de los números es: %.2f\n", prom);
	} else {
		printf("No se ingresaron números positivos.\n");
	}
	
	return 0;
}
