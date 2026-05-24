#include <stdio.h>
#define MAX_SIZE 5

int fila[MAX_SIZE];
int frente = 0;
int tras = 0;
int tamanho = 0;

int estaVazia() {
    return tamanho == 0;
}

int estaCheio() {
    return tamanho == MAX_SIZE;
}

void enfileirar(int valor) {
    if (estaCheio()) {
        printf("Erro: Fila cheia!\n");
        return;
    }

    fila[tras] = valor;
    tras = (tras + 1) % MAX_SIZE;
    tamanho++;

    printf("Enfileirado: %d\n", valor);
}

int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }

    int valor = fila[frente];
    frente = (frente + 1) % MAX_SIZE;
    tamanho--;

    return valor;
}

void exibirFila() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return;
    }

    int i = frente;
    for (int count = 0; count < tamanho; count++) {
        printf("%d ", fila[i]);
        i = (i + 1) % MAX_SIZE;
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

    printf("Desenfileirado: %d\n", desenfileirar());
    printf("Desenfileirado: %d\n", desenfileirar());

    enfileirar(60);
    enfileirar(70);

    exibirFila();
}
