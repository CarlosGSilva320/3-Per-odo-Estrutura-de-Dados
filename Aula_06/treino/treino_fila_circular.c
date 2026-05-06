#include <stdio.h>
#define MAX 5

int fila[MAX];
int frente = 0;
int tras = 0;
int tamanho = 0;

int estaVazia() {
    return tamanho == 0;
}

int estaCheia() {
    return tamanho == MAX;
}

void enfileirar(int valor) {
    if(estaCheia()) {
        printf("Erro: fila cheia!");
        return;
    }
    fila[tras] = valor;
    tras = (tras + 1) % MAX;
    tamanho++;
    printf("Enfileirado: %d\n", valor);
}

int desenfileirar() {
    if(estaVazia()) {
        printf("Erro: fila vazia!");
        return -1;
    }
    int valor = fila[frente];
    frente = (frente + 1) % MAX;
    tamanho--;
    return valor;
}

void exbirFila() {
    if(estaVazia()) {
        printf("Erro: fila vazia!");
        return;
    }
    int i = frente;
    for(int count = 0; count < MAX; count++) {
        printf("Fila[%d]: %d\n", count, fila[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);
    enfileirar(40);
    enfileirar(50);

    exbirFila();

    printf("Desenfileirar: %d\n", desenfileirar());
    printf("Desenfileirar: %d\n", desenfileirar());

    enfileirar(60);
    enfileirar(70);

    exbirFila();

    return  0;



}