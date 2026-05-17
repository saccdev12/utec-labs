#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"
#include <map>
#include <string>
#include <set>
#include "datatypes/DTPropietario.h"
#include "Propietario.h"

class Sistema : public ISistema {
private:
    static Sistema* instancia;
    Sistema();
    int proximoIdInmueble = 1;
    map<string, Propietario*> propietarios;
    map<int, Inmueble*> inmuebles;
    map<string, Inmobiliaria*> inmobiliarias;
    Inmobiliaria* inmobiliariaRecordada = nullptr;

public:
    static Sistema* getInstancia();

     //Alta Inmueble
    set<DTPropietario*> ObtenerPropietarios();
    void IngresarDatosInmueble(string nickname, DTInmuebleDetalles* datos);

    //Representar Propietario
    set<DTInmobiliaria*> obtenerInmobiliarias();
    set<DTPropietario*> seleccionInmobiliariaParaRepresentar(string nickname);
    set<DTPropietario*> seleccionARepresentar(string nickname);

     // Alta Publicación
    void generarPublicacion(string nickInmo, int codInmueble, DTPublicacion* datos);
    set<DTInmueble*> seleccionInmobiliariaParaPublicar(string nickname);

    //ConsultarPublicacion
    set<DTListaPublicacion*> obtenerPublicaciones(DTPublicacion* tipo, DTRango rango, DTInteres interes);
    DTInmueble* seleccionPublicacion(int codPublicacion);
    set<DTCliente*> agendarVisita();
    void seleccionCliente(int idCliente, Date fecha, string formaContacto);

    void cargarDatosPrueba();


};
#endif