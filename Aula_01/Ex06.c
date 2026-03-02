//6. Escreva um programa que leia três notas e calcule a média aritmética.

#include <stdio.h>

int main() {

    float n1, n2, n3, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);

    printf("Digite a segunda nota: ");
    scanf("%f", &n2);

    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media = (n1 + n2 + n3) / 3;

    printf("A media e igual a: %.2f", media);

}