//EXERCÍCIO07
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float C, K;
	
	printf("\n Quantos Graus está fazendo?(responda em graus Kelvin):\n");
	scanf("%f", &K);
	
	C= 273.15 - K;
	
	printf("\n Essa temperatura equivale a %f", C);
	
	return 0;
}
