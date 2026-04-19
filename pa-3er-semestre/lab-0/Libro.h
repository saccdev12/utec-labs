#ifndef UNTITLED_LIBRO_H
#define UNTITLED_LIBRO_H
#include "Publicacion.h"
#include <set>
#include <string>


using namespace std;

class Libro : public Publicacion{
    private:
        string editorial;
        set<string> palabrasDestacadas;
    public:
        Libro();
        bool contienePalabra(string palabra) override;
    Libro(string doi, string titulo, DTFecha fecha, string editorial, set<string> palabrasDestacadas);
};


#endif //UNTITLED_LIBRO_H