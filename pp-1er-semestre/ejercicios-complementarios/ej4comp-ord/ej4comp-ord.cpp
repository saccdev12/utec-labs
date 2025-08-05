#include <iostream>
#include "ej4comp-ord.h"
#include <string.h>
Persona leerPersona (){
	Persona persona_aux;
	printf ("POr fevor coloca el nombre de la persona:\n");
	scanf ("%s",persona_aux.nombre);
	printf ("POr fevor coloca el apellido de la persona:\n");
	scanf ("%s",persona_aux.apellido);
	printf ("POr fevor coloca la fecha de nacimiento de la persona:\n");
	scanf (" %d%*c%d%*c%d%*c",&persona_aux.fecha_nacimiento.dia,&persona_aux.fecha_nacimiento.mes,&persona_aux.fecha_nacimiento.anio);
	return persona_aux;
}
	void imprimirPersona (Persona p){
		printf ("\n------Impresion de persona----------\n");
		printf ("\nNombre:%s %s -Fecha Nacimiento:%d/%d/%d\n",p.nombre,p.apellido,p.fecha_nacimiento.dia,p.fecha_nacimiento.mes,p.fecha_nacimiento.anio);
	}
		void ordenaArreglo (Persona vector []){
			for (int i=0;i<N;i++){
				for (int j=i+1;j<N;j++){
					if (strcmp(vector[i].nombre,vector[j].nombre)>0){
						Persona aux =vector[i];
						vector[i]=vector[j];
						vector[j]=aux;
					}
				}
			}
		}
