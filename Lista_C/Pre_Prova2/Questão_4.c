#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int lerNumero()
{
    int n;
    printf("Digite um numero[C/L]: ");
    scanf("%d", &n);
    return n - 1;
}

bool calculaMaior(float matriz[][MAX], int linha, int coluna)
{
    bool linhaMaior;
    float maiorLin = matriz[linha][0], maiorCol = matriz[0][coluna];
    for(int i = 1; i < MAX; i++)
    {
        if(maiorLin < matriz[linha][i]){
            maiorLin = matriz[linha][i];
        }
        if(maiorCol < matriz[i][coluna]){
            maiorCol = matriz[i][coluna];
        }
    }
    linhaMaior = maiorLin >= maiorCol;
    return linhaMaior;
}

int main(void)
{
    float matriz[MAX][MAX] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}};
    int linha = lerNumero();
    int coluna = lerNumero();
    if(calculaMaior(matriz, linha, coluna)) printf("Linha e maior\n");
    else printf("Coluna e maior\n");
}

