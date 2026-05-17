
#ifndef LAB_2_INMUEBLE_H
#define LAB_2_INMUEBLE_H

#include <string>
using namespace std;

class Inmueble {
protected:
    int id;
    string direccion;
    int nroPuerta;
    int superficie;
    int anioConstruccion;

public:
    Inmueble(int _id, string _dir, int _nro, int _sup, int _anio)
        : id(_id), direccion(_dir), nroPuerta(_nro), superficie(_sup), anioConstruccion(_anio) {}

    virtual ~Inmueble() {}

    int getId() { return id; }
    string getDireccion() { return direccion; }
    int getNroPuerta() { return nroPuerta; }
    int getSuperficie() { return superficie; }
    int getAnioConstruccion() { return anioConstruccion; }
};

#endif