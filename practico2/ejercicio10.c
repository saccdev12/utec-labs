#include <stdio.h>

int main() {
    int num1, num2, num3, producto;

    // Leer tres números enteros
    printf("Ingrese el primer número entero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número entero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer número entero: ");
    scanf("%d", &num3);

    // Calcular el producto
    producto = num1 * num2 * num3;

    // Mostrar el resultado
    printf("El producto de %d, %d y %d es: %d\n", num1, num2, num3, producto);

    return 0;
}