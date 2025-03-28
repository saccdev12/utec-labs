#include <stdio.h>

int main() {
    int numeros[5];
    int mayor, menor;

    // Leer 5 números enteros
    printf("Ingrese 5 números enteros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Inicializar mayor y menor con el primer número
    mayor = menor = numeros[0];

    // Encontrar el mayor y el menor
    for (int i = 1; i < 5; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    // Imprimir el mayor y el menor
    printf("El mayor número es: %d\n", mayor);
    printf("El menor número es: %d\n", menor);

    return 0;
}