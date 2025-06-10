//EXERCÍCIOS14
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//ESCOPO GLOBAL
#define Pi 3.14

int main(){
	float R, G;
	//const = 3.14; (isso equivale ao escopo local)
	
	printf("Qual é o ângulo (em graus), da sua garrafa de água?\n");
	scanf("%f", &G);
	
	R = G * Pi / 180;
	
	printf ("Você sabia que o raio da sua garrafa equivale a %.2f", R);
	
	return 0;
}
