//2. Faça um programa que leia um número inteiro e mostre esse número na tela.

#include <stdio.h>

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("O numero digitado e: %d", numero);
    return 0;
}