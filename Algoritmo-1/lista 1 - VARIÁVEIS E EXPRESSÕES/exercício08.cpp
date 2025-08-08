//EXERCÍCIO08
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float C, K;
	
	printf("Insira a a temperatura que você acabou de receber em Kelvin:\n");
	scanf ("%f", &K);
	
	C = 273.15 + K;
	
	printf ("Exatamente o mesmo valor %.2f em graus Céusios\n", C);
	
	return 0;
}
