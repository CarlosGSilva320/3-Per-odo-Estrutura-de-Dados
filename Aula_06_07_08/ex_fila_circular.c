#include <stdio.h>
#define MAX_SIZE 5

int fila[MAX_SIZE];
int frente = 0;
int tras = 0;
int tamanho = 0;

int estaVazia()
{
    return tamanho == 0;
}

int estaCheia()
{
    return tamanho == MAX_SIZE;
}

void enfileirar(int valor)
{
    if (estaCheia())
    {
        printf("Erro: Fila cheia!");
        return;
    }
    fila[tras] = valor;
    tras = (tras + 1) % MAX_SIZE;
    tamanho++;

    printf("Enfileirado: %d\n", valor);
}

int desenfileirar()
{
    if (estaVazia())
    {
        printf("Erro: Fila esta vazia");
        return -1;
    }

    int valor = fila[frente];
    frente = (frente + 1) % MAX_SIZE;
    tamanho--;
    return valor;
}

void exibirFila()
{
    if (estaVazia())
    {
        printf("Erro: Fila vazia!");
        return;
    }

    int i = frente;
    for (int count = 0; count < tamanho; count++)
    {
        printf("Fila[%d]: %d\n", count, fila[i]);
        i = (i + 1) % MAX_SIZE;
    }
}

int main()
{
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);
    enfileirar(40);
    enfileirar(50);

    exibirFila();

    printf("Desenfileirar: %d\n", desenfileirar());
    printf("Desenfileirar: %d\n", desenfileirar());

    enfileirar(60);
    enfileirar(70);

    exibirFila();

    return 0;
}