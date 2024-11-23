#include <stdio.h>

int impressao(int inf, int sup, int *acumulador)
{
    printf("%d ", inf);
    *acumulador += inf;
    if (inf < sup) 
    {
        impressao(inf + 1, sup, acumulador);
    }
    return *acumulador;
}

int ler_numero(char* msg)
{
    int n1;
    printf("Digite o limite %s: ", msg);
    scanf("%d", &n1);
    return n1;
}

void resultado_soma(int x)
{
    printf("\nO resultado da soma dos numeros: %d", x);
}

int main(void)
{
    int limite_inferior = ler_numero("inferior");
    int limite_superior = ler_numero("superior");
    int acumulador = 0; 
    int resultado = impressao(limite_inferior, limite_superior, &acumulador);
    resultado_soma(resultado);
    return 0;
}