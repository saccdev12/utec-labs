#include "ejercicio5.h"

// Versión iterativa
int sumaIterativa(int arr[], int tamaño) {
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += arr[i];
    }
    return suma;
}

// Función recursiva helper
int sumaRecursivaHelper(int arr[], int inicio, int fin) {
    if (inicio > fin) return 0;
    return arr[inicio] + sumaRecursivaHelper(arr, inicio + 1, fin);
}

// Versión recursiva (wrapper function)
int sumaRecursiva(int arr[], int tamaño) {
    return sumaRecursivaHelper(arr, 0, tamaño - 1);
}