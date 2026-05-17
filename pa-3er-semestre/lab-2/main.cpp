#include <iostream>
#include "negocio/Sistema.h"
#include "presentacion/PantallaAltaPublicacion.h"
#include "presentacion/PantallaConsultarPublicaciones.h"
#include "presentacion/PantallaRepresentarPropietario.h"
#include "presentacion/PantallaAltaInmueble.h"

int main() {
    // Se obtiene la instancia única del sistema
    Sistema* sys = Sistema::getInstancia();
    sys->cargarDatosPrueba();
    int opcion;
    do {
        std::cout << "\n========================================" << std::endl;
        std::cout << "   SISTEMA INMOBILIARIO - PROTOTIPO" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Alta de Inmueble (DSS 3)" << std::endl;
        std::cout << "2. Representar Propietario (DSS 5) " << std::endl;
        std::cout << "3. Alta de Publicacion (DSS 9)" << std::endl;
        std::cout << "4. Consultar Publicaciones (DSS 10)" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:

                 PantallaAltaInmueble(sys);
                break;
            case 2:
                 PantallaRepresentarPropietario(sys);
                break;
            case 3:
               pantallaAltaPublicacion(sys);
                break;
            case 4:
                pantallaConsultarPublicaciones(sys);
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
