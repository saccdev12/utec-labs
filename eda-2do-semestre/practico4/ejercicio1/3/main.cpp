#include<iostream>
#include "ejercicio3.h"
using namespace std;
#define T 5


int main () {
	int num1[] = {7, 81, 50, 30, 42};
	int num2[] = {7, 81, 50, 30, 42};
	
	if(igualesR(num1, num2, T)==1){
		cout << "Son Iguales";
	}else{
		cout << "No son Iguales";
	}
	return 0;
}

