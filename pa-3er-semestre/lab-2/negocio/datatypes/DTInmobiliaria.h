#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H
#include <string>
using namespace std;

class DTInmobiliaria {
private:
    string nickname;
    string nombre;
public:
    DTInmobiliaria(string nick, string nom);
    string getNickname();
    string getNombre();
    ~DTInmobiliaria();
};
#endif