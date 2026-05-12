#include "DTCliente.h"
DTCliente::DTCliente(string nom, string ape, int id) : nombre(nom), apellido(ape), idCliente(id) {}

string DTCliente::getNombre() { 
    return nombre; 
}
string DTCliente::getApellido() { 
    return apellido; 
}
int DTCliente::getIdCliente() { 
    return idCliente; 
}
DTCliente::~DTCliente() {}