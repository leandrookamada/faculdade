#include<stdio.h>
#include<math.h>
float comprimento(float r){
    float comp = (2*3.14)*r;
    return comp;
}
float calcula_area(float r){
    float area = 3.14*(pow(r, 2));
    return area;
}

int main(){
    int raio;
    printf("Por favor, insira o valor da área: ");
    scanf("%d", &raio);

    float comp = comprimento(raio);
    float area = calcula_area(raio);

    printf("A área é: %.1f \n O comprimento é: %.1f", area, comp);
    return 0;
}