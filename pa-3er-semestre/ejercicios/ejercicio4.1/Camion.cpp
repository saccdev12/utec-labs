#include "Camion.h"
#include<iostream>
using namespace std;

Camion::Camion(){
	
};

void Camion::setCapacidadDeCarga(int capacidadDeCarga){
	this->capacidadDeCarga= capacidadDeCarga;
}

void Camion::mostrarDetalle(){
	cout<<"Marca: "<<this->marca<<"\n Modelo: "<<this->modelo<<"\n a�o: "<<this->anio<<"\n Capacidad de Carga: "<<this->capacidadDeCarga<<endl;
};