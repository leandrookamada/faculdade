#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int x[4];
    printf("insira um valor \n");
    scanf("%d", &x[0]);

    for(int i = 1; i <= 3; i++){
        x[i] = x[0] * (i+1);
    }

    printf("Os três primeiros multiplos do número são %d, %d, %d, e o número foi %d", x[1], x[2], x[3], x[0]);

    return 0;
}