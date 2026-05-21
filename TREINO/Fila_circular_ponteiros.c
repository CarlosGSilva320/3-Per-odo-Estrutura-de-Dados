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

    f ->dados = (int*) malloc(capacidade *sizeof(int));

    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

int estaVazia(Fila *f) {    
    return f-> tamanho == 0;
}

int estaCheia(Fila *f) {
    return f->tamanho == f->capacidade;
}

void enfileirar(Fila *f, int valor) {
    
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }

    f->tras = (f->tras + 1) % f->capacidade;
    *(f->dados + f->tras) = valor;
    f->tamanho++;

    printf("Enfileirado: %d\n", valor);
}

int desenfileirar(Fila *f) {

    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }

    int valor = *(f->dados + f->frente);
    f->frente = (f->frente + 1) % f ->capacidade;
    f->tamanho--;

    return valor;
}

void exibirFila(Fila *f) {

    if(estaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    printf("Fila: ");

    int i = f-> frente;

    for (int count = 0; count < f-> tamanho; count++) {
        printf("%d", *(f->dados + i));

        i = (i + 1) % f-> capacidade;
    }
    printf("\n");
}

void liberarFila(Fila *f) {
    free(f->dados);
    free(f);
}

int main() {

    Fila *fila = criarFila(5);

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    enfileirar(fila, 50);

    exibirFila(fila);

    printf("Desenfileirar: %d\n", desenfileirar(fila));
    printf("Desenfileirar: %d\n", desenfileirar(fila));

    exibirFila(fila);

    enfileirar(fila, 60);
    enfileirar(fila, 70);

    exibirFila(fila);

    liberarFila(fila);

    return 0;
}


