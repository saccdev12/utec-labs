#ifndef EJER4COMPLEALGOORDE_H
#define EJER4COMPLEALGOORDE_H
#define LARGO_CHAR 20
#define N 2
struct fecha{
	int dia;
	int mes;
	int anio;
};
typedef struct fecha Fecha;
struct persona{
	char nombre[LARGO_CHAR];
	char apellido[LARGO_CHAR];
	Fecha fecha_nacimiento;
};
typedef struct persona Persona;
Persona leerPersona ();
void imprimirPersona (Persona p);
void ordenaArreglo (Persona vector []);
#endif
