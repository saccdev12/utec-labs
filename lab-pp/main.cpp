#include<iostream>
#include "lab.h"
#include "sorteo.h"
using namespace std;

int main () {
	Jugador jugadores[NUM_JUGADRES];
	int cant_jugadores=0;
	int entrada_primaria,entrada_secundaria;
	int rondas_jugadas=0;
	char stringAuxiliar[LARGO_NOMBRE];
	mostrarMenuPrincipal();
	scanf("%d",&entrada_primaria);
	while(entrada_primaria<=3&&entrada_primaria>=1){
		switch (entrada_primaria){
		case 1:
			printf("1- Alta de jugadores \n");
			printf("2- Baja de jugador \n");
			printf("3- Modificacion de jugador \n");
			printf("4- Volver al menu \n ");
			scanf("%d",&entrada_secundaria);
			while(entrada_secundaria<=3&&entrada_secundaria>=1){
				switch (entrada_secundaria){
				case 1:
					alta_jugador(jugadores,cant_jugadores);
					ordenarJugadoresPorAlias(jugadores,cant_jugadores);
					break;
				case 2:
					//funcion de baja de jugador 
					break;
				case 3:
					printf("Ingrese el alias del jugador a modificar: \n");
					scanf("%s",stringAuxiliar);
					modificacionJugador(jugadores,stringAuxiliar,cant_jugadores);
					break;
					//funcion modificar jugador struct
				case 4:
					mostrarMenuPrincipal();
					scanf("%d",&entrada_primaria);
					break;
				default:
					break;
				}
				printf("1- Alta de jugadores \n");
				printf("2- Baja de jugador \n");
				printf("3- Modificacion de jugador \n");
				printf("4- Volver al menu \n ");
				scanf("%d",&entrada_secundaria);
			}
			break;
		case 2:
			printf("1- Listado de jugadores \n");
			printf("2- Listado de todas las apuestas \n");
			printf("3- Listado de las apuestas por jugador \n");
			printf("4- Volver al menu \n ");
			scanf("%d",&entrada_secundaria);
			while(entrada_secundaria<=3&&entrada_secundaria>=1){
				switch (entrada_secundaria){
				case 1:
					//funcion de listado de jugadores 
					listadoJugadores(jugadores,cant_jugadores);
					break;
				case 2:
					//funcion de todas las apuestas 
					break;
				case 3:
					//funcion listado de las apuestas por jugador
					printf("Ingrese el alias del jugador a modificar: \n");
					scanf("%s",stringAuxiliar);
					listadoApuestasporJugador(jugadores,stringAuxiliar,rondas_jugadas,cant_jugadores);
					break;
				case 4:
					mostrarMenuPrincipal();
					scanf("%d",&entrada_primaria);
					break;
				default:
					break;
				}
				printf("1- Listado de jugadores \n");
				printf("2- Listado de todas las apuestas \n");
				printf("3- Listado de las apuestas por jugador \n");
				printf("4- Volver al menu \n ");
				scanf("%d",&entrada_secundaria);
			}
			break;
		case 3:
			printf("Ingrese el alias del jugador: \n");
			scanf("%s",stringAuxiliar);
			rondas_jugadas=apostar(jugadores,stringAuxiliar,cant_jugadores);
			//apostar
			break;
		case 4:
			return 0;
		default:
			break;
		}
		printf("1- Gestionar usuario \n");
		printf("2- Consultas \n");
		printf("3- Apostar \n");
		printf("4- Salir \n ");
		scanf("%d",&entrada_primaria);	
		
	}
	
	return 0;
}
