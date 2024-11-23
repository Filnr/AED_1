#include <stdio.h>
#define MAX 5

void ler_vetor(float valor[])
{
    for(int i = 0; i < MAX; i++)
    {
        printf("Digite o %d.o valor: ", i+1);
        scanf("%f", &valor[i]);
    }
}

float maior(float valor[], int *location)
{
    float maior = valor[0];
    for(int i = 1; i < MAX; i++)
    {
        if(maior < valor[i])
        {
            maior = valor[i];
            *location = i;
        }
    }
    return maior;
}

void ordenador(float valor[])
{
    int pos = 0;
    float aux;
    float maior_vetor = maior(valor, &pos);
    printf("->%d e %d\n", pos, MAX);
    if(pos != MAX)
    {
        printf("%d e %d\n", valor[MAX], valor[pos]);
        aux = valor[MAX - 1];
        valor[MAX - 1] = valor[pos];
        valor[pos] = aux;
        printf("%d e %d\n", valor[MAX], valor[pos]);
    }
}

void resultado(float valor[])
{
    for(int i = 0; i < MAX; i++)
    {
        printf("%.2f, ", valor[i]);
    }
    printf("\n");
}

int main(void)
{
    float vetor[MAX];
    ler_vetor(vetor);
    printf("Antes de mudar: ");
    resultado(vetor);
    ordenador(vetor);
    printf("Depois de mudar: ");
    resultado(vetor);
    return 0;
}