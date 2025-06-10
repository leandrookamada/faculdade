//EXERCÍCIO16
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float P, C;
	
	printf("Quantas polegadas você tem?\n");
	scanf("%f", &P);
	
	C = P*2.54;
	
	printf("\nisso equivale a %.2f cm.", C);
	
	return 0;
}
