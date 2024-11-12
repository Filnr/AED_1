#include <stdio.h>
#include <stdbool.h>
#define MAX 50
int TAM = 10;

float lerReal(char *msg)
{
    float n;
    printf("Digite %s:", msg);
    scanf("%f", &n);
    return n;
}

int lerInt()
{
    bool erro;
    int n;
    do
    {
        printf("Digite a posicao no vetor: ");
        scanf("%d", &n);
        erro = n < 1 || n > TAM;
        if(erro) printf("Valor invalido\n");
    } while (erro);
    return n - 1;
}

void decideNumero(float *numero, int *posicao)
{
    *numero = lerReal("um valor");
    *posicao = lerInt();
}

void shift1(float vetor[], float numero, int posicao)
{
    for (int i = TAM; i > posicao; i--)
    {
        vetor[i] = vetor[i - 1];
    }
    vetor[posicao] = numero;
    TAM++;
}

void imprimeVetor(float vetor[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%.1f, ", vetor[i]);
    }
}

int main(void)
{
    float vetor[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float numero;
    int posicao;
    decideNumero(&numero, &posicao);
    shift1(vetor, numero, posicao);
    imprimeVetor(vetor);
}