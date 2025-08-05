#include <stdio.h>
int main(){
	char letra;
	printf("Ingresa una letra:\n");
	scanf ("%c",&letra);
	switch (letra){
	case 'd':
	case 'f':
		printf ("Trabajo deficiente \n");
		break;
	case 'c':
	case 'b':
		printf ("buen trabajo \n");
		break;
	case 'a':
		printf ("trabajo excelente.\n");
		break;
		
	default:
		break;
	} 
	
	
	
}
	
	
