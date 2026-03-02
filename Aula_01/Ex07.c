//7. Crie um programa que leia o nome e a idade de uma pessoa e mostre esses dados. 

#include <stdio.h>

int main() {

    char nome[50];
    int idade;

    printf("Digite o seu nome: ");
    fgets(nome, 50, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Nome: %s", nome);
    printf("Idade: %d", idade);

    return 0;
}