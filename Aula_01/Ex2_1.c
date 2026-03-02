//1. Declare um vetor de 5 inteiros e atribua valores manualmente.

#include <stdio.h>

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};
    int i;

    
    for (i = 0; i < 5; i++) {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
    return 0;
}