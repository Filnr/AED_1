#include <stdio.h>
#define TAM 5

void ler_numero(float vetor[])
{
    for(int i = 0; i < TAM; i++)
    {
        printf("Digite o %d numero: ", i+1);
        scanf("%f", &vetor[i]);
    }
}

void inverteVetorIt(float vetor[])
{
    float aux;
    for(int i = 0; i < TAM / 2; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[TAM - i - 1];
        vetor[TAM - i - 1] = aux;
    }
}

void inverteVetorR(float vetor[])
{
    inverteVetorRec(vetor[], TAM);
}

void inverteVetorRec(float vetor[], int posicao)
{
    if(posicao == 1) vetor[posicao] = vetor[TAM - 1]
    else if(posicao > 1)
    {
        vetor[posicao] = vetor[]
    }
}

void imprimeVetor(float vetor[])
{
    for(int i = 0; i < TAM; i++)
    {
        printf("%.1f, ", vetor[i]);
    }
    printf("\n");
}

int main(void)
{
    float vetor[TAM];
    printf("Inversor de vetor\n\n\n");
    ler_numero(vetor);
    printf("Vetor Inalterado: ");
    imprimeVetor(vetor);
    inverteVetorRec(vetor);
    printf("Vetor invertido por iteração: ");
    imprimeVetor(vetor);
}