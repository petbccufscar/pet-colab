#include <stdio.h> //Essas são as bibliotécas básicas da linguagem c
#include <stdlib.h>

int main(){
    /* 
    A função printf é usada 
    para escrever texto na tela
    */ 
    printf("Hello World! \n\n");

    //Declaração de variáveis
    //Sempre iniciar variáveis para evitar incosistências
    int x = 0; 
    int y = 0; 
    int z = 0;

    printf("Insira o valor de x: ");
    //Lendo os valores das variáveis pelo teclado
    scanf("%d", &x);
    printf("\n");

    printf("Insira o valor de y: ");
    //Lendo os valores das variáveis pelo teclado
    scanf("%d", &y);
    printf("\n");

    //Condicional, a execução do código muda de acordo com a condição
    if (x>y){
        printf("(%d>%d), x maior. \n", x, y);
    }else {
        printf("(%d>%d), y maior. \n", y, x);
    }
    printf("\n");

    //Realizar a multiplicação entre variáveis
    z = x*y;

    //Imprimir o resultado na tela
    printf("Resultado de x . y = %d \n", z);
    
    //Sinaliza o final do código
    return 0;
}