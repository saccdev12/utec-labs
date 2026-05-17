#ifndef DTLISTAPUBLICACION_H
#define DTLISTAPUBLICACION_H
#include <string>
#include "Date.h"
using namespace std;

class DTListaPublicacion {
private:
    int codigo;
    Date fecha;
    string texto;
    float precio;
    string nombreInmobiliaria;
public:
    DTListaPublicacion(int cod, Date f, string txt, float pre, string inmo);
    int getCodigo();
    Date getFecha();
    string getTexto();
    float getPrecio();
    string getNombreInmobiliaria();
    ~DTListaPublicacion();
};
#endif