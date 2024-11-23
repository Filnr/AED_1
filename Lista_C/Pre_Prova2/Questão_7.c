#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN 3
#define MAX_COL 3

float ler_numero()
{
    float n;
    printf("Digite um numero: ");
    scanf("%f", &n);
    return n;
}

void analisaDiagonal(float matriz[][MAX_COL])
{
    int iguais = 0;
    for(int i = 0; i  < MAX_LIN; i++)
    {
        for(int j = 0; j < MAX_COL - i -1 ; j++)
        {
            printf("%.0f, ", matriz[i][j]);
        }
    }
}


int main()
{
    float matriz[MAX_LIN][MAX_COL] ={{1,2,3}, {4,5,6}, {7,8,9}};
    analisaDiagonal(matriz);
}