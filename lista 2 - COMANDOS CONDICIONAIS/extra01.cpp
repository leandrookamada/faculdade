//////EXCÍCIO01
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int VALOR, num_valor[2], MAIOR, R, SOMA, R2;
    do {
        printf("\nQuantos número você deseja inserir?\n");
        scanf("%d", &VALOR);
        if(VALOR != 2){
            printf("\nEstou brincando, vou armazenar só dois números\n");
        }
    } while( VALOR != 2);

    printf("\n Nossa, fico feliz que você pensa no meu armazenamento ;) \n Ok!! Vamos lá\n");

    for(int i = 0; i < 2; i++){
        printf("\nAgora, preciso que você insira o %dº número:\n", i + 1);
        scanf("%d", &num_valor[i]);
    }

    printf("\nOs número inseridos foram %d e %d, correro?(S=true e F=false)\n\n", num_valor[0], num_valor[1]);
    scanf("%d", &R);

    do{
        printf("\nOs número inseridos foram %d e %d, correro?(S=true e F=false)\n\n", num_valor[0], num_valor[1]);
        scanf("%d", &R);
        if(R =='F'){
            printf("\nTem certeza? Veja novamente\n");
        }
    } while (R =='F');

    SOMA = num_valor[0] + num_valor[1];
    if( num_valor[0] > num_valor[1]){
        MAIOR = num_valor[0];
    } else{
        MAIOR = num_valor[1];
    }

    printf("\n Que ótimo!!\n Você sabia que entre eles, a soma vale %d e o maior número é %d?(S=true e F=false)\n", SOMA, MAIOR);
    scanf("%d", &R2);
    
    if(R2 == 'S'){
        printf("\npsh... mas tbm não saber isso é foda né...\n");
    } else{
        printf("\nPo, você é muito burro, tchua\n");
    }
    return 0;
}