#ifndef ISISTEMA_H
#define ISISTEMA_H
#include <set>
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


class ISistema {
public:
    //Alta Inmueble
    virtual set<DTPropietario*> ObtenerPropietarios() = 0;
    virtual void IngresarDatosInmueble(string nickname, DTInmuebleDetalles* datos)= 0;

    //Representar Propietario
    virtual set<DTInmobiliaria*> obtenerInmobiliarias() = 0;
    virtual set<DTPropietario*> seleccionInmobiliariaParaRepresentar(string nickname) = 0;
    virtual set<DTPropietario*> seleccionARepresentar(string nickname) = 0;

    // Alta Publicación
    virtual set<DTInmueble*> seleccionInmobiliariaParaPublicar(string nickname) = 0;
    virtual void generarPublicacion(string nickInmo, int codInmueble, DTPublicacion* datos) = 0;

    //ConsultarPublicacion
    virtual set<DTListaPublicacion*> obtenerPublicaciones(DTPublicacion* tipo, DTRango rango, DTInteres interes) = 0;
    virtual DTInmueble* seleccionPublicacion(int codPublicacion) = 0;
    virtual set<DTCliente*> agendarVisita() = 0;
    virtual void seleccionCliente(int idCliente, Date fecha, string formaContacto) = 0;


    virtual ~ISistema() {}
};
#endif