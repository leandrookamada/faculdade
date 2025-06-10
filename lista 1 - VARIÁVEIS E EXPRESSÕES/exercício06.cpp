//ECERCÍCIO06
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int C, F;
	 printf("\n Quantos graus está na sua cidade?");
	 scanf("%d", &C);
	 
	 F=C * 9/5 +32 ;
	 
	 printf("\n Você sabia que isso é igual a %d, em graus Fahrenheit?", F);
	 
	return 0;
}
