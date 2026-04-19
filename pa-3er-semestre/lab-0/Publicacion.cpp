#include "Publicacion.h"
#include "Investigador.h"
#include <string>
#include <set>

using namespace std;

Publicacion::Publicacion() {}

Publicacion::Publicacion(string DOI, string titulo, DTFecha fecha): DOI(DOI), titulo(titulo), fecha(fecha) {}

Publicacion::~Publicacion() {
    for (auto autor : this->autores) {
        autor->removerPublicacion(this);
    }
}

string Publicacion::getDOI() const {
    return DOI;
}
string Publicacion::getTitulo() const {
    return titulo;
}
DTFecha Publicacion::getFecha() const {
    return fecha;
}

void Publicacion::agregarAutor(Investigador* autor) {
    autores.insert(autor);
}

DTRefer Publicacion::getDT() const {
    set<string> nombresAutores; // Creamos un set de strings para guardar SOLO los nombres de los autores (no los objetos Investigador completos).

    for (auto it = autores.begin(); it != autores.end(); ++it) { //Recorremos el conjunto de autores mediante un for (que son punteros a Investigador)
        // (*it) es un puntero a Investigador
        // ->getNombre() llama al método del objeto Investigador
        // Insertamos el nombre en el set (sin duplicados automáticamente)
        nombresAutores.insert((*it)->getNombre());
    }

    return DTRefer(DOI, titulo, fecha, nombresAutores); //Creamos y retornamos un objeto DTRefer con todos los datos.
}

void Publicacion::removerInvestigador(Investigador* Investigador) {
    this->autores.erase(Investigador);
}