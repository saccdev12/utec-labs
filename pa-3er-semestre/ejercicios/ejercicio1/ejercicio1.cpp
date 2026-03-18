#include "ejercicio1.h"

// Parte c: Inicialización del atributo de clase [2, 5]
int Automovil::velocidadMaxima = 0;

// Parte a: Constructor por defecto [3]
Automovil::Automovil() {
    this->marca = "Sin marca";
    this->modelo = "Sin modelo";
    this->anioFabricacion = 0;
    this->identificador = 0;
}

// Parte a: Constructor con parámetros [3, 4]
Automovil::Automovil(std::string marca, std::string modelo, int anio, int id) {
    this->marca = marca;
    this->modelo = modelo;
    this->anioFabricacion = anio;
    this->identificador = id;
}

// Parte a: Destructor con mensaje específico [3]
Automovil::~Automovil() {
    std::cout << "El automovil con Id " << identificador << " fue destruido" << std::endl;
}

// Implementación de Getters [1]
std::string Automovil::getMarca() { return marca; }
std::string Automovil::getModelo() { return modelo; }
int Automovil::getAnioFabricacion() { return anioFabricacion; }
int Automovil::getIdentificador() { return identificador; }

// Parte b: Implementación del Setter solicitado [2]
void Automovil::setMarca(std::string nuevaMarca) { this->marca = nuevaMarca; }

// Parte a: Método para mostrar información del objeto [3]
void Automovil::mostrarInformacion() {
    std::cout << "Auto: " << marca << " " << modelo 
              << " (" << anioFabricacion << ") - ID: " << identificador << std::endl;
}

// Parte c: Métodos estáticos para gestionar la velocidad de la clase [2]
void Automovil::setVelocidadMaxima(int vel) { velocidadMaxima = vel; }
void Automovil::mostrarVelocidadMaxima() {
    std::cout << "Velocidad maxima global: " << velocidadMaxima << " km/h" << std::endl;
}