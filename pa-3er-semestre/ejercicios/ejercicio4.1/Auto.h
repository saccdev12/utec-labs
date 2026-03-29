#ifndef AUTO_H
#define AUTO_H
#include "Vehiculo.h"
class Auto : public Vehiculo{
private:
	int cantidadDePuertas;
public:
	Auto();
	virtual void mostrarDetalle();
	void setCantidadDePuertas(int cantidadDePuertas);
	
};
#endif