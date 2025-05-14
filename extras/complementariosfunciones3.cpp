#include <iostream>
using namespace std;

void idProdGondola(int codigo, char & producto, int & gondola);

int main() {
	printf("Ingrese el código del producto: \n");
	int cod, gondola;
	scanf("%d", &cod);
	char prod;
	idProdGondola(cod, prod, gondola);
	printf("%d es un producto de tipo: %c y está en la gondola: %d", cod, prod, gondola);
	return 0;
}

void idProdGondola(int codigo, char & producto, int & gondola) {
	switch(codigo) {
	case 0:
		producto = 'A';
		gondola = 1;
		break;
	case 1:
		producto = 'L';
		gondola = 2;
		break;
	case 2:
		producto = 'C';
		gondola = 3;
		break;
	default:
		producto = 'O';
		gondola = 4;
	}
}
