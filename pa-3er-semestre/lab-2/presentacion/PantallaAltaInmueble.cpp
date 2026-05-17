#include "PantallaAltaInmueble.h"
#include <iostream>
#include <string>
#include "ISistema.h"
#include "DTCasa.h"
#include "DTApartamento.h"

using namespace std;

void PantallaAltaInmueble(ISistema* sys) {
    string nickname, direccion;
    int nroPuerta, superficie, anio;
    int opcionTipo;

    cout << "=== ALTA DE INMUEBLE ===" << endl;
    cout << "Nickname del propietario: ";
    cin >> nickname;

    cout << "Direccion: ";
    cin >> direccion;
    cout << "Nro de Puerta: ";
    cin >> nroPuerta;
    cout << "Superficie (m2): ";
    cin >> superficie;
    cout << "Anio de construccion: ";
    cin >> anio;

    cout << "\nTipo de Inmueble (1. Casa | 2. Apartamento): ";
    cin >> opcionTipo;

    DTInmuebleDetalles* datosInmueble = nullptr;

    if (opcionTipo == 1) {
        int propHoriz, tipoTechoInt;
        cout << "Es Propiedad Horizontal? (1: Si, 0: No): ";
        cin >> propHoriz;
        cout << "Tipo de techo (0: Dos Aguas, 1: Liviano, etc...): ";
        cin >> tipoTechoInt;

        bool ph = (propHoriz == 1);
        DTTecho techo = static_cast<DTTecho>(tipoTechoInt); // Casteamos el int al Enum

        datosInmueble = new DTCasa(direccion, nroPuerta, superficie, anio, ph, techo);

    } else if (opcionTipo == 2) {
        int nroPiso, ascensor;
        float gastos;
        cout << "Nro de Piso: ";
        cin >> nroPiso;
        cout << "Posee ascensor? (1: Si, 0: No): ";
        cin >> ascensor;
        cout << "Gastos comunes: ";
        cin >> gastos;

        bool poseeAsc = (ascensor == 1);


        datosInmueble = new DTApartamento(direccion, nroPuerta, superficie, anio, nroPiso, poseeAsc, gastos);
    }


    if (datosInmueble != nullptr) {
        sys->IngresarDatosInmueble(nickname, datosInmueble);
        cout << "\nInmueble ingresado con exito!" << endl;


        delete datosInmueble;
    }
}