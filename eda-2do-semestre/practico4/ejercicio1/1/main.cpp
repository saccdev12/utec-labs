#include<iostream>
#include "ejercicio1.h"
using namespace std;
#define T 5

int main () {
	int numeros[] = {18, 18, 31, 6, 22};
	int x;
	cout << "Ingrese ocurrencia:  ";
	cin >> x;
	cout << ocurrencia_Recursiva(numeros, x, T);
	return 0;
}

