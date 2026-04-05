#ifndef DTREFER_H
#define DTREFER_H

#include <string>
#include <set>
#include "DTFecha.h"

using namespace std;

class DTRefer {
    private:
        string DOI;
        string titulo;
        set<std::string> autores; //los autores NO son objetos, son strings.
        DTFecha fecha; //la fecha es un objeto, por eso la importamos.

    public:
       DTRefer();
       DTRefer(std::string DOI, std::string titulo, DTFecha fecha, std::set<std::string> autores); //constructor completo.
       
       //Getters
       string getDOI() const;
       string getTitulo() const;
       DTFecha getFecha() const;
       set<std::string> getAutores() const;
        
       //Sobrecarga del operador, accede a atributos que son privados, lo usamos para imprimir el objeto.
       friend ostream& operator<<(ostream& os, const DTRefer& referencia);

};

#endif // DTREFER_H