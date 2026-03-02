//10. Faça um programa que leia um número e calcule seu fatorial (usando for).

#include <stdio.h>

int main() {

    int numero, i;
    int fatorial = 1;

    printf("Digite um numero para saber seu fatorial: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; i++) {
        fatorial = fatorial * i;
    }

    printf("O fatorial de %d e : %d", numero, fatorial);

    return 0;

}