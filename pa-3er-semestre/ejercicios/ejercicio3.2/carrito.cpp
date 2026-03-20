#include "carrito.h"

CarritoOnLine::CarritoOnLine(std::string user, std::string fecha) {
    this->usuario = user;
    this->fechaHoraCreado = fecha;
}

void CarritoOnLine::agregarArticulo(Articulo art) {
    articulos.push_back(art); 
}

int CarritoOnLine::calcularImporteTotal() const {
    int total = 0;
    for (const auto& art : articulos) {
        total += art.getPrecio();
    }
    return total;
}
