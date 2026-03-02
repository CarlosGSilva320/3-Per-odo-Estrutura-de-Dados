//5. Faça um programa que conte quantos números pares existem em um vetor.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;
    int contador = 0;

    for (i = 0; i < 5; i++){
        printf("Digite o vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0){
            contador += 1;
        }
    }
    printf("%d", contador);
    return 0;
}