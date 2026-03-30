#include "Publicacion.h"
#include "Investigador.h"

// Constructor vacío para evitar basura en memoria, siempre tiene una publicación válida.
Publicacion::Publicacion() {}

// Constructor que usaremos para insertar valores al objeto.
Publicacion::Publicacion(std::string DOI, std::string titulo, DTFecha fecha)
    : DOI(DOI), titulo(titulo), fecha(fecha) {}

// Destructor virtual para asegurar la correcta destrucción de objetos derivados.
Publicacion::~Publicacion() {}    

//Definimos los Getters.
std::string Publicacion::getDOI() const {
    return DOI;
}
std::string Publicacion::getTitulo() const {
    return titulo;
}
DTFecha Publicacion::getFecha() const {
    return fecha;
}

// definimos el método para agregar un autor a la publicación, recibe un puntero a un objeto Investigador.
void Publicacion::agregarAutor(Investigador* autor) {
    autores.insert(autor);
}

DTRefer Publicacion::getDT() const {
    std::set<std::string> nombresAutores; // Creamos un set de strings para guardar SOLO los nombres de los autores (no los objetos Investigador completos).

    for (auto it = autores.begin(); it != autores.end(); ++it) { //Recorremos el conjunto de autores mediante un for (que son punteros a Investigador)

        // (*it) es un puntero a Investigador
        // ->getNombre() llama al método del objeto Investigador
        // Insertamos el nombre en el set (sin duplicados automáticamente)
        nombresAutores.insert((*it)->getNombre());
    }

    return DTRefer(DOI, titulo, fecha, nombresAutores); //Creamos y retornamos un objeto DTRefer con todos los datos.
}