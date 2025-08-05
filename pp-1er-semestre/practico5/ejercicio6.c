#include <stdio.h>

int main() {
	char decena, unidad, decimal;
	printf("Ingrese 3 caracteres numericos: \n");
	scanf("%c %c %c", &decena, &unidad, &decimal);
	float resultado;
	if (decena >= 48 && decena <= 57 && unidad >= '0' && unidad <= '9' && decimal >= '0' && decimal <= '9'){
		resultado = (decena - '0') * 10;
		resultado = resultado + (unidad - '0');
		float valordecimal = (decimal - '0');
		resultado += (valordecimal/10);
		printf("El valor formado es %f", resultado);
	}else{
		printf("Algun caracter no es un dígito");
	}
	return 0;
}

