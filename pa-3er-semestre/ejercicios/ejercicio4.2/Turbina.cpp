
#include "Turbina.h"

#include <iostream>
#include <ostream>
using namespace std;

Turbina::~Turbina() {
    cout << "La turbina ha sido eliminada" << endl;
}

Turbina::Turbina(double potencia,bool activa) {
    this->potencia = potencia;
    this->activa = activa;
}

bool Turbina::getActiva() {
    return this->activa;
}

double Turbina::getPotencia() {
    return this->potencia;
}