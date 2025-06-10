#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int N, num1[3], MAIOR, MEIO, MENOR;

    printf("\ninsira um número com duas casas decimais:\n");
    scanf("%d", &N);

    for(int i=0; i < 3; i++){
        num1[i] = N % 10;  
    }

    printf ("números: %d; %d; %d", num1[0], num1[1], num1[2]);

    if (num1[0] < num1[1] && num1[1] < num1[2]){

    }
    if (num1[1] < num1[2] && num1[2] < num1[0]){

    }
    if (num1[2] < num1[0] && num1[0] < num1[1]){

    }
    return 0;
}