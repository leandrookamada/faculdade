//EXERCÍCIO05
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	float x, y;
	
	printf("Insira um número, maior que 4:");
	scanf("%f", &x);
	
	y=x/5;
	
	printf("\n a quinta parte do número escolhido foi: %.2f", y);
	return 0;
}
