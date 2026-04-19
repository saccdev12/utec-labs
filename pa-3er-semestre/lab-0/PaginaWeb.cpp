#include "PaginaWeb.h"
#include <iostream>
#include <string>
using namespace std;

bool PaginaWeb::contienePalabra(string palabra) {
    return (contenidoExtraido.find(palabra) != string::npos);
}

PaginaWeb::PaginaWeb(string doi, string titulo, DTFecha fecha, string url, string contenidoExtraido): Publicacion(doi, titulo, fecha) {
    this->url = url;
    this->contenidoExtraido = contenidoExtraido;
}

PaginaWeb::PaginaWeb() : Publicacion(), url(""), contenidoExtraido("") {}