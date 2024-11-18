#include <stdio.h>

int potencia(int base, int *fatorial)
{
    *fatorial *= base;
    if(base > 1) potencia(base - 1, fatorial);
    return *fatorial;
}


void resultado_final(int base, int fatorial)
{
    printf("O fatorial de %d!: %d", base, fatorial);
}
int ler_numero(char* msg)
{
    int n;
    printf("Digite um numero para %s: ", msg);
    scanf("%d", &n);
    return n;
}
int main(void)
{
    int base = ler_numero("fatoriar");
    int fatorial = 1;
    int resultado = potencia(base, &fatorial);
    resultado_final(base, fatorial);
}