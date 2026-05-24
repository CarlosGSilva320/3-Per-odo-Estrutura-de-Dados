#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* frente = NULL;
No* tras = NULL;

int estaVazia() {
    return frente == NULL;
}

void enfileirar(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memeoria!\n");
    }

    novo-> valor = valor;
    novo ->prox = NULL;

    if(estaVazia()) {
        frente = novo;
        tras = novo;
    } else {
        tras->prox = novo;
        tras = novo;
    }

    printf("Enfileirado: %d\n", valor);
}

int desenfileirar() {
    if(estaVazia()) {
        printf("Erro: Fila vazia!");
        return -1;
    }

    No* temp = frente;
    int valor = temp->valor;

    frente = frente->prox;

    if (frente == NULL) {
        tras = NULL;
    }
    free(temp);
    return valor;
}

void exibirFila() {
    if (estaVazia()) {
        printf("Fila vazia!");
        return;
    }

    No* atual = frente;

    while (atual != NULL) {
        printf("->%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);
    enfileirar(40);
    enfileirar(50);

    exibirFila();

    printf("Desenfileirar: %d\n", desenfileirar());
    printf("Desenfileirar: %d\n", desenfileirar());

    exibirFila();
}

