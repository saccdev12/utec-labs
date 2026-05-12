#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>
#include "Date.h"
using namespace std;

class DTInmueble {
private:
    int codigo;
    string direccion;
    Date fechaAdmin;
public:
    DTInmueble(int cod, string dir, Date fecha);
    int getCodigo();
    string getDireccion();
    Date getFechaAdmin();
    ~DTInmueble();
};
#endif