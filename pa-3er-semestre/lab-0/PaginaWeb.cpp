#include "PaginaWeb.h"
#include <iostream>
#include <string>
using namespace std;

bool PaginaWeb::contienePalabra(string palabra) {
     if (contenidoExtraido.find(palabra) != string::npos) {
        return true;
    }

    return false;
}

PaginaWeb::PaginaWeb(string doi, string titulo, DTFecha fecha, string url, string contenidoExtraido): Publicacion(doi, titulo, fecha) {
    this->url = url;
    this->contenidoExtraido = contenidoExtraido;
}