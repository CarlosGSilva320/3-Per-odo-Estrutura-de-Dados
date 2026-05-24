#include "hospital.h"

int main()
{

    int opcao;

    do
    {
        printf("\n==== HOSPITAL ====\n"
               "1 - Cadastrar paciente.\n"
               "2 - Atender pacientes\n"
               "3 - Mostrar pacientes\n"
               "4 - Transferir pacientes\n"
               "5 - Relatorios\n"
               "0 - Sair.\n"
               "Opcao: ");

        scanf("%d", &opcao);

        if (opcao == 1)
        {
            cadastroPaciente();
        }
        else if (opcao == 2)
        {

            int atendimento;

            printf("Escolha qual tipo de atendimento:\n");
            printf(
                "1 - Emergencia.\n"
                "2 - Consulta.\n"
                "3 - Exame.\n"
                "Opcao: ");
            scanf("%d", &atendimento);

            if (atendimento == 1)
            {
                printf("Atendendo Emergencia...\n");
                atenderEmergencia();
            }
            else if (atendimento == 2)
            {
                printf("Atendendo consulta...");
                atenderConsulta();
            }
            else if (atendimento == 3)
            {
                printf("Atendendo exames...");
                atenderExame();
            }
            else
            {
                printf("Opcao invalida!");
                return 0;
            }
        }
        else if (opcao == 3)
        {
            mostrarPaciente();
        }
        else if (opcao == 4)
        { 
            transferirConsultaEmergencia();
            
        }
        else if (opcao == 5)
        {
            relatorios();
        }
        else if (opcao == 0)
        {
            printf("\nSaindo do programa... Obrigado!");
        }
        else
        {
            printf("Opcao invalida!");
        }
    } while (opcao != 0);

    return 0;
}
