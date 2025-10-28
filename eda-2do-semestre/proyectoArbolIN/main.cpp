#include<iostream>
using namespace std;
#include "estructura.h"
#include "prototipo.h"

int main (int argc, char *argv[]) {
	arboln a;
	a=crearArbol();

	insertarNodo(a,99,70);
	
	
	cout << a->hijo->valor << endl;
	
	return 0;
}

