#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int A[6];
    for(int i =0; i < 6; i++){
        printf("\nInsira um valor: ");
        scanf("%d", &A[i]);
    }
    for(int i =0; i < 6; i++){
        printf("\n %d", A[i]);
    }
    
    return 0;
}