//8. Desenvolva um programa que calcule a soma dos elementos de uma matriz.


#include <stdio.h>

int main(){
    int matriz[2][2];
    int i,j;
    int soma = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Digite o valor matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            soma += matriz[i][j];
        }
    }
    printf("A soma dos elementos e igual a: %d", soma);
    return 0;
}