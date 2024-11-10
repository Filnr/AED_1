#include <stdio.h>

int ler_numero()
{
    int n;
    printf("Digite quantos numeros deseja digitar: ");
    scanf("%d", &n);
    return n;
}

void ler_numeros(int numeros[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        printf("Digite o %d.o numero: ", i+1);
        scanf("%d", &numeros[i]);
    }
}

void ordenador(int numeros[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < tamanho - 1 - i; j++)
        {
            if(numeros[j] > numeros[j+1])
            {
                int aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
}

void imprimir_array(int numeros[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

int main(void)
{
    int n = ler_numero();
    int numeros[n];
    ler_numeros(numeros, n);
    printf("Antes de ordenar: ");
    imprimir_array(numeros, n);
    ordenador(numeros, n);
    printf("Depois de ordenar: ");
    imprimir_array(numeros, n);
    return 0;
}