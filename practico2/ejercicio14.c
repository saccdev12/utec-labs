#include <stdio.h>
#include <math.h>

int main() {
    int octal, decimal = 0, digit, i = 0;

    // Leer el número octal de tres dígitos
    printf("Ingrese un numero octal de 3 cifras: ");
    scanf("%d", &octal);

    // Convertir de octal a decimal
    int temp = octal;
    while (temp > 0) {
        digit = temp % 10;          // Obtener el último dígito
        decimal += digit * pow(8, i); // Convertir el dígito a base 10
        temp /= 10;                 // Eliminar el último dígito
        i++;
    }

    // Mostrar el resultado
    printf("Octal %d = Decimal %d\n", octal, decimal);

    return 0;
}