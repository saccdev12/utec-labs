#include <stdio.h>

int main() {
	float salariom=0,salarioj=0,liquidacion=0,valordejornales=0;
	int jornalero=0,mensual=0,valor,jornales=0;
	printf ("Ingrese 0 para agregar un empleado mensual a la liquidación.\n");
    printf ("Ingrese 1 para agregar un empleado jornalero a la liquidación.\n");
	printf ("Ingrese 2 para consultar la liquidación.\n");
	printf ("Ingrese 3 para salir.\n");
	scanf ("%d",&valor);
	while (valor!=3 ) {
		switch (valor){
		    case (0):
				printf ("Ingrese el salario mensual del empleado");
				scanf("%f",&salariom);
				liquidacion+=salariom;
				mensual++;
				break;
		    case (1):
				printf ("Ingrese la cantidad de jornales seguidos del valor del jornal: ");
				scanf("%d %f",&jornales,&salarioj);
				jornalero++;
				liquidacion=liquidacion+jornales*salarioj;
				break;
			case (2):
			    printf("La liquidación total es: %f con  %d empleados mensuales y %d jornaleros.\n",liquidacion,mensual,jornalero);
				break;
			}
		printf ("Ingrese 0 para agregar un empleado mensual a la liquidación.\n");
		printf ("Ingrese 1 para agregar un empleado jornalero a la liquidación.\n");
		printf ("Ingrese 2 para consultar la liquidación.\n");
		printf ("Ingrese 3 para salir.\n");
		scanf ("%d",&valor);
		}
	if (valor==3 ){
		printf("Total de la liquidación mensual es: %f ",salariom);
	}
	return 0;
}

