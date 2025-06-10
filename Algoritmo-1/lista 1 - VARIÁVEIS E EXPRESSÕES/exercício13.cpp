//EXERCÍCIO13
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float K, M;
	
	printf ("Quantos quilometros tem da sua casa até a sua faculdade?\n");
	scanf ("%f", &K);
	
	M = K / 1.61;
	
	printf ("Essa medida em milhas equivale a %.2f quilometros");
	
	return 0;
}
