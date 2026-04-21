#include <stdio.h>
#include <stdlib.h>

int *pilha;
int topo = -1;

int vazia() {
    return topo == -1;
}

int cheia(int tamanho) {
    return topo == tamanho - 1;
}

void push(int valor, int tamanho) {
    if (cheia(tamanho)) {
        printf("Overflow - Pilha cheia\n");
        return;
    }
    topo++;
    pilha[topo] = valor;
}

int pop() {
    if (vazia()) {
        printf("Underflow - Pilha vazia\n");
        return -1;
    }
    return pilha[topo--];
}

void exibir() {
    if (vazia()) {
        printf("Pilha vazia\n");
        return;
    }

    printf("Pilha: ");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}



int main() {
    int tamanho, valor;

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tamanho);

    pilha = (int*) malloc(tamanho *sizeof(int));

    if (pilha == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }
    printf("Digite %d elementos:\n", tamanho -1);
    for (int i = 0; i< tamanho - 1; i++) {
        scanf("%d", &valor);
        push(valor, tamanho);
    }

    exibir();

    printf("Pilha vazia? %s\n", vazia() ? "sim" : "não");
    printf("Pilha cheia? %s\n", cheia(tamanho)? "sim" : "não");

    printf("Digite um valor para inserir: ");
    scanf("%d", &valor);
    push(valor, tamanho);

    printf("Após inserção: \n");
    exibir();

    printf("Elemento removido: %d", pop());

    printf("Após remoção: \n");
    exibir();

    free(pilha);
    return 0;


}