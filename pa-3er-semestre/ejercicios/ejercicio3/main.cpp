#include <iostream>
#include "auto.h"
#include "motor.h"
#include <string>

using namespace std;
int main(){
    Motor *motor1 = new Motor(2000, 50000, "Gasolina");
    Auto *auto1 = new Auto("Toyota", "Corolla", motor1);
    auto1->encender();
    auto1->apagar();
    return 0;
}