#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"
#include <map>
#include <string>
#include <set>
#include "datatypes/DTPropietario.h"
#include "datatypes/DTTipoPublicacion.h"
#include "Propietario.h"

class Sistema : public ISistema {
private:
    static Sistema* instancia;
    Sistema();
    int proximoIdInmueble = 1;
    std::map<std::string, Propietario*> propietarios;
    std::map<int, Inmueble*> inmuebles;
    std::map<std::string, Inmobiliaria*> inmobiliarias;
    Inmobiliaria* inmobiliariaRecordada = nullptr;

public:
    static Sistema* getInstancia();
    void cargarDatosPrueba();

     //Alta Inmueble
    std::set<DTPropietario*> ObtenerPropietarios() override;
    void IngresarDatosInmueble(const std::string& nickname, DTInmuebleDetalles* datos) override;

    //Representar Propietario
    std::set<DTInmobiliaria*> obtenerInmobiliarias() override;
    std::set<DTPropietario*> seleccionInmobiliariaParaRepresentar(const std::string& nickname) override;
    std::set<DTPropietario*> seleccionARepresentar(const std::string& nickname) override;

     // Alta Publicación
    void generarPublicacion(const std::string& nickInmo, int codInmueble, DTPublicacion* datos) override;
    std::set<DTInmueble*> seleccionInmobiliariaParaPublicar(const std::string& nickname) override;

    //ConsultarPublicacion
    std::set<DTListaPublicacion*> obtenerPublicaciones(DTTipoPublicacion tipo, DTRango rango, DTInteres interes) override;
    DTInmueble* seleccionPublicacion(int codPublicacion) override;
    std::set<DTCliente*> obtenerClientes() override;
    void agendarVisita(int idCliente, Date fecha, const std::string& formaContacto, int codPublicacion) override;


};
#endif