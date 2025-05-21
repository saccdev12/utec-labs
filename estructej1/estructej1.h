#ifndef ESTRUCTEJ1_H
#define ESTRUCTEJ1_H
#define N 2
#define LARGONOMBRE 20
#define LARGOAPELLIDO 20
struct F{
	int dia;
	int mes;
	int anio;
};
typedef struct F Fecha;
typedef struct pers{
	char nombre[LARGONOMBRE];
	char apellido[LARGOAPELLIDO];
	Fecha fnacimiento;
}Persona;

Persona leerPersona();
void imprimirPersona(Persona p);
#endif
