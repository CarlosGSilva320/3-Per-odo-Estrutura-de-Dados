//16. Desenvolva um programa que utilize uma função para calcular o quadrado de um número.

#include <stdio.h>

int calcQuadrado (int n) {
    int quadrado;

    quadrado = n * n;
    return quadrado;

// ou return n * n;
}

int main() {
    int numero, resultado;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    resultado = calcQuadrado(numero);

    printf("O quadrado do numero '%d' e '%d'", numero, resultado);
    
}