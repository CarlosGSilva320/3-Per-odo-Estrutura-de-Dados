//5. Faça um programa que leia um número inteiro e informe se ele é par ou ímpar.

#include <stdio.h>

int main() {

    int numero;

    printf("Digite um numero para saber se e par ou impar: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O numero %d e par", numero);
    } else {
        printf("O numero %d e impar", numero);
    }
    return 0;
    
}