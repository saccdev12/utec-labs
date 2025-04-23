#include<iostream>
using namespace std;
int exponente (int base,int exp);


int main () {
	int base,potencia;
	printf(" Ingrese la base y el exp: ");
	scanf ("%d%d",&base,&potencia);
	int res=exponente(base,potencia);
	printf ("El resultado de %d elevado a %d es %d ",base,potencia,res);
	
	
	return 0;
}
int exponente (int base,int exp){
	int resultado=1;
	for (int i=1;i<=exp;i++){
		resultado=resultado*base;
	}
	return resultado;
	
}
