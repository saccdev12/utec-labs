#include "ArticuloRevista.h"
#include <iostream>
#include <string>
using namespace std;

bool ArticuloRevista::contienePalabra(string palabra) {
    return (extracto.find(palabra) != string::npos);
}

ArticuloRevista::ArticuloRevista(string doi, string titulo, DTFecha fecha, string revista, string extracto): Publicacion(doi, titulo, fecha) {
    this->revista = revista; // Cambiá "revista" si tu compañero le puso otro nombre a la variable
    this->extracto = extracto;
}

ArticuloRevista::ArticuloRevista() : Publicacion(), revista(""), extracto("") {}
