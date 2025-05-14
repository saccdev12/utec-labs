#include <iostream>
using namespace std;
#define N 100

bool esPrimo(int num);

int main() {
	int entrada;
	for(int i=1; i<=N; i++){
		printf("Ingrese un número: \n");
		scanf("%d", &entrada);
		bool resultado = esPrimo(entrada);
		if(resultado == true)
			printf("El número %d es primo \n", entrada);
		else
			printf("El número %d no es primo \n", entrada);
	}
	return 0;
}

bool esPrimo(int num){
	for(int i=2; i<num; i++){
		if(num % i==0)
			return false;
	}
	return true;
}
