//EXERCÍCIO15
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//#define PI 3.14 (isso equivale ao escopo Global)
// a boa pratica de programação me instrui a escrever variáveis em maiusculos

int main(){
	float R, G, D;
	const double PI=3.14;
	
	printf ("Qual é o diametro da base da sua garrafa?");
	scanf ("%f", &D);
	
	R=D/2;
	G=R*180/PI;
	
	printf("tendo em vista isso, o ângulo, em radianos, da sua garrafa, equivale a %.2f", G);
	
	return 0;
}
