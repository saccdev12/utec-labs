#include <iostream>
#include <math.h>
using namespace std;

void baskara(float a, float b, float c, float &raiz1, float &raiz2, int &catRaices);
	
int main() {
	float coef1, coef2, coef3;
	scanf("%f %f %f", &coef1, &coef2, &coef3);
	float raiz1, raiz2;
	int numRaices;
	baskara(coef1, coef2, coef3, raiz1, raiz2, numRaices);
	if (numRaices == 0){
		printf("El polinomio no tiene raices");
	}else{
		printf("Raiz 1 es %f, Raiz 2 es %f", raiz2, raiz2);
	}
	return 0;
}

void baskara(float a, float b, float c, float &raiz1, float &raiz2, int &cantRaices){
	float disc = b*b - 4*a*c;
	if(disc < 0){
		cantRaices = 0;
	}else{
		raiz1 = (-1*b + sqrt(disc))/(2*a);
		raiz2 = (-1*b - sqrt(disc))/(2*a);
	}
}
