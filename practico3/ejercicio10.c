#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Leer 3 números enteros
    printf("Ingrese el primer número entero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número entero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer número entero: ");
    scanf("%d", &num3);

    // Verificar si cada número es múltiplo de 2
    if (num1 % 2 == 0) {
        printf("El número %d es múltiplo de 2.\n", num1);
    } else {
        printf("El número %d no es múltiplo de 2.\n", num1);
    }

    if (num2 % 2 == 0) {
        printf("El número %d es múltiplo de 2.\n", num2);
    } else {
        printf("El número %d no es múltiplo de 2.\n", num2);
    }

    if (num3 % 2 == 0) {
        printf("El número %d es múltiplo de 2.\n", num3);
    } else {
        printf("El número %d no es múltiplo de 2.\n", num3);
    }

    return 0;
}