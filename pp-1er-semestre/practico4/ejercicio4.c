#include <stdio.h>

int main() {
	int n1,n2;
	char op;
	printf("Ingrese dos numeros enteros y la operacion separada por un espacio \n");
	scanf ("%d%d %c",&n1,&n2,&op);
	switch (op)
	{
		
		case '+':
			printf("El resultado de la operacion es %d",n1+n2);
			break;
	    case '-':
			printf("El resultado de la operacion es %d",n1-n2);
		    break;
	    case '*':
	    case 'x':
		    printf("El resultado de la operacion es %d",n1*n2);
		    break;
	    case '/':
		    printf("El resultado de la operacion es %d",n1/n2);
			break;
	    case '%':
		    printf("El resultado de la operacion es %d",n1%n2);
		    break;
	    default:
			printf("La operacion no esta registrada.");
	}
	return 0;
}

