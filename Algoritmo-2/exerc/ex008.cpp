#include<stdio.h>

int potencia(int num1, int num2){
    if(num2 == 1){
        return 1;
    } else {
        return (num1 * (potencia(num2-1 )));
    }
}

