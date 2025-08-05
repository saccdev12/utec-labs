#include <stdio.h>
#include <math.h>
int main() {
	int num;
	float result;
	char op;
	printf ("Las operaciones posibles son 'e'(exponencial), 'r'(raiz cuadrada),'l'(logarirmo base 10) y 'a'(Valor absoluto) \n");
	printf ("Ingrese el número entero y la operacion a realizar: \n");
	scanf ("%d %c",&num,&op);
	switch (op){
		case ('e'):
			result=exp(num);
			break;
		case ('r'):
			result=sqrt(num);
		    break;
	    case ('l'):
		    result=log10(num);
		    break;
	    case ('a'):
		    result=fabs(num);
		    break;
	    default:
			printf("La opercaion no esta registrada \n");
			
			
		
	}
printf("El resultado de la operación es:%f",result); 

	
	return 0;
}

