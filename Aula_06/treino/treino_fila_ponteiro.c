#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int frente;
    int tras;
    int tamanho;
    int capacidade;
} Fila;

Fila* criarFila(int capacidade) {
    Fila *f = (Fila*) malloc(sizeof(Fila));

    
}