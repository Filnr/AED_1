#include <stdio.h>

void apresentacao()
{
    printf("Bem vindo, nesse program irei ordenar em ordem descrescente os numeros digitados\n");
}

float ler_numero(char* msg)
{
    float valor;
    printf("Digite o %s numero: ", msg);
    scanf("%f", &valor);
    return valor;
}

void ordernador(float *a, float *b, float *c)
{
    float aux;
    if(*b > *a)
    {
        aux = *b;
        *b = *a;
        *a = aux;
    }
    if(*c > *b)
    {
        aux = *b;
        *b = *c;
        *c = aux;
    }
    if(*b > *a)
    {
        aux = *b;
        *b = *a;
        *a = aux;
    }
}

void resultado(int a, int b, int c)
{
    printf("\n%d %d %d\n\n", a, b, c);
}

int main(void)
{
    apresentacao();
    float a = ler_numero("primeiro");
    float b = ler_numero("segundo");
    float c = ler_numero("terceiro");
    ordernador(&a, &b, &c);
    resultado(a, b, c);
}
