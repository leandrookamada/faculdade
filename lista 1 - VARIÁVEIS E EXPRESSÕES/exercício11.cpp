//EXERCPICIO11
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	float M, K;
	
	printf ("Até quantos m/s algum veículo pode andar na sua rua?(seguindo as leis de transito).\n");
	scanf ("%f", &M);
	
	K = M * 3.6;
	
	printf ("Apartir disso, você pode andar até %.2f km/h, na sua rua.\n", K); 
	
	return 0;
}
