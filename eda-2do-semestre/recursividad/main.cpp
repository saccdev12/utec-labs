#include<iostream>
using namespace std;

int factorial(int numero){
	if (numero == 0){
		return 1; //caso base
	}else {
		return numero * factorial(numero-1);
	}
}



int main () {
	int numero;
	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << "El factorial de "<< numero <<" es "<< factorial(numero);
	return 0;
}

