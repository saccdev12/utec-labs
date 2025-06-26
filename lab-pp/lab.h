#ifndef LAB_H
#define LAB_H
#define LARGO_NOMBRE 50
#define LARGO_APELLIDO 50
#define LARGO_CEDULA 8
#define NUM_JUGADRES 80
#define NUM_JUGADAS 100
#include <stdbool.h>
struct fecha{
	int dia;
	int mes;
	int anio;
};
typedef struct fecha Fecha;

struct apuesta{
	int monto_apostado[NUM_JUGADAS];
	int saldopos_Apuesta[NUM_JUGADAS];
	bool resultado[NUM_JUGADAS];
};
typedef struct apuesta Apuesta;

struct jugador{
	int cedula[LARGO_CEDULA];
	char nombre[LARGO_NOMBRE];
	char apellido[LARGO_APELLIDO];
	char alias[LARGO_NOMBRE];
	bool activo;
	Fecha fechaNam;
	Apuesta apuestas_del_jugador;
	int saldo;
	int contador_de_aciertos;
};
typedef struct jugador Jugador;

void mostrarMenuPrincipal();
int buscarJugadorPorAlias(Jugador jugadores[], int cant, char alias[]);
int validarFecha(Fecha f);
int validarCI(int ci[]);
void alta_jugador(Jugador jugadores_main[],int &num_jugadores);
void ordenarJugadoresPorAlias(Jugador jugadores_main[], int num_jugadores);
void modificacionJugador(Jugador jugadores_main[], char alias[],int num_jugadores);
void listadoJugadores(Jugador jugadores_main[],int num_jugadores);//CI,nombre, apellido, alias y saldo actual. 
int apostar(Jugador jugadores_main[], char alias[],int num_jugadores);
void listadoApuestasporJugador(Jugador jugadores_main[],char alias[],int rondas_jugadas,int num_jugadores);
#endif
