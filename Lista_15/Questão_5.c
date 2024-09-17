#include <stdio.h>

float A(int m, int n)
{   
    float resultado;
    if(m == 0) 
    {
        resultado = n + 1;
    }
    if(m > 0 && n == 0) 
    {
        resultado = A(m-1, 1);
    }
    if(m > 0 && n > 0) 
    {
        resultado = A(m-1, A(m, n-1));
    }
    return resultado;
}

int ler_numero()
{
    int n; 
    do
    {
        printf("Digite um valor inteiro e positivo: ");
        scanf("%d", &n);
    } while (n < 0);
    return n;
}

int main(void)
{
    int m = ler_numero();
    int n = ler_numero();
    printf("%.1f", A(m, n));
}