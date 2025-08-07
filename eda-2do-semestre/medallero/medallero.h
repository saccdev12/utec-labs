#ifndef EJER2_H
#define EJER2_H
#define LARGO_NOMBRE 50
#define CANTIDAD_PAISES 5

struct pais{
	char nombre[LARGO_NOMBRE];
	int medalla_oro=0;
	int medalla_plata=0;
	int medalla_bronce=0;
};
typedef struct pais Pais;

void ingreser_pais(Pais array_paises[],char nombre_pais[],int &contador);
void ingresar_medallas(Pais array_paises[],int contador);
void modificar_medallas(Pais array_paises[],int contador);
void imprimir_oro(Pais array_paises[],int contador);
#endif

