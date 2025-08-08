#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float L, S, F, M;

    printf("\nInsira a sua nota da avaliação de laboratório:\n");
    scanf("%f", &L);
    printf("\nInsira a sua nota do exame semestral:\n");
    scanf("%f", &S);
    printf("Insira a sua nota no exame final:\n");
    scanf("%f", &F);

    M = (L*2+S*3+F*5)/10;

    if (M<=2.9){
      printf("\nAluno reprovado\n Media inferior a 3\n Sua média foi %.2f", M);
    } else {
        printf("\nAluno aprovado!\n Media maior ou igual a 3\n Sua media foi: %.2f", M);
    }

    return 0;
}