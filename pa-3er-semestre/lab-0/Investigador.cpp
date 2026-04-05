//
// Created by Facundo Caraballo Beledo on 3/4/26.
//
#include "Investigador.h"
#include "Publicacion.h"
#include <iostream>
#include <string>

using namespace std;

Investigador::Investigador(string orcid, string nom, string inst) {
    this->ORCID = orcid;
    this->nombre = nom;
    this->institucion = inst;
}

Investigador::~Investigador() {
    cout<<"El investigador ha sido destruido"<<endl;
}

string Investigador::DeString() {
    return this->ORCID + "->" + this->nombre + "/" + this->institucion;
}

set<string> Investigador::listarPublicaciones(DTFecha desde, string palabra) {
    set<string> resultado;

    for (Publicacion* p : publicaciones) {
        DTFecha fechaPub = p->getFecha();
        bool esPosterior = false;

        // Comparo: Año, Mes, Día
        if (fechaPub.getAnio() > desde.getAnio()) {
            esPosterior = true;
        } else if (fechaPub.getAnio() == desde.getAnio()) {
            if (fechaPub.getMes() > desde.getMes()) {
                esPosterior = true;
            } else if (fechaPub.getMes() == desde.getMes()) {
                if (fechaPub.getDia() >= desde.getDia()) {
                    esPosterior = true;
                }
            }
        }

        if (esPosterior && p->contienePalabra(palabra)) {
            resultado.insert(p->getDOI());
        }
    }

    return resultado;
}


void Investigador::agregarPublicacion(Publicacion* p) {
    this->publicaciones.push_back(p);
}

void Investigador::removerPublicacion(Publicacion* p) {
    this->publicaciones.remove(p);
}

string Investigador::getNombre() const {
    return this->nombre;
}