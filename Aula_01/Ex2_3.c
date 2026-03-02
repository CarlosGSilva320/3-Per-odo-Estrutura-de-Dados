//3. Desenvolva um programa que calcule a soma dos elementos de um vetor. 

#include <stdio.h>

int main() {
    int vetor[5];
    int i;
    int soma = 0;

    for (i = 0; i < 5; i++){
        printf("Digite o vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    printf("A soma dos vetores e igual a: %d", soma);
    return 0;
}