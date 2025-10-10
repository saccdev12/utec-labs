#include<iostream>
using namespace std;
#include "prototipos.h"
#include "estructura.h"

int main () {
	arbol a;
	a = creoArbol();
	
	if(esVacio(a)){
		cout << "El Arbol se encuentra vacio" << endl;
	}
	
	insertar(a, 10);
	insertar(a, 5);
	insertar(a,20);
	insertar(a, 15);
	
	cout << "Muestro arbol en preorden: ";
	preorden(a);
	cout << endl << "Muestro el arbol en inorden: ";
	inorden(a);
	cout << endl << "Muestro arbol en postorden: ";
	postorden(a);
	
	cout << endl << "El valor del nodo apuntado es: " << valor(a) << endl;
	
	
	
	return 0;
}
