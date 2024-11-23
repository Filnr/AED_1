#include <stdio.h>


int iterativo(int vetor[][5], int coluna, int linha)
{
    int soma = 0;
    for(int i = 0; i < coluna; i++)
    {
        for(int j = 0; j < linha; j++)
        {
            soma += vetor[i][j];
        }
    }
    return soma;
}

int main(void)
{
    int vetor[2][5] = {{10, 20, 30, 40, 50}, {60, 70, 80, 90, 100}};
    printf("Soma dos numeros do vetor por iterativo: %d\n", iterativo(vetor, 2, 5));
}