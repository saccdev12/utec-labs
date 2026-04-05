#include "Libro.h"
#include <iostream>
using namespace std;

bool Libro::contienePalabra(string palabra) {
    if (getTitulo().find(palabra) != string::npos) {
        return true;
    }
    else if (palabrasDestacadas.count(palabra) > 0) {
        return true;
    }

    return false;
}
Libro::Libro(string doi, string titulo, DTFecha fecha, string editorial)
    : Publicacion(doi, titulo, fecha) {
    // Acá asumo que a su variable privada le puso 'editorial'
    this->editorial = editorial;
}
