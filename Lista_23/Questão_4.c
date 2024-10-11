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

float menor(float valor[], int *location)
{
    float menor = valor[0];
    for(int i = 1; i < MAX; i++)
    {
        if(menor > valor[i])
        {
            menor = valor[i];
            *location = i;
        }
    }
    return menor;
}

void ordenador(float valor[])
{
    int pos = 0;
    float aux;
    float maior_vetor = menor(valor, &pos);
    printf("->%d e %d\n", pos, MAX);
    if(pos != 0)
    {
        aux = valor[0];
        valor[0] = valor[pos];
        valor[pos] = aux;
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