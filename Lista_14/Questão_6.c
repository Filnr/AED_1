#include <stdio.h>

int potencia(int base, int expoente, int *pot)
{
    *pot *= base;
    if(expoente > 1) potencia(base, expoente - 1, pot);
    return *pot;
}


void resultado_final(int base, int exp, int resultado)
{
    printf("O a pontencia de %d elevado a %d vale: %d", base, exp, resultado);
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
    int base = ler_numero("a base");
    int exp = ler_numero("o expoente");
    int pot = 1;
    int resultado = potencia(base, exp, &pot);
    resultado_final(base, exp, resultado);
}