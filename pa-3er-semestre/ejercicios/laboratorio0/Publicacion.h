#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTRefer.h"

class Investigador; // Declaración adelantada para evitar dependencias circulares (Forward declaration).

class Publicacion {
    protected:
        std::string DOI;
        std::string titulo;
        DTFecha fecha;
        std::set<Investigador*> autores; //Los autores son punteros a objetos de tipo Investigador, para evitar copias innecesarias y permitir la relación entre publicaciones e investigadores.
    public:
        //Constructores
        Publicacion();
        Publicacion(std::string DOI, std::string titulo, DTFecha fecha, std::set<Investigador*> autores);
        
        //Destructor virtual para asegurar la correcta destrucción de objetos derivados.
        virtual ~Publicacion();

        //Getters
        std::string getDOI() const;
        std::string getTitulo() const;
        DTFecha getFecha() const;
        
        void agregarAutor(Investigador* autor); // Método para agregar un autor a la publicación, recibe un puntero a un objeto Investigador.

        virtual bool contienePalabra(std::string palabra) = 0; // Método abstracto, NO se define en el .cpp.

        DTRefer getDT() const; // Método para obtener un objeto de tipo DTRefer que representa la publicación, útil para transferir datos sin exponer la implementación interna.
};

#endif // PUBLICACION_H