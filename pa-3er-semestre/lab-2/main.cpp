#include <iostream>
#include "negocio/Sistema.h"
#include "presentacion/PantallaAltaPublicacion.h"
#include "presentacion/PantallaConsultarPublicaciones.h"

// Prototipos de las pantallas que implementará tu compañero
void pantallaAltaInmueble(ISistema* sys);
void pantallaRepresentarPropietario(ISistema* sys);

int main() {
    // Se obtiene la instancia única del sistema (Singleton) [4]
    ISistema* sys = Sistema::getInstancia();
    
    int opcion;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "   SISTEMA INMOBILIARIO - PROTOTIPO" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Alta de Publicacion (DSS 9)" << std::endl;
        std::cout << "2. Consultar Publicaciones (DSS 10)" << std::endl;
        std::cout << "3. Alta de Inmueble (Pendiente compañero)" << std::endl;
        std::cout << "4. Representar Propietario (Pendiente compañero)" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                pantallaAltaPublicacion(sys);
                break;
            case 2:
                pantallaConsultarPublicaciones(sys);
                break;
            case 3:
                std::cout << "\n[Aviso] Caso de uso no integrado aun.\n";
                // Integra Facundo: pantallaAltaInmueble(sys); 
                break;
            case 4:
                std::cout << "\n[Aviso] Caso de uso no integrado aun.\n";
                // Integra Facundo: pantallaRepresentarPropietario(sys);
                break;
            case 0:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}

// De esto se encarga Facu.
void pantallaAltaInmueble(ISistema* sys) {
    // Completa Facundo
}

void pantallaRepresentarPropietario(ISistema* sys) {
    // Completa Facundo
}