//18. Faça um programa que leia um número inteiro e calcule a soma dos números pares até ele.


#include <stdio.h>

int main() {
    int i, numero;
    int soma = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; i++){
        if (i % 2 == 0){
            soma += i;
        }        
    }
    printf("A soma dos numeros pares e igual a: %d", soma);
    return 0;
}
