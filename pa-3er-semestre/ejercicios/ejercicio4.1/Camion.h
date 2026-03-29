#ifndef CAMION_H
#define CAMION_H
#include "Vehiculo.h"
class Camion : public Vehiculo{
private:
	int capacidadDeCarga;
public:
	Camion();
	virtual void mostrarDetalle();
	void setCapacidadDeCarga(int capacidadDeCarga);
};
#endif