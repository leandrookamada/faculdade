//EXERCPICIO18
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	float MC, L;
	
	printf ("Fale um número, mas pense nele em metros cúbicos.\n");
	scanf ("%f", &MC);
	
	L = 1000*MC;
	
	printf("\nEsse valor equivale a %.2L.", L);
	
	return 0;
}