#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int zero = 0;
    for (int i = 0; i <= 100; i++){
        printf("\n%d", zero);
        zero = zero + 1000;
    }
    return 0;
}