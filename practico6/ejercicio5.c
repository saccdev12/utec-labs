#include <stdio.h>

int main() {
	int cont=0;
	float num;
	printf ("Ingrese el numero: \n");
	scanf ("%d",&num);
	while (num>=0){
		cont++;
		printf ("Ingrese el numero: \n");
		scanf ("%d",&num);
	}
	printf ("El numero de datos ingresados es %d.",cont);
	return 0;
}

