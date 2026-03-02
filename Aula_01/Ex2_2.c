//2. Faça um programa que leia 5 números em um vetor e mostre-os na tela.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
    return 0;
}