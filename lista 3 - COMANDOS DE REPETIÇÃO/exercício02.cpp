#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    //  USANDO FOR
    int i = 1;
    for (int i=1; i <= 100; i++){
        printf("\n%d", i);
    };
    //  USANDO WHILE
    while(i <= 100){
        printf("\n%d", i);
        i++;
    }
    //  USANDO DO WHILE
    do {
        printf("\n%d", i);
        i++;
    } 
    while( i < 101);
    
return 0;
 }

        