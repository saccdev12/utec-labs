#include "motor.h"
#include <iostream>

Motor::Motor(int cilindro, int kilometros, string combust){
     this->cilindrada=cilindro;
     this->kilometraje=kilometros;
     this->combustible=combust;
}

void Motor::iniciar(){
   cout <<"El motor fué iniciado"<<endl;
}

void Motor::detener(){
   cout <<"El motor fué detenido"<<endl;
}

Motor::~Motor(){
    cout <<"El motor fué destruido"<<endl;
}