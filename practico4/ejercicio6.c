#include <stdio.h>

int main() {
	int hor,horx,min,prec=40,prex=15,pref=0;
	printf ("Por favor coloque el tiempo que estuvo en el parqueo separado por un espacio(2h20m= 2 20):\n");
	scanf(" %d %d ",&hor,&min);
	if (hor<2 && min<=0){
		pref=prec;
	}else{
		horx=hor-2;
		pref=prec+(horx*prex);
		if (min>0){
			horx++;
		}
	}
	printf ("El precio total es :%d",pref);
	
	
	return 0;
}

