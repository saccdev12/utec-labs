#include <iostream>
#include <cstring>
#include "lab-proto.h"

using namespace std;

void mostrarMenu();
void procesarComando(Archivo* &archivoActual);

int main() {
    Archivo* archivoActual = nullptr;
    
    cout << "=== MANEJADOR DE VERSIONES ===" << endl;
    cout << "Sistema de control de versiones para archivos de texto" << endl << endl;
    
    while (true) {
        mostrarMenu();
        procesarComando(archivoActual);
    }
    
    return 0;
}

void mostrarMenu() {
    cout << "\nCOMANDOS DISPONIBLES:" << endl;
    cout << "1. crear <nombre> - Crear nuevo archivo" << endl;
    cout << "2. borrar - Borrar archivo actual" << endl;
    cout << "3. version <id> - Crear nueva versión" << endl;
    cout << "4. borrar_version <id> - Borrar versión" << endl;
    cout << "5. mostrar_versiones - Mostrar todas las versiones" << endl;
    cout << "6. insertar <version> <linea> <texto> - Insertar línea" << endl;
    cout << "7. borrar_linea <version> <nro_linea> - Borrar línea" << endl;
    cout << "8. mostrar_texto <version> - Mostrar texto de versión" << endl;
    cout << "9. mostrar_cambios <version> - Mostrar cambios de versión" << endl;
    cout << "10. iguales <version1> <version2> - Comparar versiones" << endl;
    cout << "11. salir - Salir del programa" << endl;
    cout << "\nIngrese comando: ";
}

void procesarComando(Archivo* &archivoActual) {
    char comando[100];
    cin >> comando;
    
    if (strcmp(comando, "crear") == 0) {
        char nombre[100];
        cin >> nombre;
        
        if (archivoActual) {
            cout << "ERROR: Ya existe un archivo abierto" << endl;
        } else {
            archivoActual = CrearArchivo(nombre);
            cout << "Archivo '" << nombre << "' creado exitosamente" << endl;
        }
    }
    else if (strcmp(comando, "borrar") == 0) {
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            BorrarArchivo(archivoActual);
            cout << "Archivo borrado exitosamente" << endl;
        }
    }
    else if (strcmp(comando, "version") == 0) {
        char version[100];
        cin >> version;
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            TipoRet resultado = CrearVersion(archivoActual, version);
            if (resultado == OK) {
                cout << "Versión '" << version << "' creada exitosamente" << endl;
            }
        }
    }
    else if (strcmp(comando, "borrar_version") == 0) {
        char version[100];
        cin >> version;
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            TipoRet resultado = BorrarVersion(archivoActual, version);
            if (resultado == OK) {
                cout << "Versión '" << version << "' borrada exitosamente" << endl;
            }
        }
    }
    else if (strcmp(comando, "mostrar_versiones") == 0) {
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            MostrarVersiones(archivoActual);
        }
    }
    else if (strcmp(comando, "insertar") == 0) {
        char version[100];
        unsigned int nroLinea;
        char linea[1000];
        
        cin >> version >> nroLinea;
        cin.ignore(); // Ignorar espacio
        cin.getline(linea, 1000);
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            TipoRet resultado = InsertarLinea(archivoActual, version, linea, nroLinea);
            if (resultado == OK) {
                cout << "Línea insertada exitosamente" << endl;
            }
        }
    }
    else if (strcmp(comando, "borrar_linea") == 0) {
        char version[100];
        unsigned int nroLinea;
        
        cin >> version >> nroLinea;
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            TipoRet resultado = BorrarLinea(archivoActual, version, nroLinea);
            if (resultado == OK) {
                cout << "Línea borrada exitosamente" << endl;
            }
        }
    }
    else if (strcmp(comando, "mostrar_texto") == 0) {
        char version[100];
        cin >> version;
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            MostrarTexto(archivoActual, version);
        }
    }
    else if (strcmp(comando, "mostrar_cambios") == 0) {
        char version[100];
        cin >> version;
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            MostrarCambios(archivoActual, version);
        }
    }
    else if (strcmp(comando, "iguales") == 0) {
        char version1[100], version2[100];
        cin >> version1 >> version2;
        
        if (!archivoActual) {
            cout << "ERROR: No hay archivo abierto" << endl;
        } else {
            bool iguales;
            TipoRet resultado = Iguales(archivoActual, version1, version2, iguales);
            if (resultado == OK) {
                cout << "Las versiones son " << (iguales ? "IGUALES" : "DIFERENTES") << endl;
            }
        }
    }
    else if (strcmp(comando, "salir") == 0) {
        if (archivoActual) {
            BorrarArchivo(archivoActual);
        }
        cout << "¡Hasta luego!" << endl;
        exit(0);
    }
    else {
        cout << "ERROR: Comando no reconocido" << endl;
        cin.ignore(1000, '\n'); // Limpiar buffer
    }
}