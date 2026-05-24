//Lista Simplesmente Encadeada
#include <stdio.h>
#include <stdlib.h>
 
// Estrutura do nó
struct No {
        int valor;
        struct No *prox;
        };

 
// Ponteiro para início da lista
struct No *inicio = NULL;
 
// Inserir no início
void inserirInicio(int valor) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
 
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
 
    novo->valor = valor;
    novo->prox = inicio;
    inicio = novo;
}
 
// Inserir no final
void inserirFinal(int valor) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    struct No *atual;
 
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
 
    novo->valor = valor;
    novo->prox = NULL;
 
    if (inicio == NULL) {
        inicio = novo;
        return;
    }
 
    atual = inicio;
 
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
 
    atual->prox = novo;
}
 
// Remover elemento
void remover(int valor) {
    struct No *atual = inicio;
    struct No *anterior = NULL;
 
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        // return;
    }
 
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }
 
    if (atual == NULL) {
        printf("Elemento nao encontrado!\n");
        return;
    }
 
    if (anterior == NULL) {
        inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
 
    free(atual);
}
 
// Exibir lista
void exibirLista() {
    struct No *atual = inicio;
 
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
 
    printf("Lista: ");
 
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
 
    printf("NULL\n");
}
 
// Programa principal
int main() {
    inserirInicio(10);
    inserirInicio(20);
    inserirFinal(30);
    inserirFinal(40);
 
    exibirLista();
 
    remover(20);
 
    exibirLista();
 
    return 0;
}