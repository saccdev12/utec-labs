#ifndef EJERCICIO1_H
#define EJERCICIO1_H

#include <iostream>
#include <string>

class Automovil {
private:
    // Parte a: Atributos de instancia privados (Encapsulamiento) [1]
    std::string marca;
    std::string modelo;
    int anioFabricacion;
    int identificador;

    // Parte c: Atributo de clase compartido por todas las instancias [2]
    static int velocidadMaxima;

public:
    // Parte a: Constructores [3]
    Automovil(); // Por defecto
    Automovil(std::string marca, std::string modelo, int anio, int id);

    // Parte a: Destructor [3]
    ~Automovil();

    // Parte a: Operaciones para acceder al estado (Getters) [1]
    std::string getMarca();
    std::string getModelo();
    int getAnioFabricacion();
    int getIdentificador();

    // Parte b: Modificador necesario para alterar el estado [2]
    void setMarca(std::string nuevaMarca);

    // Parte a: Operación para mostrar información de la instancia [3]
    void mostrarInformacion();

    // Parte c: Operaciones de clase para la velocidad máxima [2]
    static void setVelocidadMaxima(int vel);
    static void mostrarVelocidadMaxima();
};

#endif