#include "DTRefer.h"
#include <iostream>
#include <iterator>

using namespace std;

// constructor vacío para evitar basura en memoria, siempre tiene referencia válida.
DTRefer::DTRefer() {}

//constructor completo, para insertar valores al objeto.
DTRefer::DTRefer(std::string DOI, std::string titulo, DTFecha fecha, std::set<std::string> autores){
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


// Sobrecarga del operador.
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

