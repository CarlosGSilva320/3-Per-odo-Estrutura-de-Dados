//13. Escreva um programa que leia um vetor de 10 posições e mostre seus valores.

#include <stdio.h>

int main() {
    int vetor[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor na posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("Valor na posicao %d: %d\n", i, vetor[i]);
    }
}