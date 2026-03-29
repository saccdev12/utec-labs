#include<iostream>
#include "Auto.h"
using namespace std;
Auto::Auto(){
	
};

void Auto::setCantidadDePuertas(int cantidadDePuertas){
	this->cantidadDePuertas = cantidadDePuertas;
}

void Auto::mostrarDetalle(){
	cout<<"Marca: "<<this->marca<<"\n Modelo: "<<this->modelo<<"\n a�o: "<<this->anio<<"\n Cantidad de puertas: "<<this->cantidadDePuertas<<endl;
};