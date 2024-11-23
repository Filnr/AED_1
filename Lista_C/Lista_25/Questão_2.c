#include <stdio.h>


int iterativo(int vetor[], int tam)
{
    int soma = 0;
    for(int i = 0; i < tam; i++)
    {
        soma += vetor[i];
    }
    return soma;
}

int recursivo(int vetor[], int tam)
{
    int soma = 0;
    if(tam == 1) soma = vetor[tam - 1];
    else if(tam > 1)
    {
        soma = vetor[tam - 1] + recursivo(vetor, tam - 1);
    }
    return soma;
}

int main(void)
{
    int vetor[5] = {10, 20, 30, 40, 50};
    printf("Soma dos numeros do vetor por iterativo: %d\n", iterativo(vetor, 5));
    printf("Soma dos numeros do vetor por recursivo: %d\n", recursivo(vetor, 5));
}