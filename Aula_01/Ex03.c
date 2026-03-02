//3. Crie um programa que leia dois números inteiros e mostre a soma deles.

#include <stdio.h>

int main() {

    int n1, n2, soma;
    
    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);

    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    soma = n1 + n2;

    printf("A soma de %d com %d e: %d", n1, n2, soma);



}