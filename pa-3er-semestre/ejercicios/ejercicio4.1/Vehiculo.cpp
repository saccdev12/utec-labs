#include "Vehiculo.h"
#include<iostream>
using namespace std;
#include <list>
#include "Vehiculo.h"


Vehiculo::~Vehiculo(){
	
};

void Vehiculo::setMarca(string marca){
	this->marca = marca;
};

void Vehiculo::setModelo(string modelo){
	this->modelo = modelo;
};

void Vehiculo::setAnio(int anio){
	this->anio = anio;
};

void Vehiculo::mostrarDetalle(){
	
};