#ifndef HOSPITAL_H
#define HOSPITAL_H  

#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    char nome[50];
    int idade;
    int gravidade;
    int tipo;

} Pacientes;

extern Pacientes pacientes[100];
extern int total;

extern Pacientes emergencia[100];
extern int topoEmergencia;

extern Pacientes consulta[100];
extern int frenteConsulta;
extern int trasConsulta;

extern Pacientes exame[8];
extern int frenteExame;
extern int trasExame;
extern int totalExame;

void cadastroPaciente();
void mostrarPaciente();
void relatorios();

void empilharEmergencia(Pacientes p);
void atenderEmergencia();

void enfileirarConsulta(Pacientes p);
void atenderConsulta();

void enfileirarExame(Pacientes p);
void atenderExame();

void transferirConsultaEmergencia();
/* void transferirEmergenciaConsulta();
void transferirConsultaExame();
void transferirExameConsulta();
void transferirExameEmergencia();
 */

#endif
