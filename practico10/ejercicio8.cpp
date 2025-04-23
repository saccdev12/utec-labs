#include<iostream>
using namespace std;
#include <math.h>
void bhaskara (int a,int b,int c);
int main () {
	printf("Ingrese los coeficientes del polinomio:     \n");
	int a,b,c;
	scanf ("%d%d%d",&a,&b,&c);
	bhaskara(a,b,c);
	
	return 0;
}
void bhaskara (int a,int b,int c){
	int discriminante =b*b-4*a*c;
	if (discriminante<0){
		printf ("EL polinomio NO tiene raices reales");
	}else{
		float raiz1,raiz2;
		raiz1=((-1*b+sqrt(discriminante))/2*a);
		raiz1=((-1*b-sqrt(discriminante))/2*a);
	}
}
	
	
