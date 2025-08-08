#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    int N[2], M;
    for(int i=0;i<2;i++){
        printf("\nInsira o %dº numero:", i+1);
        scanf("%d", &N[i]);
    }
    if(N[0]>N[1]){
        M = N[0];
    } else{
        M = N[1];
    }
    if(N[0]==N[1]){
        printf("\nOs número são iguais.");
    } else{
        printf("\n Omaior número inserido foi %d", M);
    }
    return 0;
}