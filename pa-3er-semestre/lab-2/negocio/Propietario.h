
#ifndef LAB_2_PROPIETARIO_H
#define LAB_2_PROPIETARIO_H

#include <string>
#include <map>
#include "Inmueble.h"
using namespace std;

class Propietario {
private:
    string nickname;
    string nombre;
    string email;
    map<int, Inmueble*> inmuebles;
public:
    Propietario(string _nick, string _nom, string _email):nickname(_nick), nombre(_nom), email(_email) {}

    string getNickname(){return nickname;}
    string getNombre(){return nombre;}
    string getEmail(){return email;}

    void agregarInmueble(Inmueble* inmo) {this->inmuebles[inmo->getId()] = inmo;}

    ~Propietario() {}
};


#endif //LAB_2_PROPIETARIO_H
