#include<iostream>
#include "Vehiculo.h"
#include "Auto.h"
#include "Moto.h"
#include "Camion.h"
#include <list>
using namespace std;

void recorrerLista(list<Vehiculo*> vehiculos);
int main (int argc, char *argv[]) {
	Auto *v1 = new Auto();
	v1->setModelo("Elise");
	v1->setAnio(2022);
	v1->setMarca("Citroen");
	v1->setCantidadDePuertas(4);
	v1->mostrarDetalle();
	
	Moto *v2 = new Moto();
	v2->setMarca("Baggio");
	v2->setModelo("Ninja");
	v2->setAnio(2022);
	v2->setCilindrada(32);
	v2->mostrarDetalle();
	
	Camion *v3 = new Camion();
	v3->setMarca("Mercedes");
	v3->setModelo("V500");
	v3->setAnio(2011);
	v3->setCapacidadDeCarga(400);
	
	cout<<"\n Recorro lista: \n"<<endl;
	list<Vehiculo*>vehiculos;
	vehiculos.push_back(v1);
	vehiculos.push_back(v2);
	vehiculos.push_back(v3);
	recorrerLista(vehiculos);
	return 0;
}
void recorrerLista(list<Vehiculo*> vehiculos){
	for(auto vehiculo:vehiculos){
		vehiculo->mostrarDetalle();
	};
};