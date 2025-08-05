#include <iostream>
#include"lab.h"
#include <string.h>
#include "sorteo.h"

//Función que muestra el menu principal
void mostrarMenuPrincipal() {
	printf("1- Gestionar usuario\n");
	printf("2- Consultas\n");
	printf("3- Apostar\n");
	printf("4- Salir\n");
}

//Validación de fecha 
int validarFecha (Fecha fechadenacimiento){
	if (fechadenacimiento.anio < 1850 || fechadenacimiento.anio > 2025) return 0;
	if (fechadenacimiento.mes < 1 || fechadenacimiento.mes > 12) return 0;
	if (fechadenacimiento.dia < 1 || fechadenacimiento.dia > 31) return 0;
	return 1;
}

//Comparación de alias
int buscarJugadorPorAlias(Jugador jugadores[], int cant_jugadores, char alias[]) {
	for (int i = 0; i < cant_jugadores; i++) {
		if (strcmp(jugadores[i].alias, alias) == 0) {
			return 0;
		}
	}
	return 1;
}

//Algoritmo de ordenamiento de jugadores 
void ordenarJugadoresPorAlias(Jugador jugadores_main[], int num_jugadores) {
	Jugador jugador_auxiliar;
	for (int i = 0; i < num_jugadores - 1; i++) {
		for (int j = i + 1; j < num_jugadores; j++) {
			if (strcmp(jugadores_main[i].alias, jugadores_main[j].alias) > 0) {
				
				// Intercambio de structs
				jugador_auxiliar = jugadores_main[i];
				jugadores_main[i] = jugadores_main[j];
				jugadores_main[j] = jugador_auxiliar;
			}
		}
	}
}

//Validación de C.I
int validarCI(int ci[]){
	int verificador=0;
	int multi[]{2,9,8,7,6,3,4};
	int suma=0;
	suma = ci[0]*multi[0]+ci[1]*multi[1]+ci[2]*multi[2]+ci[3]*multi[3]+ci[4]*multi[4]+ci[5]*multi[5]+ci[6]*multi[6];
	suma= suma%10;
	suma=10-suma;
	verificador=suma;
	if(verificador==10){
		verificador=0;
	}
	if(ci[7]==verificador){
		 printf("\n----la C.I ingresada es valida----");
		 return 1;
	}else 
	   printf("\n----la C.I ingresada es invalida----");
return 0;
}
	
//Alta de jugador
void alta_jugador(Jugador jugadores_main[],int &num_jugadores){
	
	int validador=0;
	
	//Nombre
	printf("Ingrese su nombre: ");
	scanf("%s", jugadores_main[num_jugadores].nombre);
	
	//Apellido
	printf("Ingrese su apellido: ");
	scanf("%s",jugadores_main[num_jugadores].apellido);
			
	//Alias
	do{
		printf("Ingrese un alias: ");
		scanf("%s",jugadores_main[num_jugadores].alias);
		if (buscarJugadorPorAlias(jugadores_main,num_jugadores,jugadores_main[num_jugadores].alias)==0){
			printf ("\nEl alias no disponible.\n");
			validador=0;
		}else{
			printf("\n----Alias cargada----\n");
			validador=1;
		}
	} while(validador==0);
	validador=0;
	
	//Fecha de nacimiento
	do{
		printf("\nIngrese su fecha de nacimiento dd/mm/aaaa: ");
		scanf("%d%*c%d%*c%d", &jugadores_main[num_jugadores].fechaNam.dia, &jugadores_main[num_jugadores].fechaNam.mes, &jugadores_main[num_jugadores].fechaNam.anio);
		if (validarFecha(jugadores_main[num_jugadores].fechaNam)==0){
			printf("\n--fecha incorrecta.--\n--Intenta de nuevo.--\n");
			validador=0;
		}else{
			printf("\n----fecha de nacimiento cargada----\n");
			validador=1;
		}
	} while(validador==0);
	validador=0;
	
	//C.I
	do{
		int divisor = 10000000;
		int cedula_auxiliar;
		printf("\nIngrese la C.I sin espacios y sin guiones: ");
		scanf("%d",&cedula_auxiliar);
		for (int i = 0; i < LARGO_CEDULA; i++) {
			jugadores_main[num_jugadores].cedula[i] = (cedula_auxiliar / divisor) % 10;
			divisor /= 10;
		}
		if(validarCI(jugadores_main[num_jugadores].cedula)==0){
			printf("\n----C.I no valida----\n ");
			validador=0;
		}else{
			printf("\n----C.I cargada----\n");
			validador=1;
		}
	} while(validador==0);
	//ACTIVIDAD
	jugadores_main[num_jugadores].activo=true;
	//SALDO
	jugadores_main[num_jugadores].saldo=1000;
	//CANTIDAD DE JUGADORES 
	num_jugadores++;
			
			
}
void modificacionJugador(Jugador jugadores_main[],char alias[],int num_jugadores){
	int validador=0;
	for(int i=0;i<num_jugadores;i++){
		if(strcmp(jugadores_main[i].alias, alias) == 0){
			//NOMBRE
			printf("Ingrese su nombre: ");
			scanf("%s", jugadores_main[i].nombre);
			//APELLIDO
			printf("Ingrese su apellido: ");
			scanf("%s",jugadores_main[i].apellido);
			//FECHA DE NACIMIENTO
			do{
				printf("Ingrese su fecha de nacimiento dd/mm/aaaa: ");
				scanf("%d%*c%d%*c%d", &jugadores_main[i].fechaNam.dia, &jugadores_main[i].fechaNam.mes, &jugadores_main[i].fechaNam.anio);
				if (validarFecha(jugadores_main[i].fechaNam)==0){
					printf("\n--fecha incorrecta.--\n--Intenta de nuevo.--\n");
					validador=0;
				}else{
					printf("\n----fecha de nacimiento cargada----\n");
					validador=1;
				}
			} while(validador==0);
			validador=0;
			//CEDULA
			do{
				int divisor = 10000000;
				int cedula_auxiliar;
				printf("\nIngrese su C.I sin espacios y sin guiones: ");
				scanf("%d",&cedula_auxiliar);
				for (int j = 0; j < LARGO_CEDULA; j++) {
					jugadores_main[i].cedula[j] = (cedula_auxiliar / divisor) % 10;
					divisor /= 10;
				}
				
				if(validarCI(jugadores_main[i].cedula)==0){
					printf("\n----C.I no valida----\n ");
					validador=0;
				}else{
					printf("\n----C.I cargada----\n");
					validador=1;
				}
			} while(validador==0);
		}
	}
}
	
void listadoJugadores(Jugador jugadores_main[],int num_jugadores){
	//CI,nombre, apellido, alias y saldo actual. 
	for(int i=0;i<num_jugadores;i++){
		if (jugadores_main[i].activo){
			//IMPRESION DE CEDULA
			printf("C.I: ");
			for(int j=0;j<LARGO_CEDULA;j++){
				printf("%d",jugadores_main[i].cedula[j]);
			}
			//NOMBRE
			printf("\nNombre: %s \n",jugadores_main[i].nombre);
			//APELLIDO
			printf("Apellido: %s \n",jugadores_main[i].apellido);
			//ALIAS
			printf("Alias: %s \n",jugadores_main[i].alias);
			//SALDO
			printf("Saldo: %d \n",jugadores_main[i].saldo);
		}
	}
}
int apostar(Jugador jugadores_main[], char alias[],int num_jugadores){
	int copaelegida;
	int rondas=0;
	for(int i=0;i<num_jugadores;i++){
		if((strcmp(jugadores_main[i].alias, alias) == 0)&&(jugadores_main[i].activo==true)){
			if (jugadores_main[i].saldo<=0){
				printf("----Saldo insuficiente----");
			}
			while(jugadores_main[i].saldo>0){
				int copa_con_moneda = generarCopa(rondas);
				printf("O O O\n");
				printf("1 2 3\n");
				printf("Copa?:\n");
				scanf("%d",&copaelegida);
				printf("Apuesta?:\n");
				scanf(" %d",&jugadores_main[i].apuestas_del_jugador.monto_apostado[rondas]);
				if (jugadores_main[i].contador_de_aciertos == 2 && copaelegida == copa_con_moneda) { //estafa
					jugadores_main[i].saldo -= jugadores_main[i].apuestas_del_jugador.monto_apostado[rondas];
					jugadores_main[i].apuestas_del_jugador.saldopos_Apuesta[rondas]=jugadores_main[i].saldo;
					jugadores_main[i].apuestas_del_jugador.resultado[rondas]=false;
					jugadores_main[i].contador_de_aciertos = 0;
					for (int i = 1; i <= 3; i++) {
						if (i == copa_con_moneda) printf("   ");
						else printf("O  ");
						
					}
					printf("\nNo ha acertado\n");
				} else if (copaelegida == copa_con_moneda) { //acierto
					jugadores_main[i].saldo += jugadores_main[i].apuestas_del_jugador.monto_apostado[rondas];
					jugadores_main[i].apuestas_del_jugador.saldopos_Apuesta[rondas]=jugadores_main[i].saldo;
					jugadores_main[i].apuestas_del_jugador.resultado[rondas]=true;
					jugadores_main[i].contador_de_aciertos++;
			    for (int i = 1; i <= 3; i++) {
				    if (i == copa_con_moneda) printf(".  ");
				    else printf("O  ");
				}
			    printf("\nHa acertado\n");
				}else  { //no acierto
					jugadores_main[i].saldo -= jugadores_main[i].apuestas_del_jugador.monto_apostado[rondas];
					jugadores_main[i].apuestas_del_jugador.saldopos_Apuesta[rondas]=jugadores_main[i].saldo;
					jugadores_main[i].apuestas_del_jugador.resultado[rondas]=false;
			        for (int i = 1; i <= 3; i++) {
				    if (i == copa_con_moneda) printf(".  ");
				    else printf("O  ");
			        }
				printf("\nNo ha acertado\n");
		        }
		    printf("Saldo: %d\n\n", jugadores_main[i].saldo);
		    rondas++;
	        }
		return rondas;
	    printf("Gracias por jugar\n");	
       }
    }
}
	
void listadoApuestasporJugador(Jugador jugadores_main[],char alias[],int rondas_jugadas,int num_jugadores){
	for(int i=0;i<num_jugadores;i++){
		if(strcmp(jugadores_main[i].alias, alias) == 0){
			printf("Listado de apuestas del jugador:%s",jugadores_main[i].alias);
			for(int j=0;j<rondas_jugadas;j++){
				printf ("EL numero de la ronda es %d\n",j+1);
				printf("El saldo final del jugador es:%d\n",jugadores_main[i].saldo);
				printf ("El saldo resultante de la apuesta es:%d.\n",jugadores_main[i].apuestas_del_jugador.saldopos_Apuesta[j]);
				printf ("El monto apostado es:%d.\n",jugadores_main[i].apuestas_del_jugador.monto_apostado[j]);
				printf ("El resultado de la apuesta es:%d.\n",jugadores_main[i].apuestas_del_jugador.resultado[j]);
			}
			
		}
    }
}


