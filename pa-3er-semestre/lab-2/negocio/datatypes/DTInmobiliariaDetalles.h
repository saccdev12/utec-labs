//
// Created by Facundo Caraballo Beledo on 16/5/26.
//

#ifndef LAB_2_DTINMOBILIARIADETALLES_H
#define LAB_2_DTINMOBILIARIADETALLES_H


#include <string>
#include <map>
#include "Propietario.h"
using namespace std;

class Inmobiliaria {
private:
    string nickname;
    string nombre;
    string email;

    map<string, Propietario*> propietariosRepresentados;

public:
    Inmobiliaria(string _nick, string _nom, string _email)
        : nickname(_nick), nombre(_nom), email(_email) {}

    string getNickname() { return nickname; }
    string getNombre() { return nombre; }
    string getEmail() { return email; }


    void agregarPropietario(Propietario* p) {
        propietariosRepresentados[p->getNickname()] = p;
    }


    bool tienePropietario(string nick) {
        return propietariosRepresentados.find(nick) != propietariosRepresentados.end();
    }
};


#endif //LAB_2_DTINMOBILIARIADETALLES_H
