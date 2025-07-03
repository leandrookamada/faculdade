#include<stdio.h>
#include<math.h>

float calculaAMedia(int A[15]){
    float media;
    for(int i = 0; i < 15; i++){
        media += A[i];
    }
    
    return media/15;
}

int calculaMaior(int A[15]){
    int maior = 0;
    for (int i = 0; i < 15; i++){
        if(maior < A[i]){
            maior = A[i];
        }
    }
    return maior;
}

int calculaMenor(int A[15]){
    int menor = 100;
    for (int i = 0; i < 15; i++){
        if(menor > A[i]){
            menor = A[i];
        }
    }
    return menor;
}

int main(){
    int maior, menor, A[15];
    float media;
    for (int i = 0; i < 15; i++){
        printf("\nPor favor, insira a nota do %d aluno: ", i+1);
        scanf("%d", &A[i]);
    }
    media = calculaAMedia(A);
    maior = calculaMaior(A);
    menor = calculaMenor(A);

    printf("\nA media da turma é: %.1f\n", media);
    printf("\nA maior nota da turma foi: %d\n", maior);
    printf("\nA menor nota da turma foi: %d\n", menor);

    return 0;
    
}