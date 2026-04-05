
#include "PaginaWeb.h"
#include <iostream>
#include <string>
using namespace std;

bool PaginaWeb::contienePalabra(string palabra) {
    if (getTitulo().find(palabra) != string::npos) {
        return true;
    }
    else if (contenidoExtraido.find(palabra) != string::npos) {
        return true;
    }

    return false;
}

// Esto es para DTRefer;
ostream& operator<<(ostream& out, const DTRefer& ref) {
    //  Imprimimos el DOI, la flecha, el título y la fecha
    out << ref.DOI << "->" << ref.titulo << " (" << ref.fecha << ")/";

    //  Como 'autores' es un set<string>, hay que recorrerlo
    for (auto it = ref.autores.begin(); it != ref.autores.end(); ++it) {
        out << *it; // Imprimimos el nombre del autor

        // Si no es el último autor de la lista, ponemos una coma
        if (std::next(it) != ref.autores.end()) {
            out << ",";
        }
    }

    return out;
}

PaginaWeb::PaginaWeb(string doi, string titulo, DTFecha fecha, string url)
    : Publicacion(doi, titulo, fecha) {
    this->url = url; // Cambiá "url" si tu compañero le puso otro nombre
}