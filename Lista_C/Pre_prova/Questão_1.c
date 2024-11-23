#include <stdio.h>
#include <stdlib.h>

void apresentacao()
{
    printf("Bem-Vindo, Sou um programa feito para verificar divisores comuns\n\n");
}

int ler_num(char* msg)
{
    int num;
    printf("Digite %s: ", msg);
    scanf("%d", &num);
    return num;
}

int iterativo(int n1, int n2)
{
    int menor, divisores = 0;
    if(n1 > n2) menor = n2;
    else menor = n1;
    for(int i = 2; i <= menor; i++)
    {
        if((n1 % i == 0) && (n2 % i == 0))
        {
            divisores++;
        }
    }
    return divisores;
}

void resultado(int divisores)
{
    printf("Quantidade de divisores comuns: %d\n", divisores);
}

int recursivo(int n1, int n2,int n, int menor, int divisor)
{
    if(n > menor)
    {
        divisor = 0;
    }
        else if((n1 % n == 0) && (n1 % n == 0))
    {
        divisor += 1;
        recursivo(n1, n2, n+1, menor, divisor);
    }
    return divisor;
}


int main()
{
    int divisores, n = 2, menor, divisor = 0;
    apresentacao();
    int num1 = ler_num("um numero");
    int num2 = ler_num("outro numero");
    if(num1 > num2) menor = num2;
    else menor = num1;
    divisores = iterativo(num1, num2);
    resultado(divisores);
    divisores = recursivo(num1, num2, n, menor, divisor);
    resultado(divisores);
    return 0;
}