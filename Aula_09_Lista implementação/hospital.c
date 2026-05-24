#include "hospital.h"
#include <string.h>


Pacientes pacientes[100];
int total = 0;

Pacientes emergencia[100];
int topoEmergencia = -1;

Pacientes consulta[100];
int frenteConsulta = 0;
int trasConsulta = -1;

Pacientes exame[8];
int frenteExame = 0;
int trasExame = -1;
int totalExame = 0;


void relatorios() {
    int totalEmergencia = topoEmergencia + 1;
    int totalConsulta = 0;

    if (trasConsulta >= frenteConsulta) {

        totalConsulta = trasConsulta - frenteConsulta + 1;
    }

    printf("\n=== Relatorios ===\n");
    printf("Total geral de pacientes: %d\n", total);
    printf("Pacientes na Emergencia: %d\n", totalEmergencia);
    printf("Pacientes na Consulta: %d\n", totalConsulta);
    printf("Pacientes nos Exames: %d\n", totalExame);

}

void enfileirarExame(Pacientes p) {
    if(totalExame == 8) {
        printf("\nFila exames cheia!\n");
        printf("Removendo mais antigo\n");
    

    frenteExame = (frenteExame + 1) % 8;
    totalExame--;
}
    trasExame = (trasExame + 1) % 8;
    exame[trasExame] = p;

    totalExame++;

    printf("Paciente enviado para exames!\n");
}

void atenderExame() {
    if(totalExame == 0) {
        printf("Sem pacientes para exame!\n");
    }
    
    Pacientes p = exame[frenteExame];

    frenteExame = (frenteExame + 1) % 8;

    totalExame--;

    printf("\n=== Paciente atendido ===\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);
}


void enfileirarConsulta(Pacientes p)
{

    if (trasConsulta == 99)
    {
        printf("Fila consulta cheia!\n");
        return;
    }

    trasConsulta++;
    consulta[trasConsulta] = p;
    printf("Paciente enviado para consulta!");
}

void atenderConsulta()
{
    if (frenteConsulta > trasConsulta)
    {
        printf("Sem pacientes esperando consulta!\n");
        return;
    }

    Pacientes p = consulta[frenteConsulta];

    frenteConsulta++;

    printf("\n=== Paciente atendido ===\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);
}

void empilharEmergencia(Pacientes p)
{

    if (topoEmergencia == 99)
    {
        printf("Emergencia cheia!\n");
        return;
    }
    topoEmergencia++;
    emergencia[topoEmergencia] = p;
    printf("Paciente enviado para Emergencia!\n");
}

void atenderEmergencia()
{
    if (topoEmergencia == -1)
    {
        printf("\nSem pacientes na Emergencia!\n");
        return;
    }

    Pacientes p = emergencia[topoEmergencia];

    printf("\n=== Paciente atendido ===\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Gravidade: %d\n", p.gravidade);

    topoEmergencia--;
}

void cadastroPaciente()
{

    printf("\n=== Cadastro ===\n");

    printf("Nome: ");
    scanf("%s", pacientes[total].nome);

    printf("Idade: ");
    scanf("%d", &pacientes[total].idade);

    printf("Gravidade (1 / 5):\n");
    scanf("%d", &pacientes[total].gravidade);

    if (pacientes[total].gravidade >= 4)
    {

        pacientes[total].tipo = 1;
        empilharEmergencia(pacientes[total]);
    }
    else
    {

        printf(
            "Tipo:\n"
            "1 - Emergencia.\n"
            "2 - Consulta.\n"
            "3 - Exame.\n");
        scanf("%d", &pacientes[total].tipo);

        if (pacientes[total].tipo == 1)
        {
            empilharEmergencia(pacientes[total]);
        }
        else if (pacientes[total].tipo == 2)
        {
            enfileirarConsulta(pacientes[total]);

        } else if (pacientes[total].tipo == 3) {
            
            enfileirarExame(pacientes[total]);
        }
    }

    printf("Paciente cadastrado com sucesso!\n");

    total++;

    printf("\nTotal de pacientes cadastrados: %d", total);
}

void mostrarPaciente()
{

    if (total == 0)
    {

        printf("\nNenhum paciente cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE PACIENTES NA EMERGENCIA ===\n");

    for (int i = 0; i < total; i++)
    {
        if (pacientes[i].tipo == 1)
        {
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Idade: %d\n", pacientes[i].idade);
            printf("Gravidade: %d\n", pacientes[i].gravidade);
        }
    }

    printf("\n=== LISTA DE PACIENTES NA CONSULTA ===\n");

    for (int i = 0; i < total; i++)
    {
        if (pacientes[i].tipo == 2)
        {
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Idade: %d\n", pacientes[i].idade);
            printf("Gravidade: %d\n", pacientes[i].gravidade);
        }
    }
    printf("\n=== LISTA DE PACIENTES NA EXAME ===\n");

    for (int i = 0; i < total; i++)
    {
        if (pacientes[i].tipo == 3)
        {
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Idade: %d\n", pacientes[i].idade);
            printf("Gravidade: %d\n", pacientes[i].gravidade);
        }
    }
    return;
}

void transferirConsultaEmergencia() {

    if(frenteConsulta > trasConsulta) {

        printf("Sem pacientes na consulta!");
        return;
    }

    Pacientes p = consulta[frenteConsulta];

    frenteConsulta++;

    p.tipo = 1;

    empilharEmergencia(p);

    for (int i = 0; i < total; i++) {

        if (strcmp(pacientes[i].nome, p.nome) == 0) {

            pacientes[i].tipo = 1;
        }
    }

    printf(
        "Paciente transferido da consulta "
        "para emergencia!\n"
    );
}

