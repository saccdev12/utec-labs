#ifndef REPASO_H
#define REPASO_H
#define LARGONOMBRE 26

struct estudiante{
	char nombre[LARGONOMBRE];
	int calificacion;
};
typedef struct estudiante Estudiante;

//Cabeceras de funciones
void ingresarNotas(Estudiante estudiantes[], int* contador);
void mostrarEstadisticas(Estudiante estudiantes[], int contador);
float calcularPromedio(Estudiante estudiantes[], int contador);
void encontrarMayorNota(Estudiante estudiantes[], int contador);
void encontrarMenorNota(Estudiante estudiantes[], int contador);
int contarInsuficientes(Estudiante estudiantes[], int contador);
int contarSuficientes(Estudiante estudiantes[], int contador);

#endif
