#ifndef EJER2_H
#define EJER2_H
#define CANT_DEPORTISTAS 2
#define LARGO_CADENA 30
struct persona {
	char nombre[LARGO_CADENA];
	char apellido[LARGO_CADENA];
	char pais[LARGO_CADENA];
};
typedef struct persona Persona;
struct deportista {
	Persona pers;
	char disciplina[LARGO_CADENA];
	int cantidad_premios;
};
typedef struct deportista Deportista;
Deportista leer_Deportista ();
void imprime_Deportista(Deportista d);
#endif
