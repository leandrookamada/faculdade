#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int N;
    printf("\nInsira um numero inteiro\n");
    scanf("%d", &N);

    if((N % 5)==0 || (N % 3)== 0){
        if ((N%5)==0 && (N%3)==0){
            printf("\nO número é divisivel por 3 e por 5\n");
        } else{
            if ((N%5)==0){
                printf("\nOnúmero é divisivel por 5.\n");
            } else{
                printf("\nO número é divisivel por 3.\n");
            }
        }
    }else{
        printf("\nO número não é divisivel, nem por 5, nem por 3.");
    }
    return 0;
}