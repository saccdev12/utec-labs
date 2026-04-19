#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTRefer.h"

using namespace std;
class Investigador; // Declaración adelantada para evitar dependencias circulares.

class Publicacion {
    protected:
        string DOI;
        string titulo;
        DTFecha fecha;
        set<Investigador*> autores; //Los autores son punteros a objetos de tipo Investigador, para evitar copias innecesarias y permitir la relación entre publicaciones e investigadores.
    public:
        //Constructores
        Publicacion();
        Publicacion(string DOI, string titulo, DTFecha fecha);
        
        //Destructor virtual para asegurar la correcta destrucción de objetos derivados.
        virtual ~Publicacion();

        //Getters
        string getDOI() const;
        string getTitulo() const;
        DTFecha getFecha() const;
        
        void agregarAutor(Investigador* autor); // Método para agregar un autor a la publicación, recibe un puntero a un objeto Investigador.

        virtual bool contienePalabra(string palabra) = 0; // Método abstracto, NO se define en el .cpp.

        DTRefer getDT() const; // Método para obtener un objeto de tipo DTRefer que representa la publicación, útil para transferir datos sin exponer la implementación interna.

        void removerInvestigador(Investigador* investigador);
};

#endif // PUBLICACION_H