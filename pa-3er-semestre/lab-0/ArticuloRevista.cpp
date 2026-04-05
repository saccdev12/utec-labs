#include "ArticuloRevista.h"
#include <iostream>
#include <string>
using namespace std;

bool ArticuloRevista::contienePalabra(string palabra) {
    if (getTitulo().find(palabra) != string::npos) {
        return true;
    }
    else if (extracto.find(palabra) != string::npos) {
        return true;
    }

    return false;
}

ArticuloRevista::ArticuloRevista(string doi, string titulo, DTFecha fecha, string revista)
    : Publicacion(doi, titulo, fecha) {
    this->revista = revista; // Cambiá "revista" si tu compañero le puso otro nombre a la variable
}
