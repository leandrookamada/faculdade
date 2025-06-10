#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    float NOTA[2], MEDIA;

    for(int i=0; i<2; i++){
        printf("\nInsira a nota do %dº semestre:\n", i+1);
        scanf("%f", &NOTA[i]);
    }
    if((0.00 <= NOTA[0] && NOTA[0] <= 10)&&(0.00 <= NOTA[1] && NOTA[1] <= 10)){
        MEDIA=(NOTA[0]+NOTA[1])/2;
        printf("\n, A média desse aluno é: %.2f.", MEDIA);
    } else{
        printf("\nAlguma nota inserida está inválida.");
    }
    return 0;
}

//O problema estáva  na forma que eu inseri dentro da condição do if, o que deveria ser usado são 
//operadores de comparada &&(and) ||(or), dessa forma eu criaria mais de uma condição, cada uma  
// dentro de um parentese dessa forma ->>>> OBSERVE QUE OS DOIS PARENTESES ESTÃO DENTRO DE OUTRO
// PARENTESE MAIOR.
//"if ((0 >= NOTA[0] && NOTA[0] >= 10) && (0 >= NOTA[1] && NOTA[1]>= 10))" ao invés
// de if(0<= NOTA[0] <= 10, 0<= NOTA[1] <= 10)