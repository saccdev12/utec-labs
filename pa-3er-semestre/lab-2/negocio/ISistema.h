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

class ISistema {
public:
    // Alta Publicacion
    virtual set<DTInmobiliaria*> obtenerInmobiliarias() = 0;
    virtual set<DTInmueble*> seleccionInmobiliaria(string nickname) = 0;
    virtual void generarPublicacion(string nickInmo, int codInmueble, DTPublicacion* datos) = 0;

    // Consultar Publicaciones
    virtual set<DTListaPublicacion*> obtenerPublicaciones(DTPublicacion* tipo, DTRango rango, DTInteres interes) = 0;
    virtual DTInmueble* seleccionPublicacion(int codPublicacion) = 0;
    virtual set<DTCliente*> agendarVisita() = 0;
    virtual void seleccionCliente(int idCliente, Date fecha, string formaContacto) = 0;

    // Espacio reservado para Facundo (Alta Inmueble y Representar Propietario)
    virtual ~ISistema() {}
};
#endif