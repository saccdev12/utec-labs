#include <iostream>
#include "carrito.h"
#include "articulo.h"

using namespace std;

int main() {
    // 1. Instanciar un carrito de compras [18]
    CarritoOnLine miCarrito("Sebastian", "2026-03-20 12:00");

    // 2. Instanciar varios artículos [18]
    Articulo art1(101, "Teclado", 1500);
    Articulo art2(102, "Mouse", 800);
    Articulo art3(103, "Monitor", 12000);
    Articulo art4(104, "Bicicleta", 20000);

    // 3. Agregar al carrito 3 artículos previamente instanciados [18]
    miCarrito.agregarArticulo(art1);
    miCarrito.agregarArticulo(art2);
    miCarrito.agregarArticulo(art3);

    // 4. Mostrar el importe total del carrito [18]
    cout << "Sesion de compra de: Sebastian" << endl;
    cout << "El importe total del carrito es: $" << miCarrito.calcularImporteTotal() << endl;

    return 0;
}