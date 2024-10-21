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

int ler_numero()
{
    int n;
    do
    {
        printf("Digite a linha que deseja comparar[1/2]: ");
        scanf("%d", &n);
    } while (n < 1 || n > 2);

    return n;
}

float maior_numero(float matriz[][MAX_COL], int x)
{
    float maior = matriz[x][0];
    for(int i = 1; i < MAX_COL; i++)
    {
        if(maior < matriz[x][i]) maior = matriz[x][i];
    }
    return maior;
}

int main()
{
    float M1[MAX_LIN][MAX_COL];
    printf("Escreva o numeros da matriz\n");
    leMatriz(M1);
    int linha = ler_numero();
    printf("Maior numero da linha %d: %.1f", linha, maior_numero(M1, linha-1));
    return 0;
}