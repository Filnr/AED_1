#include <stdio.h>


int iterativo(int vetor[][5], int coluna, int linha)
{
    int soma = 0;
    for(int i = 0; i < linha; i++)
    {
        soma += vetor[coluna - 1][i];
    }
    return soma;
}

int main(void)
{
    int vetor[3][5] = {{10, 20, 30, 40, 50}, {60, 70, 80, 90, 100}, {50, 10, 30, 55, 90}};
    int x;
    printf("Qual linha deseja somar: ");
    scanf("%d", &x);
    printf("Soma dos numeros do vetor por iterativo: %d\n", iterativo(vetor, x, 5));
}