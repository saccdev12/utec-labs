#include <iostream>

#include "TurbinaEspecial.h"
using namespace std;
#include "Turbina.h"
#include "Usina.h"

int main() {
 Turbina *t1 = new Turbina(200,true);
    Turbina *t2 = new Turbina(200,false);
    Turbina *t3 = new TurbinaEspecial(10,200,true);
    Turbina *t4 = new TurbinaEspecial(10,200,true);
    Usina *us1 = new Usina();
    us1->agregarTurbina(t1);
    us1->agregarTurbina(t2);
    us1->agregarTurbina(t3);
    us1->agregarTurbina(t4);
    us1->calcularPotencia();
    return 0;
};