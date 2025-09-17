#include<stdio.h>

int main(){
    int x, *p, **q;

    x = 10;

    p = &x;

    q = &p;

    printf("Valor atribuido a x é %d \n", x);
    printf("Valor de x, acessado pelo ponteiro doplo %d\n", **q);

    return 0;
} 