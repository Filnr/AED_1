#include <stdio.h>
#include <stdbool.h>

int ler_numero()
{
    int n;
    printf("Digite quantos numeros deseja digitar: ");
    scanf("%d", &n);
    return n;
}

int ler_troca(char* msg, int tamanho)
{
    int n;
    bool invalido;
    do
    {
        printf("Digite  a posicao do %s numero que deseja trocar:", msg);
        scanf("%d", &n);
        invalido = n < 1 || n > tamanho;
        if(invalido) printf("Digite um numero valido\n");
    } while (invalido);
    return n-1;
}

void ler_numeros(int numeros[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        printf("Digite o %d.o numero: ", i+1);
        scanf("%d", &numeros[i]);
    }
}

void trocar_numero(int numeros[], int tamanho, int troca1, int troca2)
{
    int aux = numeros[troca1];
    numeros[troca1] = numeros[troca2];
    numeros[troca2] = aux;
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
    int troca1 = ler_troca("primeiro", n);
    int troca2 = ler_troca("segundo", n);
    printf("Antes da troca: ");
    imprimir_array(numeros, n);
    trocar_numero(numeros, n, troca1, troca2);
    printf("Depois da troca: ");
    imprimir_array(numeros, n);
    return 0;
}