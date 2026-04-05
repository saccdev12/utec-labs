#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>

class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
    
    public:
        DTFecha();  //contructor vacío para crear fechas por defecto
        DTFecha(int dia, int mes, int anio);
        
        //Getters
        int getDia() const;
        int getMes() const;
        int getAnio() const;

        //Sobrecarga del operador de inserción, muy importante chicos, lo usamos para hacer cosas cómo imprimir la fecha, ya que accede a atributos privados.
        friend std::ostream& operator<<(std::ostream& os, const DTFecha& fecha);
};

#endif // DTFECHA_H