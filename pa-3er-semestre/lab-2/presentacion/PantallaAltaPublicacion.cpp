#include "PantallaAltaPublicacion.h"
#include <iostream>
#include <string>
#include <set>

void pantallaAltaPublicacion(ISistema* sys) {
    std::cout << "\n--- ALTA DE PUBLICACION ---\n";

    // Obtenemos y mostramos las inmobiliarias disponibles
    set<DTInmobiliaria*> inmos = sys->obtenerInmobiliarias();
    for (auto i : inmos) {
        std::cout << "Nickname: " << i->getNickname() << " | Nombre: " << i->getNombre() << "\n";
    }

    std::cout << "Ingrese el nickname de la inmobiliaria: ";
    string nick;
    std::cin >> nick;

    // Seleccionamos inmobiliarias y mostramos sus inmuebles
    set<DTInmueble*> inmuebles = sys->seleccionInmobiliariaParaPublicar(nick);
    if (inmuebles.empty()) {
        std::cout << "No hay inmuebles administrados por esta inmobiliaria.\n";
        return;
    }

    for (auto inm : inmuebles) {
        std::cout << "Codigo: " << inm->getCodigo() << " | Direccion: " << inm->getDireccion() << "\n";
    }

    // 3. Generar Publicacion
    int codInmueble;
    float precio;
    string texto;
    std::cout << "Ingrese codigo del inmueble: ";
    std::cin >> codInmueble;
    std::cout << "Ingrese texto de la publicacion: ";
    std::cin.ignore();
    getline(std::cin, texto);
    std::cout << "Ingrese precio: ";
    std::cin >> precio;

    DTPublicacion* datos = new DTPublicacion(codInmueble, texto, precio);
    sys->generarPublicacion(nick, codInmueble, datos);

    std::cout << "Publicacion generada con exito.\n";
}