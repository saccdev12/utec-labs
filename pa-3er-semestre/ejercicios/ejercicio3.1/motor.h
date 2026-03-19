#ifndef MOTOR_H
#define MOTOR_H

#include <string>
using namespace std;

class Motor {
    private:
       int cilindrada;
       int kilometraje;
       string combustible;
    public:
       Motor(int cilindro, int kilometros, string combust);
       ~Motor();
       void iniciar();
       void detener();   
};

#endif