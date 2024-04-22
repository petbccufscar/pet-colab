#include <stdio.h>
#include <stdlib.h> 

int main() {
    float a, b, c;
    printf("Informe o comprimento do primeiro segmento: ");
    scanf("%f", &a);
    printf("Informe o comprimento do segundo segmento: ");
    scanf("%f", &b);
    printf("Informe o comprimento do terceiro segmento: ");
    scanf("%f", &c);

    //Decidir se é ou não um triângulo
    if (a < b + c && b < a + c && c < a + b) {
        printf("Os segmentos formam um triângulo ");
        //Definir o tipo de triângulo
        if (a == b && b == c)
            printf("equilátero.\n");
        else if (a == b || b == c || a == c)
            printf("isósceles.\n");
        else
            printf("escaleno.\n");
    } else {
        printf("Os segmentos não formam um triângulo.\n");
    }
    return 0;
}
