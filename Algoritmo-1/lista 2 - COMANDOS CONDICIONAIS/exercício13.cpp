 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>

 int main(){
    float NOTAS[3], M;

    for(float i=0; i < 3; i++){
        printf("\nInsira a nota (10 a 100) do seu %.0fº prova:\n", i+1);
        scanf("%f", &NOTAS[(int)i]);
    }
    M = NOTAS[0] + NOTAS[1] + (NOTAS[2] * 2) / 4;
    printf("\nA média ponderada das suas notas é: %f\n e as suas notas foram:\n", M);

    
    for (int i = 0; i < 3; i++){
        printf("%.2f", NOTAS[i]);
        printf("\n");
    }
    if(60<=M){
        printf("\nAluno aprovado.");
    } else {
        printf("\nAluno reprovado.");
    }
    return 0;
 }