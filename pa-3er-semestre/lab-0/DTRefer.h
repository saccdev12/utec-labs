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
        DTFecha fecha;
        set<string> autores; //los autores NO son objetos, son strings.

    public:
       DTRefer();
       DTRefer(string DOI, string titulo, DTFecha fecha, set<string> autores); //constructor completo.
       
       //Getters
       string getDOI() const;
       string getTitulo() const;
       DTFecha getFecha() const;
       set<string> getAutores() const;
        
       //Sobrecarga del operador, accede a atributos que son privados, lo usamos para imprimir el objeto.
       friend ostream& operator<<(ostream& os, const DTRefer& referencia);

};

#endif // DTREFER_H