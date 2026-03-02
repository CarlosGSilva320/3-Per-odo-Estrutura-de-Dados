//17. Crie um programa que leia dois números e utilize uma função para retornar o maior.

#include <stdio.h>

int funMaior(int m, int n) {
    int maior;
    maior = 0;

    if (m > n) {
        maior = m;
    } else {
        maior = n;
    }
    return maior;
}

int main() {
    int  n1, n2, resultado;

    
    printf("Digite o 1 numero: ");
    scanf("%d", &n1);

    printf("Digite o 2 numero: ");
    scanf("%d", &n2);
    
    resultado = funMaior(n1, n2);
    printf("O numerto maior e: %d", resultado);
}


    

