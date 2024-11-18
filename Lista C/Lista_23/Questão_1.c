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

void trocar_numero(int numeros[], int tamanho)
{
    int aux = numeros[0];
    numeros[0] = numeros[tamanho-1];
    numeros[tamanho-1] = aux;
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
    printf("Antes da troca: ");
    imprimir_array(numeros, n);
    trocar_numero(numeros, n);
    printf("Depois da troca: ");
    imprimir_array(numeros, n);
    return 0;
}