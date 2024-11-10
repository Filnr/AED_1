#include <stdio.h>


int iterativo(int vetor[], int tam)
{
    int negativo = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vetor[i] < 0) negativo++;
    }
    return negativo;
}

int recursivo(int vetor[], int tam)
{
    int negativo = 0;
    if(tam == 1)
    {
        if(vetor[tam - 1] < 0) negativo = 1;
    }
    else if(tam > 1)
    {
        if(vetor[tam -1] < 0) negativo = 1;
        negativo += recursivo(vetor, tam -1);
    }
    return negativo;
}

int main(void)
{
    int vetor[5] = {-1, -1, 5, -5, -10};
    printf("Quantidades de numeros negativos por iterativo: %d\n", iterativo(vetor, 5));
    printf("Quantidades de numeros negativos por recursivo: %d\n", recursivo(vetor, 5));
}