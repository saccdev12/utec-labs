#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>
using namespace std;

#include "prototipos.h"
#include "estructuras.h"

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Archivo a = nullptr;
    cadena name = new char[T];
    strcpy(name, "documento.txt");
    a = CrearArchivo(name);
    
    cout << "=== SISTEMA DE CONTROL DE VERSIONES ===" << endl;
    cout << "Archivo creado: " << a->nombre << endl;
    cout << "Escriba 'ayuda' para ver los comandos disponibles" << endl << endl;
    
    cadena comando = new char[100];
    cadena parametro[P];
    
    do {
        cout << "> ";
        cin.getline(comando, 100);
        
        // Tokenización
        int contador = 0;
        char *token = strtok(comando, "(\",) ");
        
        while (token != nullptr && contador < P) {
            parametro[contador] = token;
            contador++;
            token = strtok(nullptr, "(\",) ");
        }
        
        for (int i = contador; i < P; i++) {
            parametro[i] = nullptr;
        }
        
        if (contador == 0) continue;
        
        opciones opcion = error;
        
        if (strcmp(parametro[0], "InsertarLinea") == 0) opcion = InsertarLinea;
        else if (strcmp(parametro[0], "BorrarLinea") == 0) opcion = BorrarLinea;
        else if (strcmp(parametro[0], "MostrarTexto") == 0) opcion = MostrarTexto;
        else if (strcmp(parametro[0], "CrearVersion") == 0) opcion = CrearVersion;
        else if (strcmp(parametro[0], "BorrarVersion") == 0) opcion = BorrarVersion;
        else if (strcmp(parametro[0], "MostrarVersiones") == 0) opcion = MostrarVersiones;
        else if (strcmp(parametro[0], "MostrarCambios") == 0) opcion = MostrarCambios;
        else if (strcmp(parametro[0], "Iguales") == 0) opcion = Iguales;
        else if (strcmp(parametro[0], "VersionIndependiente") == 0) opcion = VersionIndependiente;
        else if (strcmp(parametro[0], "limpiar") == 0) opcion = limpiar;
        else if (strcmp(parametro[0], "ayuda") == 0) opcion = ayuda;
        else if (strcmp(parametro[0], "salir") == 0) break;
        
        switch (opcion) {
            case InsertarLinea:
                if (parametro[1] != nullptr && parametro[2] != nullptr && parametro[3] != nullptr) {
                    muestroRetorno(insertarLinea(a, parametro[1], parametro[2], atoi(parametro[3])));
                } else {
                    cout << "ERROR: Parámetros insuficientes. Uso: InsertarLinea(archivo,version,texto,linea)" << endl;
                }
                break;
            case BorrarLinea:
                if (parametro[1] != nullptr && parametro[2] != nullptr) {
                    muestroRetorno(borrarLinea(a, parametro[1], atoi(parametro[2])));
                } else {
                    cout << "ERROR: Parámetros insuficientes. Uso: BorrarLinea(archivo,version,linea)" << endl;
                }
                break;
            case MostrarTexto:
                if (parametro[1] != nullptr) {
                    muestroRetorno(mostrarTexto(a, parametro[1]));
                } else {
                    cout << "ERROR: Falta parámetro versión" << endl;
                }
                break;
            case CrearVersion:
                if (parametro[1] != nullptr) {
                    muestroRetorno(crearVersion(a, parametro[1]));
                } else {
                    cout << "ERROR: Falta parámetro versión" << endl;
                }
                break;
            case BorrarVersion:
                if (parametro[1] != nullptr) {
                    muestroRetorno(borrarVersion(a, parametro[1]));
                } else {
                    cout << "ERROR: Falta parámetro versión" << endl;
                }
                break;
            case MostrarVersiones:
                muestroRetorno(mostrarVersiones(a));
                break;
            case MostrarCambios:
                if (parametro[1] != nullptr) {
                    muestroRetorno(mostrarCambios(a, parametro[1]));
                } else {
                    cout << "ERROR: Falta parámetro versión" << endl;
                }
                break;
            case Iguales:
                if (parametro[1] != nullptr && parametro[2] != nullptr) {
                    bool igual;
                    muestroRetorno(iguales(a, parametro[1], parametro[2], igual));
                } else {
                    cout << "ERROR: Parámetros insuficientes. Uso: Iguales(archivo,version1,version2)" << endl;
                }
                break;
            case VersionIndependiente:
                if (parametro[1] != nullptr) {
                    muestroRetorno(versionIndependiente(a, parametro[1]));
                } else {
                    cout << "ERROR: Falta parámetro versión" << endl;
                }
                break;
            case ayuda:
                help();
                break;
            case limpiar:
                system("clear");
                break;
            default:
                cout << "ERROR: Comando no reconocido. Escriba 'ayuda' para ver comandos disponibles." << endl;
        }
        cout << endl;
        
    } while (true);
    
    // Liberar memoria
    if (a != nullptr) {
        BorrarArchivo(a);
    }
    delete[] name;
    delete[] comando;
    
    cout << "Sistema finalizado. ¡Hasta luego!" << endl;
    return 0;
}