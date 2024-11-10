#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50
int TAM = 4;

float ler_numero()
{
    float n;  // Alteração para float, pois estamos lendo um número de ponto flutuante
    printf("Digite um numero: ");
    scanf("%f", &n);
    return n;
}

bool insercaoIt(float vetor[], float x)
{
    bool temEspaco = false;
    if (TAM < MAX)
    {
        TAM++;
        for (int i = TAM - 1; i > 0; i--)  // Ajuste para deslocar os elementos para frente
        {
            vetor[i] = vetor[i - 1];
        }
        vetor[0] = x;  // Insere o elemento na primeira posição
        temEspaco = true;
    }
    return temEspaco;
}

void escreveVetor(float vetor[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%.0f ", vetor[i]);
    }
    printf("\n");  // Adicionado para melhorar a visualização
}

int insercaoRec(float vetor[], float x, int i)
{
    int funciona = 1;
    if (TAM < MAX)
    {
        if (i == TAM)  // Caso base
        {
            vetor[i] = x;
            TAM++;
        }
        else  // Passo recursivo para deslocar os elementos
        {
            vetor[TAM] = vetor[TAM - 1];
            insercaoRec(vetor, x, i + 1);
        }
    }
    else
    {
        funciona = 0;
    }
    return funciona;
}

bool chamaRec(float vetor[], float x)
{
    bool funciona = true;
    if (insercaoRec(vetor, x, 0) == 0)
    {
        funciona = false;
    }
    return funciona;
}

int main()
{
    float n = ler_numero();
    float vetor[MAX] = {1, 2, 3, 4};  // Adicionado elementos iniciais para teste
    if (insercaoIt(vetor, n)) printf("\nInserção Iterativa: Funcionou\n");
    else printf("Inserção Iterativa: Não funcionou");

    //if (chamaRec(vetor, n)) printf("\nInserção Recursiva: Funcionou\n");
    //else printf("Inserção Recursiva: Não funcionou");

    escreveVetor(vetor);
    return 0;
}
