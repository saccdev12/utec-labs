#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>

class Articulo {
private:
    int id;
    std::string descripcion;
    int precio;

public:
    Articulo(int id, std::string desc, int precio);

    int getPrecio() const;
};

#endif