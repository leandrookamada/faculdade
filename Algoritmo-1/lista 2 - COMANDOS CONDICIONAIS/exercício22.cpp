#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    float cond[2];

    printf("\nInsira a sua idade:\n");
    scanf("%f", &cond[0]);
    printf("\nInsira o seu tempo de serviço:\n");
    scanf("%f", &cond[1]);

    if(cond[0] >= 65 && cond[1] >= 30){
        printf("\nParabéns, você está apto para se aposentar.\n");
    } else if(cond[0] >= 60 && cond[0]<=65 && cond[1] >= 25){
        printf("\nParabéns, você está apto para se aposentar.\n");
    } else{
        printf("\nInfelizmenta você não está apto para se aposentar.\n");
    }

    return 0;
}