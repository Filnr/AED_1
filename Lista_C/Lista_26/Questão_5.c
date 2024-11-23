#include <stdio.h>
#include <stdbool.h>

const int MAX_LIN = 2;
const int MAX_COL = 4;

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

void copiaMatriz(float M1[][MAX_COL], float M2[][MAX_COL])
{
    for(int i = 0; i < MAX_LIN; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            M2[i][j] = M1[i][j];
        }
    }
}

void imprimeMatriz(float matriz[][MAX_COL])
{
    for(int i = 0; i < MAX_LIN; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            printf("%.1f, ", matriz[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{
    float M1[MAX_LIN][MAX_COL];
    printf("Escreva o numeros da matriz\n");
    leMatriz(M1);
    float M2[MAX_LIN][MAX_COL];
    copiaMatriz(M1, M2);
    printf("\nPrimeira matriz:\n");
    imprimeMatriz(M1);
    printf("\nSegunda matriz:\n ");
    imprimeMatriz(M2);
    
    return 0;
}