#include<iostream>
#include "ej2comp-struct.h"
using namespace std;

int main (int argc, char *argv[]) {
	Deportista entrada_Deportista[CANT_DEPORTISTAS];
	for (int i=0;i<CANT_DEPORTISTAS;i++){
		entrada_Deportista[i]=leer_Deportista();
	}
	Deportista mayor=entrada_Deportista[0];
	for (int i=1;i<CANT_DEPORTISTAS;i++){
		if (entrada_Deportista[i].cantidad_premios>mayor.cantidad_premios){
			mayor=entrada_Deportista[i];
		}
	}
	printf("EL deportista con mayor cantidad de premios es :    \n");
	imprime_Deportista(mayor);
	return 0;
}
