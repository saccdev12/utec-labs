#ifndef LAB_2_DTPROPIETARIO_H
#define LAB_2_DTPROPIETARIO_H
#include <string>
using namespace std;

class DTPropietario {
private:
    string nickname;
    string nombre;
    string email;
    public:
    DTPropietario(string _nick, string _nom, string _em) : nickname(_nick), nombre(_nom), email(_em) {}

    string getNickname() {return nickname;}
    string getNombre() {return nombre;}
    string getEmail() {return email;}

    ~DTPropietario() {}
};


#endif //LAB_2_DTPROPIETARIO_H
