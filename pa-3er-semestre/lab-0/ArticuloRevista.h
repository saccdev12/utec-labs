
#ifndef UNTITLED_ARTICULOREVISTA_H
#define UNTITLED_ARTICULOREVISTA_H
#include "Publicacion.h"
#include <string>
using namespace std;
class ArticuloRevista : public Publicacion{
    private:
        string revista;
        string extracto;
    public:
        ArticuloRevista();
        bool contienePalabra(string palabra) override;
    ArticuloRevista(string doi, string titulo, DTFecha fecha, string revista);
};


#endif //UNTITLED_ARTICULOREVISTA_H