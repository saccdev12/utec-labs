#include "estructej1.h"
#include <iostream>

Persona leerPersona(){
	Persona ret;
	printf("Ingrese el nombre de la persona: ");
	scanf("%s", ret.nombre);
	printf("Ingrese el apellido de la persona: ");
	scanf("%s", ret.apellido);
	printf("Ingrese su fecha de nacimiento (dd/mm/yyyy): ");
	scanf("%d %*c %d %*c %d", &ret.fnacimiento.dia, &ret.fnacimiento.mes, &ret.fnacimiento.anio);
	return ret;
}

void imprimirPersona(Persona p){
	for (int i=1; i<N; i++){
		printf("- - - - Informacion de Persona - - - -\n");
		printf("Nombre: %s %s - Fecha de nacimiento: %d/%d/%d \n", p.nombre, p.apellido, p.fnacimiento.dia, p.fnacimiento.mes, p.fnacimiento.anio);
		
	}
}
