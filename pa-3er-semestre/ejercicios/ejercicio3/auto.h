#ifndef AUTO_H
#define AUTO_H
#include "motor.h"
#include <string>

using namespace std;

class Auto{
    private:
       string marca;
       string modelo;
       Motor *motor;
    public:
       Auto(string brand, string model, Motor* motor);
       ~Auto();
       void encender();
       void apagar();   
};

#endif