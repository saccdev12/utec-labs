#ifndef CARRITO_H
#define CARRITO_H

#include <string>
#include <list>
#include "articulo.h" 

class CarritoOnLine {
private:
    std::string usuario;
    std::string fechaHoraCreado;
    std::list<Articulo> articulos; 
public:
    CarritoOnLine(std::string user, std::string fecha);
    void agregarArticulo(Articulo art);
    int calcularImporteTotal() const;
};

#endif