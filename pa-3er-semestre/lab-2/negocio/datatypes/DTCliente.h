#ifndef DTCLIENTE_H
#define DTCLIENTE_H
#include <string>
using namespace std;

class DTCliente {
private:
    string nombre;
    string apellido;
    int idCliente;
public:
    DTCliente(string nom, string ape, int id);
    string getNombre();
    string getApellido();
    int getIdCliente();
    ~DTCliente();
};
#endif