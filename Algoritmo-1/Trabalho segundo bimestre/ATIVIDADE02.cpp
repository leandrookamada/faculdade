#include<stdio.h>
#include<math.h>

// Questão 02 - Leia 10 números inteiros e armazene-os em um vetor.
// Em seguida, identifique e  exiba os elementos que são números primos, juntamente com suas 
// respectivas posições no vetor.

int verificaSeEhPrimo(int NUMBER[10]){
    int incremento = 0;
    
    for(int i = 0; i < 10; i++){
        if(NUMBER[i] % 2 == 0 || NUMBER[i] % 3 == 0 || NUMBER[i] % 5 == 0 || NUMBER[i] % 7 == 0 || NUMBER[i] % 9 == 0){
            if(NUMBER[i] == 1 || NUMBER[i] == 2 || NUMBER[i] == 3 || NUMBER[i] == 5 || NUMBER[i] == 7 || NUMBER[i] == 9 ){
                
            }
        }
    }
    return 0;
}
int main(){
    int num[10];

    return 0;
}