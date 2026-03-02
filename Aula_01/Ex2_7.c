//7. Faça um programa que leia os valores de uma matriz 2x2.

#include <stdio.h>

int main() {
    int matriz[2][2];
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Digite o valor matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d", matriz[i][j]);            
        }        
        printf("\n");
    }
    return 0;
}