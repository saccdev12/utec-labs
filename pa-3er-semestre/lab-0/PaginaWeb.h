#ifndef UNTITLED_PAGINAWEB_H
#define UNTITLED_PAGINAWEB_H
#include "Publicacion.h"
#include <string>
using namespace std;
class PaginaWeb : public Publicacion{
    private:
        string url;
        string contenidoExtraido;
    public:
        PaginaWeb();
        bool contienePalabra(string palabra) override;
    PaginaWeb(string doi, string titulo, DTFecha fecha, string url);
};


#endif //UNTITLED_PAGINAWEB_H