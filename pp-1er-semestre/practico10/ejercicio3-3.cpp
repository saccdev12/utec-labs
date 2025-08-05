#include<iostream>
using namespace std;

void mostrarDivisores(int x);

int main () {
	printf("Ingrese un número: \n");
	int num;
	scanf("%d", &num);
	mostrarDivisores(num);
	return 0;
}

void mostrarDivisores (int x){
	for(int i=1; i<=x; i++){
		if(x % i == 0){
			printf("%d es divisor %d \n", i, x);
		}
	}
}

