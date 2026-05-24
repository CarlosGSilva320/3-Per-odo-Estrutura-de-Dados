#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
// Estrutura da fila de prioridade
typedef struct {
    int valor;
    int prioridade;
} Elemento;
 
Elemento fila[MAX];
int tamanho = 0;