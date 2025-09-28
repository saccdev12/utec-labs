#include "ejercicio2.h"
#include <iostream>

using namespace std;

// Versión iterativa con array auxiliar
void invertirIterativo(int arr[], int tamaño) {
    int auxiliar[tamaño];
    
    // Copiar elementos en orden inverso al array auxiliar
    for (int i = 0; i < tamaño; i++) {
        auxiliar[i] = arr[tamaño - 1 - i];
    }
    
    // Copiar de vuelta al array original
    for (int i = 0; i < tamaño; i++) {
        arr[i] = auxiliar[i];
    }
}

// Función recursiva helper
void invertirRecursivoHelper(int arr[], int inicio, int fin) {
    if (inicio >= fin) return;
    
    // Intercambiar elementos
    int temp = arr[inicio];
    arr[inicio] = arr[fin];
    arr[fin] = temp;
    
    // Llamada recursiva
    invertirRecursivoHelper(arr, inicio + 1, fin - 1);
}

// Versión recursiva (wrapper function)
void invertirRecursivo(int arr[], int tamaño) {
    invertirRecursivoHelper(arr, 0, tamaño - 1);
}

// Función para imprimir array
void imprimirArray(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}