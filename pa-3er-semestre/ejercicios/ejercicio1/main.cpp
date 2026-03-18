#include "ejercicio1.h"
#include <iostream>

int main() {
    // Parte b.1: Crear dos instancias dinámicas utilizando 'new' [3, 6]
    Automovil* auto1 = new Automovil("Toyota", "Corolla", 2022, 101);
    Automovil* auto2 = new Automovil("Ford", "Mustang", 1967, 102);

    // Parte b.2: Enviar mensaje para mostrar información de una instancia [2]
    std::cout << "--- Informacion auto1 ---" << std::endl;
    auto1->mostrarInformacion();

    // Parte b.3: Mostrar solo la marca de una de las instancias [2]
    std::cout << "\nMarca del auto2: " << auto2->getMarca() << std::endl;

    // Parte b.4: Modificar el estado de una instancia [2]
    auto1->setMarca("Lexus");
    std::cout << "Nueva marca auto1: " << auto1->getMarca() << std::endl;

    // Parte c.6: Establecer velocidad máxima de 60 para todos los objetos [2]
    Automovil::setVelocidadMaxima(60);

    // Parte c.7: Mostrar la velocidad máxima de todos los automóviles [2]
    std::cout << "\n--- Datos de Clase ---" << std::endl;
    Automovil::mostrarVelocidadMaxima();

    // Limpieza de memoria (importante para disparar el mensaje del destructor) [3, 6]
    std::cout << "\n--- Destruyendo instancias ---" << std::endl;
    delete auto1;
    delete auto2;

    return 0;
}