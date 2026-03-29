#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
using namespace std;
class Vehiculo{
	protected:
		string marca;
		string modelo;
		int anio;
	public:
		virtual ~Vehiculo();
		virtual void mostrarDetalle();
		void setMarca(string marca);
		void setModelo(string modelo);
		void setAnio(int anio);
};
#endif