#include "DTRefer.h"
#include <iostream>
#include <iterator>
using namespace std;

// constructor vacío para evitar basura en memoria, siempre tiene referencia válida.
DTRefer::DTRefer() {}

//constructor completo, para insertar valores al objeto.
DTRefer::DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores){
    this->DOI = DOI;
    this->titulo = titulo;
    this->fecha = fecha;
    this->autores = autores;
}

// Definimos los Getters.

string DTRefer::getDOI() const {
    return DOI;
}

string DTRefer::getTitulo() const {
    return titulo;
}

DTFecha DTRefer::getFecha() const {
    return fecha;
}

set<string> DTRefer::getAutores() const {
    return autores;
}

ostream& operator<<(ostream& out, const DTRefer& ref) {
    //  Imprimimos el DOI, la flecha, el título y la fecha
    out << ref.DOI << "->" << ref.titulo << " (" << ref.fecha << ")/";

    //  Como 'autores' es un set<string>, hay que recorrerlo
    for (auto it = ref.autores.begin(); it != ref.autores.end(); ++it) {
        out << *it;

        // Si no es el último autor de la lista, ponemos una coma
        if (next(it) != ref.autores.end()) {
            out << ",";
        }
    }

    return out;
}


    

