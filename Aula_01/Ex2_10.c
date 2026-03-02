//10. Faça um programa que leia os dados de uma struct e mostre na tela.

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa p1;

    printf("Digite o Nome: ");
    scanf("%s", p1.nome);

    printf("Digite a idade: ");
    scanf("%d", &p1.idade);

    printf("Digite a altura: ");
    scanf("%f", &p1.altura);

    printf("--Cadstro--\n");
    printf("nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Altura: %.2f\n", p1.altura);

    return 0;

}
