#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 1000000;
    int *vetor = malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro de memória\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }

    printf("%d\n", vetor[n-1]);

    free(vetor);
    return 0;
}