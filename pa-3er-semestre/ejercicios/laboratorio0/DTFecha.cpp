#include "DTFecha.h"

// constructor x defecto para evitar basura en memoria, siempre tiene fecha válida.
DTFecha::DTFecha(){
    dia = 1;
    mes = 1;
    anio = 2000;
}

// constructor que usaremos para insertar valores al objeto.
DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

// retornamos el día
int DTFecha::getDia() const{
    return dia;
}

// retornamos el mes
int DTFecha::getMes() const{
    return mes;
}

// retornamos el año
int DTFecha::getAnio() const{
    return anio;
}

// sobrecarga del operador para imprimir el objeto como si fuera un string o int.
std::ostream& operator<<(std::ostream& salida, const DTFecha& fecha){
    salida << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return salida;
}

