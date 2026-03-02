//11. Crie um programa que leia 5 números inteiros e mostre a soma deles.

#include <stdio.h>

int main() {

    int numero, i;
    int soma = 0;

    for (i = 1; i <= 5; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%d", &numero);
        soma = soma + numero;
    }

    printf("%d", soma);

}