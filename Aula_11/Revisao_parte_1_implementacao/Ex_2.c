#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    int ticket;
    char descricao[100];
} Chamado;

Chamado chamado[MAX];
int frenteChamado = 0;
int trasChamado = -1;
int proxTicket = 1;
int tamanho = 0;

typedef struct {
    char alteracao[50];
} Logs;

Logs logs[MAX];
int topoLogs = -1;

typedef struct Equipamentos {
    char patrimonio[50];
    char tipo[50];
    char localizacao[50];
   struct Equipamentos *prox;
} Equipamentos;

Equipamentos *inicio = NULL;

void adicionarEquipamneto(char patrimonio[], char tipo[], char localizacao[]) {
    Equipamentos *novo = (Equipamentos*) malloc(sizeof(Equipamentos));

    if(novo == NULL) {
        printf("Erro de memoria!");
        return;
    }

    strcpy(novo->patrimonio, patrimonio);
    strcpy(novo->tipo, tipo);
    strcpy(novo->localizacao, localizacao);
    novo->prox = NULL;

    if(inicio == NULL) {
        inicio = novo;
    } 
        else {
            Equipamentos *atual = inicio;
                while(atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novo;
        }
        printf("Equipamentos cadastrados com sucesso!\n");  
}

void buscarEquipamentos(char patrimonio[]) {
    if (inicio == NULL) {
        printf("Lista vazia!");
        return;
    }
    Equipamentos *atual = inicio;

    while(atual != NULL) {
        if(strcmp(atual->patrimonio, patrimonio) == 0) {
            printf("\n=== Equipamento encontrado ===\n");
            printf("Patrimonio: %s\n", atual->patrimonio);
            printf("Tipo: %s\n", atual->tipo);
            printf("Localizacao: %s", atual->localizacao);
            return;
        }
        atual = atual-> prox;
    }
} 

void listarEquipamentos() {
    if(inicio == NULL) {
        printf("Lista vazia!");
        return;
    }
    Equipamentos *atual = inicio;
    printf("\n=== Lista de Equipamentos ===\n");
    while(atual != NULL) {
        printf("\nPatrimonio: %s\n", atual->patrimonio);
        printf("Tipo: %s\n", atual->tipo);
        printf("Localizacao: %s\n", atual->localizacao);
        atual = atual-> prox;
    }
}

void removerEquipamento(char patrimonio[]) {
    if(inicio == NULL) {
        printf("Lista vazia!");
        return;
    }

    Equipamentos *atual = inicio;
    Equipamentos *anterior = NULL;

    while(atual != NULL && 
        strcmp(atual->patrimonio, patrimonio) != 0) {
            anterior = atual;
            atual = atual->prox;
        }

        if(atual == NULL) {
            printf("\nEquipamento não encontrado\n");
            return;
        }
        
        if(anterior == NULL) {
            inicio = atual->prox;
        }
            else {
                anterior->prox = atual->prox;
            }
        free(atual);

        printf("\nEquipamento: %s removido\n", patrimonio);
}

void registrarAcao(char alteraçao[]) {
    if(topoLogs == MAX -1) {
        printf("Pilha de registors cheia!");
    }
    
    topoLogs++;
    strcpy(logs[topoLogs].alteracao, alteraçao);    
    printf("Alteracao: %s -> registrada com sucesso....\n", alteraçao);
    return;
} 

Logs desfazerAcao() {
    Logs vazio = {""};
    if(topoLogs == -1) {
        printf("Registro vazio!\n");
        return vazio;
    }

    Logs l = logs[topoLogs];
    topoLogs--;
    return l;
}

void mostrarHistorico() {
    if(topoLogs == -1) {
        printf("Registro vazio!");
        return;
    }
    printf("\n=== Historico de Logs ===\n");
    for(int i = topoLogs; i >= 0; i--) {
        printf("Posicao: %d | Alteracao: %s\n", i, logs[i].alteracao);
    }
    return;
}


void abrirChamado(char descricao[] ) {
    if(tamanho == MAX) {
        printf("Chamados lotados!\n");
        return;
    }

    trasChamado = (trasChamado + 1) % MAX;
    tamanho++;
    chamado[trasChamado].ticket = proxTicket;
    proxTicket++; 
    strcpy(chamado[trasChamado].descricao, descricao);
    printf("Ticket: %d | Descricao: %s -> gerado com sucesso...\n", proxTicket - 1, descricao);
    return;
}

Chamado atenderChamado() {
    
    Chamado vazio = {0, ""};
    if(tamanho == 0) {
        printf("Sem chamdos na fila!\n");
        return vazio;
    }
    Chamado atual = chamado[frenteChamado];

    frenteChamado = (frenteChamado + 1) % MAX;
    tamanho--;
    return atual;
}

void ListarChamados() {
    if(tamanho == 0) {
        printf("Sem chamdos na fila!\n");
    }
    printf("\n=== Lista de espera de Ticket's ===\n");
    int i = frenteChamado;    
    for(int count = 0; count < tamanho; count++) {
        printf("Fila: %d-> Ticket: %d | Descricao: %s\n", count, chamado[i].ticket, chamado[i].descricao);
        i = (i + 1) % MAX;    
    }
    return;
}




int main() {

/*     abrirChamado("sem internet");
    abrirChamado("sem tinta");
    abrirChamado("internet lenta");
    abrirChamado("impressora ruim");

    ListarChamados();

   Chamado c1 = atenderChamado();
   printf("\nAtendendo-> Ticket: %d | Descricao: %s\n", c1.ticket, c1.descricao);

   Chamado c2 = atenderChamado();
   printf("Atendendo-> Ticket: %d | Descricao: %s\n", c2.ticket, c2.descricao);

   ListarChamados(); */

/*    registrarAcao("reiniciou servidor");
   registrarAcao("alterou IP");
   registrarAcao("reiniciou servidor");

   mostrarHistorico();


   Logs l1 = desfazerAcao();
   printf("\nDesfando ultima acao: %s\n", l1.alteracao);

   mostrarHistorico(); */

   adicionarEquipamneto("Impressora", "eletronico", "escritorio");
   adicionarEquipamneto("PC", "eletronico", "escritorio");
   adicionarEquipamneto("Mesa", "movel", "escritorio");

   buscarEquipamentos("PC");

   listarEquipamentos();

   removerEquipamento("PC");

   listarEquipamentos();
}

