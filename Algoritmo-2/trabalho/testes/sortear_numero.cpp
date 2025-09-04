#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    int num[16];

    srand(time(NULL)); // isso vai fazer gerar o número aleatório todas as vezes. se eu colocar dentro do for, ele vai gerar o mesmo número todas as vezes.

    for(int i = 0; i < 16; i++){
        num[i] = (rand()%59) + 1;
    }

    for(int i = 0; i < 16; i++){
        printf("%d \n", num[i]);
    }

return 0;
}

// problema: o número pode ser repetido