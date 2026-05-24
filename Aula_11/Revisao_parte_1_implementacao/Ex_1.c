#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Max 100

typedef struct {
    char nome[50];
    int idade;
} Cadastro;

Cadastro cadastro[Max];
int frenteCadastro = 0;
int trascadastro = -1;
int tamanho = 0;

typedef struct {
    char nome[50];
    char especialidade[50];
} Historico;

Historico historico[Max];
int topoHistorico = -1;

typedef struct Paciente {
    char nome[50];
    char cpf[20];
    char telefone[20];
    struct Paciente *prox;
} Paciente;

Paciente *inicio = NULL;

/*cadastrar pacientes*/
void cadastrarPacientes(char nome[], char cpf[], char telefone[]) {
    Paciente *novo = (Paciente*) malloc(sizeof(Paciente));

    if(novo == NULL) {
        printf("Erro de memoria!");
        return;
    }
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    strcpy(novo->telefone, telefone);
    
    novo-> prox = NULL;

    if(inicio == NULL) {
        inicio = novo;
    }
        else {
            Paciente *atual = inicio;
            while(atual->prox != NULL) {
                atual = atual->prox;
            }
            atual->prox = novo;
        }
        printf("Paciente: %s cadastrado com sucesso!\n", nome);
}

void listaPaciente() {
    if(inicio == NULL) {
        printf("Lista Vazia!\n");
        return;
    }

    Paciente *atual = inicio;

    while(atual != NULL) {

        printf("\nNome: %s\n", atual->nome);
        printf("CPF: %s\n", atual->cpf);
        printf("Tel: %s\n", atual->telefone);
        atual = atual->prox;
    }
}

void buscarPaciente(char nome[]) {
    if(inicio == NULL) {
        printf("Lista Vazia!\n");
        return;
    }
    Paciente *atual = inicio;
    while(atual != NULL) {
        if(strcmp(atual->nome, nome) == 0) {
            printf("\n=== Paciente encontrado ===\n");
            printf("Nome: %s\n", atual->nome);
            printf("CPF: %s\n", atual->cpf);
            printf("Tel: %s\n", atual->telefone);
            return;
        }
        atual = atual->prox;
    }
}
void removerPaciente(char nome[]) {

    if(inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Paciente *atual = inicio;
    Paciente *anterior = NULL;

    while(atual != NULL &&
          strcmp(atual->nome, nome) != 0) {

        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) {

        printf("\nPaciente nao encontrado!\n");
        return;
    }

    if(anterior == NULL) {

        inicio = atual->prox;
    }
    else {

        anterior->prox = atual->prox;
    }

    free(atual);

    printf("\nPaciente: %s removido!\n", nome);
}

/*emplihar*/
void registrarAtendimento(char nome[], char especialidade[]) {
    if(topoHistorico == Max - 1) {
        printf("Registro cheio!");
        return;
    }
    topoHistorico++;
    strcpy(historico[topoHistorico].nome, nome);
    strcpy(historico[topoHistorico].especialidade, especialidade);
    printf("Registrado -> Nome: %s | Especialidade: %s\n", nome, especialidade);
    return;
}

/*desempilhar*/
Historico desfazerUltimoRegistro() {
    
    Historico vazio = {"", ""};
    if(topoHistorico == -1) {
        printf("Registro vazio");
        return vazio;
    }

    Historico paciente = historico[topoHistorico];
    topoHistorico--;
    return paciente;
}

/*exibir historico*/
void exibirHistorico() {
    if(topoHistorico == -1) {
        printf("Registro vazio!");
        return;
    }
    printf("\n=== Exibir historico ===\n");
    for(int i = topoHistorico; i >= 0; i--) {
        printf("Nome: %s | Especialidade: %s\n", historico[i].nome, historico[i].especialidade);
        
    }
}


/*enqueue*/
void cadastrarFila(char nome[], int idade) {
    if(tamanho == Max) {
        printf("Fila cheia!");
        return;
    }    
    
    trascadastro = (trascadastro + 1) % Max;
    tamanho++;

    strcpy(cadastro[trascadastro].nome, nome);
    cadastro[trascadastro].idade = idade;
    printf("Cadastrado - > Nome: %s | Idade: %d | Fila: %d\n", nome, idade, trascadastro + 1);
    return;
}

/*dequeue*/
Cadastro chamarPaciente() {
    
    Cadastro vazio = {"",0};
    if(tamanho == 0) {
        printf("Fila vazia!");
        return vazio;
    }

    Cadastro paciente = cadastro[frenteCadastro];   

    frenteCadastro = (frenteCadastro + 1) % Max;
    tamanho--;
    return paciente;
}

/*Fila espera*/
void filaEspera() {
    if(tamanho == 0) {
        printf("Fila vazia!");
        return;
    }

    printf("\n=== Fila de espera ===\n");
    int i = frenteCadastro;
    for(int count = 0; count < tamanho; count++) {
        printf("Fila: %d | Nome: %s\n", count + 1, cadastro[i].nome);
        i = (i + 1) % Max;

    }
}

int main() {
/*     cadastrarFila("Joao", 25);
    cadastrarFila("Maria", 40);
    cadastrarFila("Carlos", 31);
    cadastrarFila("Ana", 28);

    printf("Atendendo: %s\n", chamarPaciente().nome);
    printf("Atendendo: %s\n", chamarPaciente().nome);

    filaEspera(); */
   /*  registrarAtendimento("carlos", "Dentista");
    registrarAtendimento("joao", "Clinico");
    registrarAtendimento("David", "Cardiologista");

    exibirHistorico();

    printf("\nDesfazendo ultimo registro -> nome: %s", desfazerUltimoRegistro().nome );
    printf("\nDesfazendo ultimo registro -> nome: %s\n", desfazerUltimoRegistro().nome );

    exibirHistorico(); */
    cadastrarPacientes("carlos", "12345678909", "(22)9999-9999");
    cadastrarPacientes("Joao", "12345678909", "(22)9999-9999");
    cadastrarPacientes("Ze", "12345678909", "(22)9999-9999");

    listaPaciente();

    buscarPaciente("carlos");

    removerPaciente("Ze");

    return 0;
}

/*
#1. Por que fila é ideal para recepção?
Isso representa exatamente uma recepção de clínica, onde os pacientes são atendidos por ordem de chegada.

#2. Por que pilha serve para desfazer ações?
Isso é ideal para desfazer ações porque normalmente queremos cancelar a ação mais recente.

#3. Por que lista encadeada é melhor que vetor para cadastros dinâmicos?
A lista encadeada é melhor porque ela cresce dinamicamente na memória. 
No vetor, o tamanho é fixo, então existe limite de cadastros.
Além disso, remover elementos do meio do vetor pode exigir deslocamento dos outros elementos.
Já na lista encadeada, cada paciente aponta para o proximo.
Isso permite:
inserir pacientes facilmente, remover pacientes facilmente e crescer sem tamanho fixo.
*/