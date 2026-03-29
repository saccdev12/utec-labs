#include "Moto.h"
#include<iostream>
using namespace std;

Moto::Moto(){
	
};

void Moto::setCilindrada(int cilindrada){
	this->cilindrada = cilindrada;
};

void Moto::mostrarDetalle(){
	cout<<"Marca: "<<this->marca<<"\n Modelo: "<<this->modelo<<"\n a�o: "<<this->anio<<"\n Cilindrada: "<<this->cilindrada<<endl;	
};
