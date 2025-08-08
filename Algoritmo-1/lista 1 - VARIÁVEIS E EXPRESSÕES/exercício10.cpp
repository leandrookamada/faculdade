//EXERCÍCIO10
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float M, K;
	
	printf ("Qual é a velocidade mínima da sua rua?(escreva em Km/m\n)");
	scanf("%f", &K);
	
	M = K / 3.6;
	
	printf ("Seguindo a lei, na sua rua você poderia andar em até %.2f, em m/s\n", M);
	
	return 0;
}
