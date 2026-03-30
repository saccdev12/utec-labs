#include "DTRefer.h"
#include <iostream>
#include <iterator>

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

std::string DTRefer::getDOI() const {
    return DOI;
}

std::string DTRefer::getTitulo() const {
    return titulo;
}

DTFecha DTRefer::getFecha() const {
    return fecha;
}

std::set<std::string> DTRefer::getAutores() const {
    return autores;
}

// Sobrecarga del operador.
std::ostream& operator<<(std::ostream& out, const DTRefer& ref) {
    out << ref.DOI << "->" << ref.titulo << "(" << ref.fecha << ")/"; //Básicamente esto define el formato de impresión del objeto, separado x comas y esa vaina.

    for (auto it = ref.autores.begin(); it != ref.autores.end(); ++it) { //Usamos un for para recorrer todos los autores, y los imprimimos separados por comas.
        out << *it;

        if (std::next(it) != ref.autores.end()) { //preguntamos si el iterador actual no es el último, para evitar imprimir una coma al final (integilencia muchachos).
            out << ",";
        }
    }

    return out; //Devolvemos el flujo de salida para permitir encadenar operaciones de inserción.
}
    

