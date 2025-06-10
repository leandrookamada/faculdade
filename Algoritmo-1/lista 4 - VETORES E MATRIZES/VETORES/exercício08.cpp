#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int A[10];
    for(int i = 0; i < 10; i++){
        printf("\ninsira um valor: ");
        scanf("%d", &A[i]);
    }
    for(int i = 9; i >= 0; i--){
        printf("\n %d valor: %d\n ",i + 1,  A[i]);
    }
    return 0;
}