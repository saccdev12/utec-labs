#include "DTListaPublicacion.h"

DTListaPublicacion::DTListaPublicacion(int cod, Date f, string txt, float pre, string inmo) : codigo(cod), fecha(f), texto(txt), precio(pre), nombreInmobiliaria(inmo) {}

int DTListaPublicacion::getCodigo() { 
    return codigo; 
}
Date DTListaPublicacion::getFecha() { 
    return fecha; 
}
string DTListaPublicacion::getTexto() { 
    return texto; 
}
float DTListaPublicacion::getPrecio() { 
    return precio; 
}
string DTListaPublicacion::getNombreInmobiliaria() { 
    return nombreInmobiliaria; 
}
DTListaPublicacion::~DTListaPublicacion() {}