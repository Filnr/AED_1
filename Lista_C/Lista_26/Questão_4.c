#include <stdio.h>
#define MAX_LIN 3
#define MAX_COL 3

void leMatriz(float matriz[][MAX_COL])
{
    int posicao = 1;
    float n;
    for(int i = 0; i < MAX_LIN; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            printf("Digite o %d.o numero da matriz: ", posicao);
            scanf("%f", &matriz[i][j]);
            posicao++;
        }
    }
}

float acima_diagonal(float matriz[][MAX_COL])
{
    float maior = matriz[0][2];
    for(int i = 0; i < MAX_LIN; i++)
    {
        for(int j = i+1; j < MAX_COL; j++)
        {
            if(maior < matriz[i][j]) maior = matriz[i][j];
        }
    }
    return maior;
}

float abaixo_diagonal(float matriz[][MAX_COL])
{
    float maior = matriz[1][0];
    for(int i = 1; i < MAX_LIN; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(maior < matriz[i][j]) maior = matriz[i][j];
        }
    }
    return maior;
}

float diferenca_valores(float matriz[][MAX_COL])
{
    return abaixo_diagonal(matriz) - acima_diagonal(matriz);
}

void resultado(float diferenca)
{
    printf("\nA diferenca entre os numeros acima e abaixo da diagonal vale: %.1f", diferenca);
}
int main(void)
{
    float matriz[MAX_LIN][MAX_COL];
    leMatriz(matriz);
    resultado(diferenca_valores(matriz));
    return 0;
}