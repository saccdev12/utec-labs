#ifndef DTPUBLICACION_H
#define DTPUBLICACION_H
#include <string>
using namespace std;

class DTPublicacion {
private:
    int codInmueble;
    string texto;
    float precio;
public:
    DTPublicacion(int cod, string txt, float pre);
    int getCodInmueble();
    string getTexto();
    float getPrecio();
    ~DTPublicacion();
};
#endif