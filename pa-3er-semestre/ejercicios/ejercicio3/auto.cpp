#include <iostream>
#include <string>

#include "auto.h"
#include "motor.h"

using namespace std;

Auto::Auto(string brand, string model, Motor* motor){
    this->marca=brand;
    this->modelo=model;
    this->motor=motor;
}

void Auto::encender(){
    cout <<"El auto fué encendido"<<endl;
    this->motor->iniciar();
}

void Auto::apagar(){
    cout <<"El auto fué apagado"<<endl;
    this->motor->detener();
}

Auto::~Auto(){
    cout <<"El auto fué destruido"<<endl;
}