#include <stdio.h>
#include <stdlib.h>

void apresentacao()
{
    printf("Bem-Vindo, Sou um programa que decompoe um numero\n\n");
}

int ler_num(char* msg)
{
    int num;
    printf("Digite %s: ", msg);
    scanf("%d", &num);
    return num;
}

void iterativo(int n)
{
    int resultado = 0;
   while(n > 0)
   {
        int decompor = n %10;
        n = n/10;
        resultado = (resultado * 10) + decompor;
   }
    while(resultado > 0)
    {
        int decompor = resultado % 10;
        resultado = resultado / 10;
        printf("%d\n", decompor);
    }
}

void recursivo(int n)
{
    if(n > 0)
    {
        int decompor = n % 10;
        recursivo(n/10);
        printf("%d\n", decompor);
    }
}


int main()
{
    apresentacao();
    int num = ler_num("um numero");
    iterativo(num);
    printf("\n\n\n");
    recursivo(num);
    return 0;
}
