#include<iostream>
using namespace std;
#include "definicion.h"
#include "prototipo.h"
int main (int argc, char *argv[]) {
	cabezal l;
	int valor;
	
	mostrarRetorno(crearLista(l));
	
	/*cout << "Muestro lista desde el principio al fin ";
	mostrarRetorno(mostrar_ppio_fin(l.primero));
	
	cout << "Muestro lista desdel el ultimo al principio ";
	mostrarRetorno(mostrar_fin_ppio(l.ultimo));
	*/
	cout << "Ingrese un numero: ";
	cin >> valor;
	mostrarRetorno(insertar_al_principio(l,valor));
	cout << "Ingrese un numero: ";
	cin >> valor;
	mostrarRetorno(insertar_al_principio(l,valor));
	cout << "Ingrese un numero: ";
	cin >> valor;
	mostrarRetorno(insertar_al_final(l,valor));
	cout << "Muestro lista desde el principio al fin ";
	mostrarRetorno(mostrar_ppio_fin(l.primero));
	cout << "Muestro lista desdel el ultimo al principio ";
	mostrarRetorno(mostrar_fin_ppio(l.ultimo));
	return 0;
}