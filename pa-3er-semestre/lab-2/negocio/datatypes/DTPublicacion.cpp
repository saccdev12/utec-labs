#include "DTPublicacion.h"

DTPublicacion::DTPublicacion(int cod, string txt, float pre) : codInmueble(cod), texto(txt), precio(pre) {}

int DTPublicacion::getCodInmueble() { 
    return codInmueble; 
}

string DTPublicacion::getTexto() { 
    return texto; 
}

float DTPublicacion::getPrecio() { 
    return precio; 
}

DTPublicacion::~DTPublicacion() {}