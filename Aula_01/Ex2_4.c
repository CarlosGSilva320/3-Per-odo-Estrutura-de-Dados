//4. Crie um programa que encontre o maior valor em um vetor de 5 posições.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;
    int maior = 0;

    for (i = 0; i < 5; i++) {
        printf("Digite o vetor[%d]: ", i);
        scanf("%d", &vetor[i]);

        if (vetor[i] > maior){
            maior = vetor[i];
        }
    }

    printf("%d", maior);
    return 0;

}