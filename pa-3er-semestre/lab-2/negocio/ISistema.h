#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <set>
#include <string>
#include "datatypes/DTInmobiliaria.h"
#include "datatypes/DTInmueble.h"
#include "datatypes/DTPublicacion.h"
#include "datatypes/DTListaPublicacion.h"
#include "datatypes/DTCliente.h"
#include "datatypes/DTRango.h"
#include "datatypes/DTInteres.h"
#include "datatypes/DTPropietario.h"
#include "datatypes/DTInmuebleDetalles.h"
#include "datatypes/DTCasa.h"
#include "datatypes/DTApartamento.h"
#include "datatypes/DTInmobiliariaDetalles.h"
#include "datatypes/DTTipoPublicacion.h"


class ISistema {
public:
    //Alta Inmueble
    virtual std::set<DTPropietario*> ObtenerPropietarios() = 0;
    virtual void IngresarDatosInmueble(const std::string& nickname, DTInmuebleDetalles* datos)= 0;

    //Representar Propietario
    virtual std::set<DTInmobiliaria*> obtenerInmobiliarias() = 0;
    virtual std::set<DTPropietario*> seleccionInmobiliariaParaRepresentar(const std::string& nickname) = 0;
    virtual std::set<DTPropietario*> seleccionARepresentar(const std::string& nickname) = 0;

    // Alta Publicación
    virtual std::set<DTInmueble*> seleccionInmobiliariaParaPublicar(const std::string& nickname) = 0;
    virtual void generarPublicacion(const std::string& nickInmo, int codInmueble, DTPublicacion* datos) = 0;

    //ConsultarPublicacion
    virtual std::set<DTListaPublicacion*> obtenerPublicaciones(DTTipoPublicacion tipo, DTRango rango, DTInteres interes) = 0;
    virtual DTInmueble* seleccionPublicacion(int codPublicacion) = 0;
    virtual std::set<DTCliente*> obtenerClientes() = 0;
    virtual void agendarVisita(int idCliente, Date fecha, const std::string& formaContacto, int codPublicacion) = 0;

    virtual ~ISistema() {}
};
#endif