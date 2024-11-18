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

bool iguais(float m1[][MAX_COL], float m2[][MAX_COL])
{
    bool iguais = true;
    int i = 0;
    while(i < MAX_LIN && iguais)
    {
        int j = 0;
        while(j < MAX_COL && iguais)
        {
            if(m1[i][j] != m2[i][j]) iguais = false;
            j++;
        }
        i++;
    }
    return iguais;
}

void escreveMatriz(float m[][MAX_COL])
{
    for(int i = 0; i < MAX_LIN; i++)
    {
        for(int j = 0; j < MAX_COL; j++)
        {
            printf("%.1f, ", m[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    float M1[MAX_LIN][MAX_COL];
    printf("Primeira Matriz\n");
    leMatriz(M1);
    float M2[MAX_LIN][MAX_COL];
    printf("\nSegunda Matriz\n");
    leMatriz(M2);
    printf("\n\nEscrevendo a primeira Matriz :\n");
    escreveMatriz(M1);
    printf("\n\nEscrevendo a segunda Matriz :\n");
    escreveMatriz(M2);
    if (iguais(M1, M2))
        printf("\nMatrizes iguais !");
    else
        printf("\nMatrizes diferentes !");
    return 0;
}