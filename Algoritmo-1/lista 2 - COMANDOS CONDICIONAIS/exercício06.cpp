#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int N[2], D;
    for(int i=0; i<2;i++){
        printf("Insira o %dº número", i+1);
        scanf("%d", &N[i]);
    }
    
    if( N[0]>N[1]){
        D = N[0]-N[1];
        printf("\nO maior número inserido é %d, e a diferença entre eles era igual a %d", N[0], D);
    } else{
        D = N[1]-N[0];
        printf("\nO maior número inserido é %d, e a diferença entre eles era igual a %d", N[1], D);
    }
    return 0;
}