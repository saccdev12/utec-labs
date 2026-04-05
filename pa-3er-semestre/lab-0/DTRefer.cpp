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


    

