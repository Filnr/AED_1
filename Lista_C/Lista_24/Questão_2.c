#include <stdio.h>
#define max 5

void ler_numero(int n[])
{
    int numero;
    for(int i = 0; i < max; i++)
    {   
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &numero);
        n[i] = numero;
    }
}

void iterativo(int n[])
{
    int soma = 0;
    for(int i = 0; i < max; i++)
    {
        soma += n[i];
    }
    printf("Soma iterativo: %d\n", soma);
}

int recursivo(int n[], int posicao)
{
    int soma = 0;
    if(posicao >= 0)
    {
        soma = n[posicao] + recursivo(n, posicao - 1);
    }
    return soma;
}

int main(void)
{
    int n[5];
    ler_numero(n);
    iterativo(n);
    printf("Soma recursiva: %d\n", recursivo(n, max - 1));
}