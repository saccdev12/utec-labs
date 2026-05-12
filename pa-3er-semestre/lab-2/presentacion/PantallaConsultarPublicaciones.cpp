#include "PantallaConsultarPublicaciones.h"
#include <iostream>
#include <vector>

void pantallaConsultarPublicaciones(ISistema* sys) {
    std::cout << "\n--- CONSULTAR PUBLICACIONES ---\n";

  
    std::cout << "Listando todas las publicaciones activas...\n";
    
    // Obtenemos publicaciones 
    set<DTListaPublicacion*> lista = sys->obtenerPublicaciones(nullptr, Minimo, Ambas);
    
    for (auto p : lista) {
        std::cout << "[" << p->getCodigo() << "] " << p->getTexto() 
                  << " | Precio: " << p->getPrecio() 
                  << " | Inmo: " << p->getNombreInmobiliaria() << "\n";
    }

    // OPT: Si el usuario lo desea (Seleccionar Publicación)
    char deseaDetalle;
    std::cout << "¿Desea ver el detalle de alguna publicacion? (s/n): ";
    std::cin >> deseaDetalle;

    if (deseaDetalle == 's') {
        int codP;
        std::cout << "Ingrese codigo de publicacion: ";
        std::cin >> codP;
        DTInmueble* det = sys->seleccionPublicacion(codP);
        std::cout << "DETALLE -> Direccion: " << det->getDireccion() << "\n";

        // OPT: Si el cliente lo desea (Agendar Visita)
        char deseaAgendar;
        std::cout << "¿Desea agendar una visita? (s/n): ";
        std::cin >> deseaAgendar;

        if (deseaAgendar == 's') {
            set<DTCliente*> clientes = sys->agendarVisita();
            for (auto c : clientes) {
                std::cout << "ID: " << c->getIdCliente() << " | " << c->getNombre() << " " << c->getApellido() << "\n";
            }

            int idC;
            string contacto;
            std::cout << "Seleccione ID de cliente: ";
            std::cin >> idC;
            std::cout << "Forma de contacto: ";
            std::cin >> contacto;
            
            // Se asume fecha actual como pide la letra
            sys->seleccionCliente(idC, {12, 5, 2026}, contacto);
            std::cout << "Visita agendada correctamente.\n";
        }
    }
}