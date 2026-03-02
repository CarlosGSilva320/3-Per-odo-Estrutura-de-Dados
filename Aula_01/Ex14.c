//14. Crie um programa que leia um vetor de 5 números e calcule a média.

#include <stdio.h>

int main() {

    int vetor[5];
    int i;
    float soma = 0;
    float media = 0;   
    

    for (i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &vetor[i]);
        soma = soma + vetor[i];
    }

    media = soma / 5;

    printf("A media e igual a: %.2f", media);


}