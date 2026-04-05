#include <iostream>
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTRefer.h"
#include "Investigador.h"
#include "Publicacion.h"
#include "Libro.h"
#include "ArticuloRevista.h"
#include "PaginaWeb.h"

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "   INICIANDO SISTEMA DE PUBLICACIONES   " << endl;
    cout << "========================================" << endl;

    DTFecha fecha1(15, 5, 2022);
    DTFecha fecha2(20, 8, 2024);
    DTFecha fecha3(10, 1, 2024);

    Investigador* carla = new Investigador("0000-0001-1234-5678", "Carla", "Udelar");
    Investigador* alberto = new Investigador("0000-0002-8765-4321", "Alberto", "ORT");

    cout << "Investigadores registrados:" << endl;
    cout << carla->DeString() << endl;
    cout << alberto->DeString() << endl;
    cout << "----------------------------------------" << endl;

    Libro* lib1 = new Libro("10.100/libro1", "Introduccion a POO", fecha1, "Pearson");
    ArticuloRevista* art1 = new ArticuloRevista("10.200/art1", "POO Avanzada y C++", fecha2, "Journal of IT");
    PaginaWeb* web1 = new PaginaWeb("10.300/web1", "Guia de C++", fecha3, "www.cplusplus.com");

    carla->agregarPublicacion(lib1);
    lib1->agregarAutor(carla);

    carla->agregarPublicacion(art1);
    art1->agregarAutor(carla);

    alberto->agregarPublicacion(art1);
    art1->agregarAutor(alberto);

    alberto->agregarPublicacion(web1);
    web1->agregarAutor(alberto);

    cout << "\nBuscando publicaciones de Carla..." << endl;
    cout << "Filtro: Posteriores al 01/01/2023 con la palabra 'POO'" << endl;

    DTFecha filtroDesde(1, 1, 2023);
    set<string> resultados = carla->listarPublicaciones(filtroDesde, "POO");

    cout << "\n--- Resultados de la busqueda ---" << endl;
    if (resultados.empty()) {
        cout << "No se encontraron publicaciones que cumplan los filtros." << endl;
    } else {
        for (const string& doi : resultados) {
            cout << "-> DOI Encontrado: " << doi << endl;
        }
    }

    delete lib1;
    delete art1;
    delete web1;
    delete carla;
    delete alberto;

    cout << "\n========================================" << endl;
    cout << "   PROGRAMA FINALIZADO CORRECTAMENTE    " << endl;
    cout << "========================================" << endl;

    return 0;
}