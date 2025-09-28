#include <iostream>
#include "ejercicio2.h"

using namespace std;

int main() {
    const int TAMANO = 5;
    int array1[TAMANO] = {1, 2, 3, 4, 5};
    int array2[TAMANO] = {10, 20, 30, 40, 50};
    
    cout << "=== PRUEBA FUNCIÓN ITERATIVA ===" << endl;
    cout << "Array original: ";
    imprimirArray(array1, TAMANO);
    
    invertirIterativo(array1, TAMANO);
    
    cout << "Array invertido (iterativo): ";
    imprimirArray(array1, TAMANO);
    
    cout << "\n=== PRUEBA FUNCIÓN RECURSIVA ===" << endl;
    cout << "Array original: ";
    imprimirArray(array2, TAMANO);
    
    invertirRecursivo(array2, TAMANO);
    
    cout << "Array invertido (recursivo): ";
    imprimirArray(array2, TAMANO);
    
    return 0;
}