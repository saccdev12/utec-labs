#include <iostream>
#include <string>
#include <set>
#include "DTFecha.h"
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

    DTFecha fecha1(15, 5, 2023);
    DTFecha fecha2(10, 2, 2024);
    DTFecha fecha3(20, 8, 2022);
    DTFecha fecha4(20, 8, 2022);
    DTFecha fecha5(20, 10, 2024);

    ArticuloRevista* art1 = new ArticuloRevista("10.1234/abc123", "Fundamentos de POO", fecha1, "Programación Avanzada", "Introduccion a los principios fundamentales de la programacionorientada a objetos, explicando sus conceptos clave como clases,objetos, herencia y polimorfismo" );
    ArticuloRevista* art2 = new ArticuloRevista("10.4567/jkl012", "Utilidad de diagramas UML", fecha2, "Modelado de Software", "Ejercicio empirico de como los diagramas UML pueden ayudar en el proces y documentacion de software, cubriendo los tipos mas importantes utilizados, como clases.");


    set<string> keywords;
    keywords.insert("Diseno");
    keywords.insert("DOP");
    keywords.insert("Class");
    Libro* lib1 = new Libro("10.2345/def456", "Patrones de Diseno en c++", fecha3, "Software Design", keywords);

    keywords.clear();

    keywords.insert("Diagramas");
    keywords.insert("UML");
    keywords.insert("Software");
    keywords.insert("Modelado");
    Libro* lib2 = new Libro("10.5678/mno345", "Guia de UML", fecha4, "IEEE", keywords);

    PaginaWeb* web1 = new PaginaWeb("10.3456/ghi789", "Diagrama para Principiantes", fecha5, "www.umlparaprincipiantes.com", "En esta pagina web se presenta una gui completa sobre los diagramas UML, abordando los diagramas de caso de uso, de clases, de secuencia y de actividades");

    cout <<art1->getDT() <<endl;
    cout <<art2->getDT() <<endl;
    cout <<lib1->getDT() <<endl;
    cout <<lib2->getDT() <<endl;
    cout <<web1->getDT() <<endl;
    cout<<endl;

    Investigador* carla = new Investigador("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
    Investigador* alberto = new Investigador("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");

    cout << "Investigadores registrados:" << endl;
    cout << carla->DeString() << endl;
    cout << alberto->DeString() << endl;
    cout << "----------------------------------------" << endl;

    carla->agregarPublicacion(art1);
    art1->agregarAutor(carla);

    carla->agregarPublicacion(art2);
    art2->agregarAutor(carla);

    carla->agregarPublicacion(lib2);
    lib2->agregarAutor(carla);

    carla->agregarPublicacion(web1);
    web1->agregarAutor(carla);

    alberto->agregarPublicacion(art1);
    art1->agregarAutor(alberto);

    alberto->agregarPublicacion(lib1);
    lib1->agregarAutor(alberto);

    alberto->agregarPublicacion(art2);
    art2->agregarAutor(alberto);

    cout << "\nBuscando publicaciones de Carla..." << endl;
    cout << "Filtro: Posteriores al 10/12/2023 con la palabra 'UML'" << endl;

    DTFecha filtroDesde1(10, 12, 2023);
    set<string> resultados1 = carla->listarPublicaciones(filtroDesde1, "UML");

    for (auto pub : resultados1 ) {
        cout<<pub<<endl;
    }//modularizable

    delete art2; //cout de el delete

    cout << "\nBuscando publicaciones de Carla..." << endl;
    cout << "Filtro: Posteriores al 01/01/2020 con la palabra 'UML'" << endl;

    DTFecha filtroDesde2(1, 1, 2020);
    set<string> resultados2 = carla->listarPublicaciones(filtroDesde2, "UML");

    for (auto pub : resultados2 ) {
        cout<<pub<<endl;
    }
    cout<<endl;

    cout <<art1->getDT() <<endl;
    cout <<lib1->getDT() <<endl;
    cout <<lib2->getDT() <<endl;
    cout <<web1->getDT() <<endl;
    cout<<endl;

    //delete publs
    delete lib1;
    delete lib2;
    delete art1;
    delete web1;

    cout << "\n========================================" << endl;
    cout << "   PROGRAMA FINALIZADO CORRECTAMENTE    " << endl;
    cout << "========================================" << endl;

    return 0;
}