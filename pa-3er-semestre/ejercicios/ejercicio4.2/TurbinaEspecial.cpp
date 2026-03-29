#include "TurbinaEspecial.h"
#include <iostream>
using namespace std;

#include "Turbina.h"
using namespace std;

TurbinaEspecial::TurbinaEspecial(double coef,double potencia,bool activa):Turbina(potencia*coef,activa){
    this->coef  = coef;
    this->activa = activa;
}
