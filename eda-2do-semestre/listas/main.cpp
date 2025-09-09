#include<iostream>
using namespace std;
#include "prototipo.h"


int main (int argc, char *argv[]) {
	lista cabezal;
	cabezal = creo_vacia();
	/*
	if (es_vacia(cabezal)){
		cout << "La lista esta vacia"<<endl;
	}else{	
		cout << "La lista NO esta vacia"<<endl;
	}

	cabezal = insertoPrincipio(cabezal, 10);
	cabezal = insertoPrincipio(cabezal, 20);
	cabezal = insertoPrincipio(cabezal, 30);
	cabezal = insertoPrincipio(cabezal, 40);
	
	insertoPrincipio2(cabezal, 50);  //procedimiento para insertar
	
	cabezal = insertoFinal(cabezal,5);
	
	if (es_vacia(cabezal)){
		cout << "La lista esta vacia"<<endl;
	}else{	
		cout << "La lista NO esta vacia"<<endl;
	}
	
	cout << "El primer valor del nodo de la lista es: " <<primero(cabezal)<<endl;
	
	cout << "Muestro lista recursivamente: ";
	imprimoRecursivo(cabezal);
	
	cout << endl << "Muestro lista iterativamente: ";
	imprimoIterativo(cabezal);
	
	
	cout << endl << "La cantidad de nodo es: " << cantidadNodos(cabezal) << endl;
	
	cout << endl << "La cantidad de nodo es: " << cantidadNodosIterativo(cabezal) << endl;
	
	cout << "La suma de los nodos es: "<<sumaNodos(cabezal)<<endl;
	
	cout << "El ultimo valor de la lista es: " << ultimo(cabezal)<<endl;
	
	cout << "Lugar del valor 20 en la lista: " << lugar(cabezal,20)<<endl;
	
	insertarDespuesde(cabezal,5,35);
	
	imprimoRecursivo(cabezal);
	cout << endl;
	insertarAntesde(cabezal,35,11);
	imprimoIterativo(cabezal);
	
	cout << endl;
	cout << dirNodo(cabezal,20) <<endl;
	
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cabezal = eliminoPrincipio(cabezal);
	cout << endl;
	imprimoRecursivo(cabezal);
	cout << endl;
	imprimoIterativo(cabezal);*/
	cabezal = insertoPrincipio(cabezal, 50);
	cabezal = insertoPrincipio(cabezal, 20);
	cabezal = insertoPrincipio(cabezal, 10);
	/*cabezal = insertoPrincipio(cabezal,1000);
	cout << "Inserto el 10, 100 y 1000"<< endl;
	imprimoIterativo(cabezal);
	cout << "Borror el ultimo "<<endl;
	cabezal = eliminoUltimo(cabezal);
	cout << endl;
	cout << "Muestro lista"<<endl;
	imprimoIterativo(cabezal);
	cabezal = eliminoUltimo(cabezal);
	cabezal = eliminoNodo(cabezal,100);*/
//	cout << "Unir"<<endl;
//	imprimoIterativo(cabezal);
//	cout << endl;
	lista cabezal2=NULL;
	//cabezal = unirLista(cabezal,cabezal2);
	cout << "Lista 1 - ";
	imprimoIterativo(cabezal);
	cabezal2 = insertoPrincipio(cabezal2, 50);
	cabezal2 = insertoPrincipio(cabezal2, 14);
	cabezal2 = insertoPrincipio(cabezal2, 12);
	cout << "Lista 2 - ";
	imprimoIterativo(cabezal2);
	cout << endl;
	//cabezal = unirLista(cabezal,cabezal2);
	//imprimoIterativo(cabezal);
	cabezal = intercalarLista(cabezal,cabezal2);
	cout << "Lista intercalada - ";
	imprimoIterativo(cabezal);
	return 0;
}