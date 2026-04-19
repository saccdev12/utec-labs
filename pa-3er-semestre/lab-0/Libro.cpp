#include "Libro.h"

using namespace std;

bool Libro::contienePalabra(string palabra) {
     if (this->palabrasDestacadas.find(palabra) == this->palabrasDestacadas.end()) {
        return false;
    }

    return true;
}
Libro::Libro(string doi, string titulo, DTFecha fecha, string editorial, set<string> palabrasDestacadas): Publicacion(doi, titulo, fecha) {
    // Acá asumo que a su variable privada le puso 'editorial'
    this->editorial = editorial;
    this->palabrasDestacadas =  palabrasDestacadas;
}
