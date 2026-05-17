#include "Sistema.h"
#include "Inmueble.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Propietario.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include "DTInmuebleDetalles.h"
#include <map>
#include <stdexcept>

Sistema* Sistema::instancia = nullptr;
Sistema::Sistema() {}
Sistema* Sistema::getInstancia() {
    if (instancia == nullptr) instancia = new Sistema();
    return instancia;
}

// 1. Obtener Inmobiliarias (¡Reutilizada para ambos casos de uso!)
std::set<DTInmobiliaria*> Sistema::obtenerInmobiliarias() {
    std::set<DTInmobiliaria*> res;
    for (auto it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Inmobiliaria* inmo = it->second;
        res.insert(new DTInmobiliaria(inmo->getNickname(), inmo->getNombre()));
    }
    return res;
}

// 2. Seleccionar Inmobiliaria y mostrar dueños NO asociados
std::set<DTPropietario*> Sistema::seleccionInmobiliariaParaRepresentar(const std::string& nickname) {
    this->inmobiliariaRecordada = this->inmobiliarias[nickname];

    std::set<DTPropietario*> res;
    for (auto it = propietarios.begin(); it != propietarios.end(); ++it) {
        Propietario* prop = it->second;

        if (!this->inmobiliariaRecordada->tienePropietario(prop->getNickname())) {
            res.insert(new DTPropietario(prop->getNickname(), prop->getNombre(), prop->getEmail()));
        }
    }
    return res;
}

// 3. Vincular y retornar la lista actualizada
std::set<DTPropietario*> Sistema::seleccionARepresentar(const std::string& nickname) {
    Propietario* prop = this->propietarios[nickname];
    this->inmobiliariaRecordada->agregarPropietario(prop);
    return this->seleccionInmobiliariaParaRepresentar(this->inmobiliariaRecordada->getNickname());
}

void Sistema::generarPublicacion(const std::string& nickInmo, int codInmueble, DTPublicacion* datos) {
    // Post-condición: se crea la instancia publicacion
}

std::set<DTListaPublicacion*> Sistema::obtenerPublicaciones(DTTipoPublicacion tipo, DTRango rango, DTInteres interes) {
    std::set<DTListaPublicacion*> res;
    res.insert(new DTListaPublicacion(50, {12, 5, 2026}, "Oferta", 1500, "inmo_1"));
    return res;
}

DTInmueble* Sistema::seleccionPublicacion(int codPublicacion) {
    return new DTInmueble(101, "Calle Falsa 123", {1, 1, 2026});
}

std::set<DTCliente*> Sistema::obtenerClientes() {
    std::set<DTCliente*> res;
    res.insert(new DTCliente("Juan", "Perez", 1));
    return res;
}

void Sistema::agendarVisita(int idCliente, Date fecha, const std::string& formaContacto, int codPublicacion) {
    // Post-condición: Se crea la instancia Agenda con los datos recibidos
    // (puedes usar codPublicacion para asociar la visita a la publicación)
}

std::set<DTPropietario*> Sistema::ObtenerPropietarios() {
    std::set<DTPropietario*> res;
    for (auto it = propietarios.begin(); it != propietarios.end(); it++) {
        Propietario* p = it->second;
        DTPropietario* dt = new DTPropietario(p->getNickname(), p->getNombre(), p->getEmail());
        res.insert(dt);
    }
    return res;
}

void Sistema::IngresarDatosInmueble(const std::string& nickname, DTInmuebleDetalles* datos) {
    if (this->propietarios.count(nickname) == 0) {
        throw std::invalid_argument("Error: No existe un propietario con ese nickname en el sistema.");
    }
    Propietario* prop = this->propietarios[nickname];
    int id = this->proximoIdInmueble;
    Inmueble* nuevo = nullptr;
    DTCasa* dtC = dynamic_cast<DTCasa*>(datos);
    if (dtC != nullptr) {
        nuevo = new Casa(id, dtC->getDireccion(), dtC->getNroPuerta(), dtC->getSuperficie(), dtC->getAnioConstruccion(), dtC->getPropiedadHorizontal(), dtC->getTipoTecho());
    } else {
        DTApartamento* dtA = dynamic_cast<DTApartamento*>(datos);
        if (dtA != nullptr) {
            nuevo = new Apartamento(id, dtA->getDireccion(), dtA->getNroPuerta(), dtA->getSuperficie(), dtA->getAnioConstruccion(), dtA->getNroPiso(), dtA->getPoseeAscesor(), dtA->getGastosComunes());
        }
    }

    if (nuevo != nullptr) {
        prop->agregarInmueble(nuevo);
        this->inmuebles[id] = nuevo;
        this->proximoIdInmueble++;
    }
}

// Implementación temporal para el caso de uso: Alta Publicación
std::set<DTInmueble*> Sistema::seleccionInmobiliariaParaPublicar(const std::string& nickname) {
    std::set<DTInmueble*> res;

    return res;
}

void Sistema::cargarDatosPrueba() {

    Propietario* p1 = new Propietario("juanperez", "Juan Perez", "juan@mail.com");
    this->propietarios["juanperez"] = p1;

    Propietario* p2 = new Propietario("mariagomez", "Maria Gomez", "maria@mail.com");
    this->propietarios["mariagomez"] = p2;
    
    Inmobiliaria* inm1 = new Inmobiliaria("inmo_1", "Propiedades Uruguay", "contacto@propiedades.com.uy");
    this->inmobiliarias["inmo_1"] = inm1;

    Inmobiliaria* inm2 = new Inmobiliaria("inmo_2", "Alquileres MVD", "mvd@alquileres.com");
    this->inmobiliarias["inmo_2"] = inm2;

}