#include <stdio.h>
#define MAX 5

int fila[MAX];
int frente = 0;
int tras = -1;

int estaVazia() {
    return frente > tras;
}

int estaCheia() {
    return tras == MAX -1; 
}

void enfileirar(int valor) {
    if(estaCheia()) {
        printf("Erro: fila cheia!");
    return;
    }
    tras++;
    fila[tras] = valor;
    printf("Enfileirdo: %d\n", valor);
}

int desenfileirar() {
    if(estaVazia()) {
        printf("Erro: fila vazia!");
        return -1;
    }
    int valor = fila[frente];
    frente++;
    return valor;    
}

void exibirFila() {
    if(estaVazia()) {
        printf("Erro: fila vazia!");
        return;
    }
    for(int i = frente; i <= tras; i++) {
        printf("Fila[%d]: %d\n", i, fila[i]);
    }
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

    return 0;
}