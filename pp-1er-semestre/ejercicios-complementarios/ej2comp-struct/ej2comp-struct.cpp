#include<iostream>
#include "ej2comp-struct.h"

Deportista leer_Deportista (){
	Deportista usuario_deportista;
	printf ("Ingrese el nombre del deportista:   \n");
	scanf("%s",usuario_deportista.pers.nombre);
	printf ("Ingrese el apellido del deportista:   \n");
	scanf("%s",usuario_deportista.pers.apellido);
	printf ("Ingrese el pais del deportista:   \n");
	scanf("%s",usuario_deportista.pers.pais);
	printf ("Ingrese la disciplina del deportista:   \n");
	scanf("%s",usuario_deportista.disciplina);
	printf ("Ingrese la cantidad de premios del deportista:   \n");
	scanf("%d",&usuario_deportista.cantidad_premios);
	return usuario_deportista;
}
	
	
void imprime_Deportista(Deportista d){
	printf ("Deportista:%s %s-",d.pers.nombre,d.pers.apellido);
	printf ("Disciplina:%s-",d.disciplina);
	printf ("Pais:%s-",d.pers.pais);
	printf ("Cantidad de premios:%d-",d.cantidad_premios);
		
}
