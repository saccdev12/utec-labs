#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, discriminante, raiz1, raiz2;

    // Leer los coeficientes a, b y c
    printf("Ingrese el coeficiente a: ");
    scanf("%lf", &a);
    printf("Ingrese el coeficiente b: ");
    scanf("%lf", &b);
    printf("Ingrese el coeficiente c: ");
    scanf("%lf", &c);

    // Verificar si es una ecuación de segundo grado
    if (a == 0) {
        printf("Esto no es una ecuación de segundo grado.\n");
        return 0;
    }

    // Calcular el discriminante
    discriminante = b * b - 4 * a * c;

    // Determinar las raíces según el discriminante
    if (discriminante > 0) {
        // Dos raíces reales y distintas
        raiz1 = (-b + sqrt(discriminante)) / (2 * a);
        raiz2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("Las raíces reales son: %.2lf y %.2lf\n", raiz1, raiz2);
    } else if (discriminante == 0) {
        // Una raíz real (doble)
        raiz1 = -b / (2 * a);
        printf("La raíz real doble es: %.2lf\n", raiz1);
    } else {
        // No hay raíces reales
        printf("La ecuación no tiene raíces reales.\n");
    }

    return 0;
}