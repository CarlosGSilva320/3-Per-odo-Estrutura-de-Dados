#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[20];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoa1;
    strcpy(pessoa1.nome, "Carlos");
    pessoa1.idade = 44;
    pessoa1.altura = 1.81;

    printf("Idade: %d\n", pessoa1.idade);

    //Ponteiro para struct
    struct Pessoa *ptr = &pessoa1;

    //Maneira facil de acessar struct com ponteiro
    printf("A altura: %.2f\n", ptr->altura);

    //Maneira difícil de acessar struct em ponteiros
    printf("A idade: %d\n", (*ptr).idade);

    return 0;
}