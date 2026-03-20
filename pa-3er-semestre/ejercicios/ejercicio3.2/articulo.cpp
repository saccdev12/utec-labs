#include "articulo.h"

Articulo::Articulo(int id, std::string desc, int precio) {
    this->id = id;
    this->descripcion = desc;
    this->precio = precio;
}

int Articulo::getPrecio() const {
    return precio;
}