#include <stdio.h>
#define MAX_SIZE 5

int fila[MAX_SIZE];
int frente = 0;
int tras = -1;

int estaVazia() {
    return frente > tras;
}

int estaCheia() {
    return tras == MAX_SIZE -1;
}

void enfileirar(int valor) {
    if (estaCheia()) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    tras++;
    fila[tras] = valor;
    printf("Enfileirado: %d\n", valor);
}

int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = fila[frente];
    frente++;
    return valor;
}

void exibirFila() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!");
        return;
    }

    for (int i = frente; i <= tras; i++) {
        printf("Fila[%d]: %d\n", i, fila[i]);
    }
    printf("\n");
}

int main() {
    enfileirar(1);
    enfileirar(2);
    enfileirar(3);
    enfileirar(4);
    enfileirar(5);

    exibirFila();

    printf("Desenfileirar: %d\n", desenfileirar());

    exibirFila();

}