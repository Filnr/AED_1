#include <stdio.h>
#include <stdbool.h>
#define MAX_COL 6
#define MAX_LIN 6

float divideMedia(float media, int contador)
{
    return media/contador;
}

float calculaMedia(float matriz[][MAX_COL], int linha, int coluna)
{
    float media = 0;
    int contador = 0;
    for(int i = linha - 1; i <= linha + 1; i++)
    {
        for(int j = coluna - 1; j <= coluna + 1; j++)
        {
            if(i >= 0 && j >= 0 && i < MAX_LIN && j < MAX_COL){
                media += matriz[i][j];
                contador++;
            }
        }
    }
    media = divideMedia(media, contador);
    return media;
}

void resultado(float media)
{
    printf("A media dos numeros vizinhos: %.1f", media);
}

int ler_numero(char* msg)
{
    int n;
    printf("Digite qual %s deseja ler[1 a 6]: ", msg);
    scanf("%d", &n);
    return n;
}

void ler_alvo(int *linha, int *coluna)
{
    *linha = ler_numero("linha") - 1;
    *coluna = ler_numero("coluna") - 1;
}

int main(void)
{
    float matriz[MAX_LIN][MAX_COL] = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18},
    {19, 20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36}};
    int linha, coluna;
    ler_alvo(&linha, &coluna);
    resultado(calculaMedia(matriz, linha, coluna));
}