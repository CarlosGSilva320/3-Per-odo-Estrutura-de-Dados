//Fila de de prioridade com ponteiro
#include <stdio.h>
#include <stdlib.h>
 
// Estrutura do nó da fila.  nó [valor/prioridade]->(prox)
typedef struct No {
    int valor;
    int prioridade;
    struct No *prox;
} No;
 
// Ponteiro para o início da fila
No *inicio = NULL;
 
// Verifica se a fila está vazia
int filaVazia() {
    return inicio == NULL;
}
 
// Inserir elemento na fila de prioridade
void enqueue(int valor, int prioridade) {
 
    // Aloca memória para o novo nó
    No *novo = (No *) malloc(sizeof(No));
 
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
 
    //obs -> é um acesso
    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->prox = NULL;
 
    // Caso a fila esteja vazia
    if (filaVazia()) {
        inicio = novo;
    }
    else {
 
        // Inserção no início se tiver maior prioridade
        if (prioridade > inicio->prioridade) {
            novo->prox = inicio;
            inicio = novo;
        }
        else {
 
            // Percorre a fila
            No *atual = inicio;
 
            while (atual->prox != NULL &&
                   atual->prox->prioridade >= prioridade) {
 
                atual = atual->prox;
            }
 
            // Insere o nó na posição correta
            novo->prox = atual->prox;
            atual->prox = novo;
        }
    }
 
    printf("Elemento %d inserido com prioridade %d\n",
           valor, prioridade);
}
 
// Remove elemento de maior prioridade
void dequeue() {
 
    if (filaVazia()) {
        printf("Fila vazia!\n");
        return;
    }
 
    No *temp = inicio;
 
    printf("Removido: %d | Prioridade: %d\n",
           temp->valor,
           temp->prioridade);
 
    inicio = inicio->prox;
 
    free(temp);
}
 
// Exibe a fila
void exibirFila() {
 
    if (filaVazia()) {
        printf("Fila vazia!\n");
        return;
    }
 
    No *atual = inicio;
 
    printf("\nFila de Prioridade:\n");
 
    while (atual != NULL) {
 
        printf("Valor: %d | Prioridade: %d\n",
               atual->valor,
               atual->prioridade);
 
        atual = atual->prox;
    }
}
 
// Programa principal
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