#include <stdio.h>
#define MAX_SIZE 5

int fila[MAX_SIZE];
int frente = 0;
int tras = -1;

int estaVazia () {
    return frente > tras;
}

int estaCheia() {
    return tras == MAX_SIZE -1;
}

void enfileirar(int valor) {
    if (estaCheia()) {
        printf("Erro: Fila linear cheia!\n");
        return;
    }
    tras++;
    fila[tras] = valor;
    printf("Enfileirado: %d\n", valor);
}

int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!");
        return -1;
    }
    int valor = fila[frente];
    frente++;
    return valor;
}

void exibirFila() {
    if (estaVazia()) {
        printf("Fila Vazia!\n");
        return;
    }
   
    for (int i = frente; i <= tras; i++) {
        printf("Fila[%d]: %d\n", i, fila[i]);        
    }
    printf("\n");
}

int main() {
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);

    exibirFila();

    printf("Desinfileirado: %d\n", desenfileirar());

    exibirFila();

    return 0;
}
