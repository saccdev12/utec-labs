#ifndef UNTITLED_USINA_H
#define UNTITLED_USINA_H
#include <string>
#include "Turbina.h"
#include <list>
using namespace std;
class Usina {
    private:
    list<Turbina*> turbinas;
    public:
    void agregarTurbina(Turbina *turbinas);
    void calcularPotencia();
    Usina();

};


#endif
