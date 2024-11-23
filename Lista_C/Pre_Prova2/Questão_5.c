#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int n;
}Num;

void lerNumero(Num *n)
{
    printf("Digite um numero: ");
    scanf("%d", &n->n);
}

void dobraValor(Num *n)
{
    n->n *= 2;
}

int main(void)
{
    Num *numero = (Num *)malloc(sizeof(Num));
    lerNumero(numero);
    dobraValor(numero);
    printf("%d", numero->n);
    free(numero);
}