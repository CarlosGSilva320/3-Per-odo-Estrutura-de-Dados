//9. Crie um programa que utilize uma struct para armazenar nome e idade de uma pessoa.

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p1;

    printf("Digite o nome: ");
    scanf("%s", p1.nome);

    printf("Digite a idade: ");
    scanf("%d", &p1.idade);

    printf("--Cadastro--\n");
    printf("Nome: %s\nIdade: %d", p1.nome, p1.idade);
    return 0;

}