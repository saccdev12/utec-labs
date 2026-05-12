#include "DTInmueble.h"

DTInmueble::DTInmueble(int cod, string dir, Date fecha) : codigo(cod), direccion(dir), fechaAdmin(fecha) {}

int DTInmueble::getCodigo() { 
    return codigo; 
}
string DTInmueble::getDireccion() { 
    return direccion; 
}
Date DTInmueble::getFechaAdmin() { 
    return fechaAdmin; 
}
DTInmueble::~DTInmueble() {}

