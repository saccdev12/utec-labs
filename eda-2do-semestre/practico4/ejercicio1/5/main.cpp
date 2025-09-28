#include <iostream>
#include "ejercicio5.h"

using namespace std;

int main() {
    const int TAMANO = 6;
    int array1[TAMANO] = {1, 2, 3, 4, 5, 6};
    int array2[TAMANO] = {10, 20, 30, 40, 50, 60};
    
    cout << "=== PRUEBA FUNCIÓN ITERATIVA ===" << endl;
    cout << "Array: ";
    for (int i = 0; i < TAMANO; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    
    int resultadoIterativo = sumaIterativa(array1, TAMANO);
    cout << "Suma (iterativa): " << resultadoIterativo << endl;
    
    cout << "\n=== PRUEBA FUNCIÓN RECURSIVA ===" << endl;
    cout << "Array: ";
    for (int i = 0; i < TAMANO; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;
    
    int resultadoRecursivo = sumaRecursiva(array2, TAMANO);
    cout << "Suma (recursiva): " << resultadoRecursivo << endl;
    
    return 0;
}