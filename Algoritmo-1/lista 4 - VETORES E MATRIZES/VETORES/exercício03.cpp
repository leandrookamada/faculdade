#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int A[10], B[10];
    for(int j = 0; j < 10; j++){
        printf("\n insira um valor ");
        scanf("%d", &B[j]);
    }
    for (int i = 0; i < 10; i++){
        A[i] = pow(B[i], 2) ;
    }
    for(int i = 0; i < 10; i++){
        printf("\n %d", A[i]);
    }
    return 0;
}