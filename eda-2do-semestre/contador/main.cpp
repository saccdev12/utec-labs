#include<iostream>
using namespace std;

int contador(int inicio, int fin){
	if (inicio == fin){
		return inicio; //caso base
	}else{
		cout << inicio << endl;
		return contador(inicio+1, fin); //caso recursivo
	}
}

int main () {
	int inicio, fin;
	cout << "Ingrese valor inicial: ";
	cin >> inicio;
	cout << "Ingrese valor final: ";
	cin >> fin;
	cout << contador(inicio, fin);
	return 0;
}

