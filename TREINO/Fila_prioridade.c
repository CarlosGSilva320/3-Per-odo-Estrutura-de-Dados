#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int valor;
    int prioridade;
} Elemento;

Elemento fila[MAX];
int tamanho = 0;

int filaVazia() {
    return tamanho == 0;
}

int filaCheia() {
    return tamanho == MAX;
}

void enqueue(int valor, int prioridade) {
    if(filaCheia()) {
        printf("Fila cheia\n");
        return;
    }

    fila[tamanho].valor = valor;
    fila[tamanho].prioridade = prioridade;
    tamanho++;

    printf("Elemento %d inserido com prioridade %d\n", valor, prioridade);
}

void dequeue() {
    if(filaVazia()) {
        printf("Fila vazia!");
        return;
    }

    int maiorPrioridade = 0;

    for (int i = 1; i < tamanho; i++) {
        if (fila[i].prioridade > fila[maiorPrioridade].prioridade) {
            maiorPrioridade = i;
        }
    }

    printf("Removido: %d (Prioridade: %d)\n",
    fila[maiorPrioridade].valor,
    fila[maiorPrioridade].prioridade);

    for (int i = maiorPrioridade; i < tamanho -1; i++) {
        fila[i] = fila[i + 1];
    }

    tamanho--;
}

    void exibirFila() {
        if (filaVazia()) {
            printf("Fila vazia.");
            return;
        }

        printf("\nFila de Prioridade:\n");

        for(int i = 0; i < tamanho; i++) {
            printf("Valor: %d | Prioridade: %d\n",
                fila[i].valor,
            fila[i].prioridade);
        }
}

int main() {

    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 1);
    enqueue(40, 4);

    exibirFila();

    printf("\n");

    dequeue();

    printf("\n");

    exibirFila();

    return 0;
}