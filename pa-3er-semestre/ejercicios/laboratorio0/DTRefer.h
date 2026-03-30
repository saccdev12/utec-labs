#ifndef DTREFER_H
#define DTREFER_H

#include <string>
#include <set>
#include "DTFecha.h"

class DTRefer {
    private:
        std::string DOI;
        std::string titulo;
        std::set<std::string> autores; //los autores NO son objetos, son strings.

    public:
       DTRefer();
       DTRefer(std::string DOI, std::string titulo, DTFecha fecha, std::set<std::string> autores); //constructor completo.
       
       //Getters
       std::string getDOI() const;
       std::string getTitulo() const;
       DTFecha getFecha() const;
       std::set<std::string> getAutores() const;
        
       //Sobrecarga del operador, accede a atributos que son privados, lo usamos para imprimir el objeto.
       friend std::ostream& operator<<(std::ostream& os, const DTRefer& referencia);

};

#endif // DTREFER_H