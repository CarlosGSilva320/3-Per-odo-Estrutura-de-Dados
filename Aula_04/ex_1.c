#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int topo;
    int capacidade;
    int *dados;
} Pilha;

Pilha* criarPilha(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->capacidade = capacidade;
    p->topo = -1;
    p->dados = (int*) malloc(capacidade * sizeof(int));
} 


int main(){
    int tamanho, i, valor;

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tamanho);
}