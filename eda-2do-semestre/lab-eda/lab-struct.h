#ifndef LAB_STRUCT_H
#define LAB_STRUCT_H

#include <cstring>

enum TipoRet { OK, ERROR, NO_IMPLEMENTADA };

// Nodo para almacenar una línea de texto
struct Linea {
    char* texto;
    Linea* siguiente;
    unsigned int numero;
    
    Linea(const char* txt, unsigned int num);
    ~Linea();
};

// Nodo para almacenar una modificación (inserción o borrado)
struct Modificacion {
    char tipo; // 'I' para inserción, 'B' para borrado
    unsigned int numeroLinea;
    char* texto; // solo para inserciones
    Modificacion* siguiente;
    
    Modificacion(char t, unsigned int num, const char* txt = nullptr);
    ~Modificacion();
};

// Nodo para una versión del archivo
struct Version {
    char* id;
    Linea* lineas;
    Modificacion* modificaciones;
    Version* padre;
    Version* primeraSubversion;
    Version* siguienteVersion;
    unsigned int numLineas;
    
    Version(const char* versionId, Version* parent = nullptr);
    ~Version();
    
    void insertarLinea(unsigned int nroLinea, const char* texto);
    void borrarLinea(unsigned int nroLinea);
    void agregarModificacion(char tipo, unsigned int nroLinea, const char* texto = nullptr);
    Linea* obtenerLinea(unsigned int nroLinea);
    void construirTextoCompleto();
};

// Estructura principal del archivo
struct Archivo {
    char* nombre;
    Version* primeraVersion;
    unsigned int contadorVersiones;
    
    Archivo(const char* nom);
    ~Archivo();
    
    Version* buscarVersion(const char* versionId);
    Version* buscarVersionRecursivo(Version* actual, const char* versionId);
    bool versionTieneSubversiones(Version* version);
    void reordenarVersiones(Version* padre);
};

#endif