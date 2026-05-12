#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"

class Sistema : public ISistema {
private:
    static Sistema* instancia;
    Sistema();
public:
    static Sistema* getInstancia();
    set<DTInmobiliaria*> obtenerInmobiliarias();
    set<DTInmueble*> seleccionInmobiliaria(string nickname);
    void generarPublicacion(string nickInmo, int codInmueble, DTPublicacion* datos);
    set<DTListaPublicacion*> obtenerPublicaciones(DTPublicacion* tipo, DTRango rango, DTInteres interes);
    DTInmueble* seleccionPublicacion(int codPublicacion);
    set<DTCliente*> agendarVisita();
    void seleccionCliente(int idCliente, Date fecha, string formaContacto);
};
#endif