#include "Sistema.h"

Sistema* Sistema::instancia = nullptr;
Sistema::Sistema() {}
Sistema* Sistema::getInstancia() {
    if (instancia == nullptr) instancia = new Sistema();
    return instancia;
}

// Implementación con datos de prueba (Mocks)
set<DTInmobiliaria*> Sistema::obtenerInmobiliarias() {
    set<DTInmobiliaria*> res;
    res.insert(new DTInmobiliaria("inmo_1", "Propiedades Uruguay"));
    return res;
}

set<DTInmueble*> Sistema::seleccionInmobiliaria(string nickname) {
    set<DTInmueble*> res;
    res.insert(new DTInmueble(101, "Calle Falsa 123", {1, 1, 2026}));
    return res;
}

void Sistema::generarPublicacion(string nickInmo, int codInmueble, DTPublicacion* datos) {
    // Post-condición: se crea la instancia publicacion
}

set<DTListaPublicacion*> Sistema::obtenerPublicaciones(DTPublicacion* tipo, DTRango rango, DTInteres interes) {
    set<DTListaPublicacion*> res;
    res.insert(new DTListaPublicacion(50, {12, 5, 2026}, "Oferta", 1500, "inmo_1"));
    return res;
}

DTInmueble* Sistema::seleccionPublicacion(int codPublicacion) {
    return new DTInmueble(101, "Calle Falsa 123", {1, 1, 2026});
}

set<DTCliente*> Sistema::agendarVisita() {
    set<DTCliente*> res;
    res.insert(new DTCliente("Juan", "Perez", 1));
    return res;
}

void Sistema::seleccionCliente(int idCliente, Date fecha, string formaContacto) {
    // Post-condición: Se crea la instancia Agenda
}