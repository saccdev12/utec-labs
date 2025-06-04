#include<iostream>
int comprobador (char a );

int main () {
	char entrada;
	int valor;
	do{
		scanf(" %c",&entrada);
		valor=comprobador(entrada);
		switch (valor){
			case 1:
			    printf("El caracter ingresado es un número\n");
		        break;
			case 2:
		        printf("El caracter ingresado es una letra\n");
				break;
			case 3:
				printf("El caracter es desconocido\n");
		}
	} while(entrada!='-');
	
	return 0;
}
int comprobador (char a ){
	if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
		return 2;
	else if (a>='0'&&a<='9')
		return 1;
	else
		return 3;
}
