#include <stdio.h>

int main() {
	int numero=1,resultado=0,primeravez=1,operando;
	char tipooperacio= 'N';
	do{
		if (numero==1){
			scanf("%d",&operando);
			numero=0;
			if(primeravez==1){
				primeravez=0;
				resultado=operando;
			}else{
				switch(tipooperacio){
					case('+'):resultado+=operando;break;
					case('-'):resultado-=operando;break;
					case('/'):resultado/=operando;break;
					case('*'):resultado*=operando;break;
				}
			}
		}else{
			scanf (" %c",&tipooperacio);
			numero=1;
		}
	} while(tipooperacio!='=');
	printf("resultado=%d",resultado);
	/*printf ("coloca el primer valor numerico: \n");
	scanf ("%d",&valor);
	
	while (carac != '='){
		resultado+=valor;
		switch(carac){
			case('+'):
				resultado=resultado+valor;
			    break;
			case('-'):
				resultado=resultado-valor;
			    break;
			case('/'):
				resultado=resultado/valor;
			    break;
			case('*'):
				resultado=resultado*valor;
			    break;
		}
	}*/
	
	return 0;
}

