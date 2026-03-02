//15. Faça um programa que leia um número e utilize uma função para verificar se ele é par.

#include <stdio.h>

int verificaPar(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (verificaPar(numero) == 1) {
        printf("O numero '%d' e par", numero);
    } else {
        printf("O numero '%d' e impar", numero);
    }
}