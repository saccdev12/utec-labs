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


    

