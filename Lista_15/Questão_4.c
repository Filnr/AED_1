#include <stdio.h>

int menu()
{
    printf("Menu de opçãoes desse programa\n\n");
    printf("1. Algoritmo iterativo\n2. Algoritmo recursivo");
    printf("\nQual estilo de algoritimo deseja[1/2]: ");
    int op; scanf("%d", &op);
    return op;
}

int ler_numero()
{
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);
    return n;
}

void iterativo(int n, int n1, int n2)
{
    printf("%d, %d, ", n1, n2);
    for(int i = 0; i < n; i++)
    {
        int resultado = n1 + n2;
        printf("%d, ", resultado);
        n1 = n2;
        n2 = resultado;
    }
}

void recursivo(int n, int num1, int num2)
{
    if(n > 0)
    {
        int resultado = num1 + num2;
        printf("%d, ", resultado);
        recursivo(n - 1, num2, resultado);
    }
}

int main(void)
{
    int num1 = 1, num2 = 1;
    int op = menu();
    int n = ler_numero();
    switch (op)
    {
    case 1:
        iterativo(n - 2, num1, num2);
        break;
    case 2:
       printf("%d, %d, ", num1, num2);
        recursivo(n - 2, num1, num2);
        break;   
    default:
        break;
    }

}