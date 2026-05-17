#include "DTInmobiliaria.h"

DTInmobiliaria::DTInmobiliaria(string nick, string nom) : nickname(nick), nombre(nom) {
}

string DTInmobiliaria::getNickname() { 
    return nickname; 
}

string DTInmobiliaria::getNombre() { 
    return nombre; 
}

DTInmobiliaria::~DTInmobiliaria() {
}