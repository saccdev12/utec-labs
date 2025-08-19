#include<iostream>
using namespace std;
#define T 5

void maxMinArr(int arr1[], int tamanio){
	int aux = arr1[0];
	
	
	for(int i=0; i<tamanio; i++){
		if(arr1[i]>aux){
			aux=arr1[i];
		}
	}
	
	cout << "El mayor es: "<<aux<<endl;
	
	for(int i=0; i<tamanio; i++){
		if(arr1[i]<aux){
			aux=arr1[i];
		}
	}
	
	cout << "El menor es: "<<aux;
}
	
int main (int argc, char *argv[]) {
	int arr1[] = {12, 18, 33, 24, 56};
		
	maxMinArr(arr1, T);
	return 0;
}	

