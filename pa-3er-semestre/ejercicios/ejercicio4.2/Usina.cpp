#include "Usina.h"
#include <iostream>
using namespace std;

void Usina :: agregarTurbina(Turbina *turbinas) {
    this->turbinas.push_back(turbinas);
}

void Usina::calcularPotencia() {
    double total = 0;
    for (auto recorroTurbina:this->turbinas) {
        if (recorroTurbina->getActiva() == true) {
             total += recorroTurbina->getPotencia();
        }
    }
    cout<<"La potencia total es de: "<<total<<endl;
}

Usina::Usina() {

}