#ifndef LAB_PA0_INVESTIGADOR_H
#define LAB_PA0_INVESTIGADOR_H
#include <string>
#include <list>
#include <set>
#include "DTFecha.h"

using namespace std;

class Publicacion;

class Investigador {
private:
    string ORCID;
    string nombre;
    string institucion;

    list<Publicacion*> publicaciones;

public:
    // Constructory Destructor
    Investigador(string orcid, string nom, string inst);
    ~Investigador();

    // Getters y Setters
    string getNombre() const;
    string getORCID() const;

    // Métodos
    string DeString();
    set<string>listarPublicaciones(DTFecha desde, string palabra);

    // Métodos auxiliares
    void agregarPublicacion(Publicacion* p);
    void removerPublicacion(Publicacion* p);


};

#endif //LAB_PA0_INVESTIGADOR_H