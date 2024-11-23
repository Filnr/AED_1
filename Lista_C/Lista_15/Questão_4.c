#include <stdio.h>

int menu()
{
    printf("Menu de opçãoes desse programa\n\n");
    printf("1. Algoritmo iterativo\n2. Algoritmo recursivo\n3. recursivo1.1");
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

int fibonacci(int k)
{
    int fib = 0;
    if(k > 0)
    {
        if(k == 1 || k == 2) fib = 1; //caso base
        else fib = fibonacci(k - 1) + fibonacci(k - 2);
    }
    return fib;
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
        if(n < 0) printf("0");
        else if(n == 1) printf("1");
        else if(n == 2) printf("1, 1");
        else 
        {
            printf("1, 1, ");
            recursivo(n - 2, num1, num2);
        }
        break;
    case 3:
           printf("%d", fibonacci(n));
           break;
    default:
        break;
    }

}