//EXERCÍCIO17
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float M, C, P;
	
	printf ("Quantos metros você tem?\n");
	scanf("%f", &M);
	
	C = M*100;
	P = C/2.54;
	
	printf("\nEssa medida equivale a %f polegadas.", P);
	return 0;
}
