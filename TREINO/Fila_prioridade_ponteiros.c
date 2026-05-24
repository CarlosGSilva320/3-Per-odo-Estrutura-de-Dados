#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    int prioridade;
    struct No *prox;
} No;

No *inicio = NULL;

int filaVazia() {
    return inicio == NULL;
}

void enqueue(int valor, int prioridade) {

    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de memoria!\n");
        return; 
    }

    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->prox = NULL;

    if(filaVazia()) {
        inicio = novo;
    } else {
        if(prioridade > inicio->prioridade) {
            novo->prox = inicio;
            inicio = novo;
        } else {
            No *atual = inicio
        }

    }
}