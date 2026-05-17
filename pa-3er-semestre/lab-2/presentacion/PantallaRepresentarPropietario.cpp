//
// Created by Facundo Caraballo Beledo on 15/5/26.
//

#include "PantallaRepresentarPropietario.h"
#include <iostream>
#include <string>
#include <set>
#include "ISistema.h"
#include "DTInmobiliaria.h"
#include "DTPropietario.h"

using namespace std;

void PantallaRepresentarPropietario(ISistema* sys) {
    cout << "=== REPRESENTAR PROPIETARIO ===" << endl;

    set<DTInmobiliaria*> inmos = sys->obtenerInmobiliarias();
    if (inmos.empty()) {
        cout << "No hay inmobiliarias registradas en el sistema." << endl;
        return;
    }

    cout << "\n-- Lista de Inmobiliarias --" << endl;
    for (auto it = inmos.begin(); it != inmos.end(); ++it) {
        cout << "- Nickname: " << (*it)->getNickname() << " | Nombre: " << (*it)->getNombre() << endl;
        delete *it;
    }

    string nickInmobiliaria;
    cout << "\nIngrese el nickname de la inmobiliaria a seleccionar: ";
    cin >> nickInmobiliaria;

    set<DTPropietario*> propsNoAsociados = sys->seleccionInmobiliariaParaRepresentar(nickInmobiliaria);
    if (propsNoAsociados.empty()) {
        cout << "Esta inmobiliaria ya representa a todos los propietarios." << endl;
        return;
    }

    cout << "\n-- Propietarios NO asociados --" << endl;
    for (auto it = propsNoAsociados.begin(); it != propsNoAsociados.end(); ++it) {
        cout << "- Nickname: " << (*it)->getNickname() << " | Nombre: " << (*it)->getNombre() << endl;
        delete *it;
    }

    string nickPropietario;
    cout << "\nIngrese el nickname del propietario que desea representar: ";
    cin >> nickPropietario;

    set<DTPropietario*> listaActualizada = sys->seleccionARepresentar(nickPropietario);

    cout << "\n¡Vinculacion exitosa! La lista de propietarios no asociados ahora es:" << endl;
    for (auto it = listaActualizada.begin(); it != listaActualizada.end(); ++it) {
        cout << "- Nickname: " << (*it)->getNickname() << " | Nombre: " << (*it)->getNombre() << endl;
        delete *it;
    }
}
