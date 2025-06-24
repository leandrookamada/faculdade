#include<stdio.h>
#include<math.h>

int retornaOMaior(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}
int main(){
    int x, y, maior;
    
    printf("Por favor, insira algum valor: ");
    scanf("%d", &x);
    printf("Por favor, insira algum outro valor: ");
    scanf("%d", &y);

    maior = retornaOMaior(x, y);

    printf("O maior número inserido foi %d", maior);

    return 0;
}