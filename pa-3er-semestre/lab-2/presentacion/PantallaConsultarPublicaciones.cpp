#include "PantallaConsultarPublicaciones.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>

void pantallaConsultarPublicaciones(ISistema* sys) {
    std::cout << "\n--- CONSULTAR PUBLICACIONES ---\n";

  
    std::cout << "Listando todas las publicaciones activas...\n";
    
    // Obtenemos publicaciones 
   // Suponiendo que preguntamos antes:
   std::cout << "Tipo de publicación (0: Venta, 1: Alquiler): ";
   int opcTipo;
   std::cin >> opcTipo;
   DTTipoPublicacion tipo = (opcTipo == 0) ? DTTipoPublicacion::Venta : DTTipoPublicacion::Alquiler;

    std::set<DTListaPublicacion*> lista = sys->obtenerPublicaciones(tipo, Minimo, Ambas);
    
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
            std::set<DTCliente*> clientes = sys->obtenerClientes();
            for (auto c : clientes) {
                std::cout << "ID: " << c->getIdCliente() << " | " << c->getNombre() << " " << c->getApellido() << "\n";
            }

            int idC;
            std::string contacto;
            std::cout << "Seleccione ID de cliente: ";
            std::cin >> idC;
            std::cout << "Forma de contacto: ";
            std::cin >> contacto;

           // Usamos el código de publicación que ya tenemos (codP)
           sys->agendarVisita(idC, {12, 5, 2026}, contacto, codP);  // ← nuevo nombre y parámetro extra
            std::cout << "Visita agendada correctamente.\n";
           }
    }
}