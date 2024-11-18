#include <stdio.h>

float ler_numero()
{
    float x;
    printf("Digite um numero: ");
    scanf("%f", &x);
    return x;
}

int iterativo(float vetor[], int tam, float x)
{
    int Maior_que_x = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vetor[i] > x) Maior_que_x++;
    }
    return Maior_que_x;
}

int recursivo(float vetor[], int tam, float x)
{
    int Maior_que_x = 0;
    if(tam == 1)
    {
        if(vetor[tam - 1] > x) Maior_que_x = 1;
    }
    else if(tam > 1)
    {
        if(vetor[tam -1] > x) Maior_que_x = 1;
        Maior_que_x += recursivo(vetor, tam -1, x);
    }
    return Maior_que_x;
}

int main(void)
{
    float vetor[5] = {1, 2, 3, 4, 5};
    float x = ler_numero();
    printf("Quantidades de numeros negativos por iterativo: %d\n", iterativo(vetor, 5, x));
    printf("Quantidades de numeros negativos por recursivo: %d\n", recursivo(vetor, 5, x));
}