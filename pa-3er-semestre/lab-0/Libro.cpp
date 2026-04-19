#include "Libro.h"

using namespace std;

bool Libro::contienePalabra(string palabra) {
    return (palabrasDestacadas.find(palabra) != palabrasDestacadas.end());
}

Libro::Libro(string doi, string titulo, DTFecha fecha, string editorial, set<string> palabrasDestacadas): Publicacion(doi, titulo, fecha) {
    // Acá asumo que a su variable privada le puso 'editorial'
    this->editorial = editorial;
    this->palabrasDestacadas =  palabrasDestacadas;
}

Libro::Libro() : Publicacion(), editorial(""), palabrasDestacadas() {}
