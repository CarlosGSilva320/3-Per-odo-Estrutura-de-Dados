#include <stdio.h>
#define MAX 100

int pilha[MAX];
int topo = -1;

void empilhar(int valor) {
    if(topo == MAX - 1) {
        printf("Erro: pilha cheia!\n");
        return;
    }
    topo++;
    pilha[topo] = valor;
    printf("Empilhado: %d\n", valor);
}

int desempilhar() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!");
        return -1;
    }

    int valor = pilha[topo];
    topo--;
    return valor;
}

int consultarTopo() {
    if(topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha[topo];
}

void mostrarPilha() {
    if(topo == - 1) {
        printf("Pilha vazia!");
        return;
    }
    printf("Pilha (do topo para base): \n");
    for(int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    empilhar(10);
    empilhar(20);
    empilhar(30);
    empilhar(40);

    mostrarPilha();

    printf("Desempilhar: %d\n", desempilhar());
    printf("Desempilhar: %d\n", desempilhar());

    mostrarPilha();

    empilhar(50);

    printf("Topo atual: %d\n", consultarTopo());

    mostrarPilha();
}