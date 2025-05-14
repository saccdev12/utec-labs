#include <iostream>
using namespace std;

float area(char figura, float base, float altura);

int main() {
	char figura;
	float valor1, valor2;
	
	printf("Seleccione la figura (T=Triangulo, R=Rectangulo, C=Cuadrado): ");
	scanf(" %c", &figura);  
	
	printf("Ingrese el primer valor (base para triangulo, largo para rectangulo, lado para cuadrado): ");
	scanf("%f", &valor1);
	
	if(figura != 'C') {  
		printf("Ingrese el segundo valor (altura para triangulo, ancho para rectangulo): ");
		scanf("%f", &valor2);
	} else {
		valor2 = valor1;  
	}
	
	float resultado = area(figura, valor1, valor2);
	printf("El area es: %.2f\n", resultado);
	
	return 0;
}

float area(char figura, float base, float altura) {
	switch(figura) {
	case 'T': case 't': 
		return (base * altura) / 2;
	case 'R': case 'r': 
		return base * altura;
	case 'C': case 'c': 
		return base * base;
	default:
		printf("Figura no reconocida. Use T, R o C.\n");
		return 0;
	}
}
