//9. Desenvolva um programa que leia um número inteiro e mostre os números de 1 até ele.

#include <stdio.h>

int main() {
    int numero, i;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for ( i = 1; i <= numero; i++) {
        printf("%d\n", i);
    }

    return 0;
}