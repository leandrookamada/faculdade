//EXERCÍCIO12
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	float M, K;
	
	printf("Quantas milhas tem o terreno em que você mora?\n");
	scanf ("%f", &M);
	
	K = 1.61*M;
	
	printf("Isso equivale a %.2f em Quilometros", K);
	return 0;
}
