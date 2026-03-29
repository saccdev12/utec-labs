#ifndef MOTO_H
#define MOTO_H
#include "Vehiculo.h"
#include <string>
class Moto : public Vehiculo{
	private:
		int cilindrada;
	public:
		Moto();
		virtual void  mostrarDetalle();
		void setCilindrada(int cilindrada);
};
#endif