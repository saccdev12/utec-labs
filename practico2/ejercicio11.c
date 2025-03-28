#include <stdio.h>

int main() {
    char c1, c2, c3;

    // Leer tres caracteres
    printf("Ingrese el primer caracter: ");
    scanf(" %c", &c1); // Espacio antes de %c para ignorar caracteres previos como '\n'
    printf("Ingrese el segundo caracter: ");
    scanf(" %c", &c2);
    printf("Ingrese el tercer caracter: ");
    scanf(" %c", &c3);

    // Mostrar la palabra formada
    printf("La palabra formada es: %c%c%c\n", c1, c2, c3);

    return 0;
}