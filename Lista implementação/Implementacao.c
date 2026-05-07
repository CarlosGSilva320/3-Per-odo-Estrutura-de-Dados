#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome[50];
    int idade;
    int gravidade;
    int tipo;

} Pacientes;

Pacientes pacientes[100];
int total = 0;

void cadastroPaciente() {


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
        printf("Paciente direcionado para Emegencia!\n");
    }
    else
    {

        printf(
            "Tipo:\n"
            "1 - Emergencia.\n"
            "2 - Consulta.\n"
            "3 - Exame.\n");
        scanf("%d", &pacientes[total].tipo);
    }

    printf("Paciente cadastrado com sucesso!\n");
    total++;

    printf("\nTotal de pacientes cadastrados: %d", total);
    return;
}

int main(){

    int opcao;

    do {
        printf("\n==== HOSPITAL ====\n"
               "1 - Cadastrar paciente.\n"
               "2 - Atender pacientes\n"
               "3 - Mostrar pacientes\n"
               "4 - Transferir pacientes\n"
               "5 - Relatorios\n"
               "0 - Sair.\n"
               "Opcao: ");

        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastroPaciente();

        } else if (opcao == 2) {
            /* atenderPaciente(); */

        } else if (opcao == 3) {
            /* mostrarPaciente();
 */
        } else if (opcao == 4) {
            /* transferirPaciente(); */

        } else if (opcao == 5) {
            /* relatorios(); */

        } else if (opcao == 0) {
            printf("\nSaindo do programa... Obrigado!");

        } else {
            printf("Opcao invalida!");
        }
    } while ( opcao != 0 );

        return 0;
}
