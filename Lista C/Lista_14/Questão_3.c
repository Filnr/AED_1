#include <stdio.h>

void impressao(int inf, int sup)
{
    printf("%d ", inf);
    if (inf < sup) 
    {
        impressao(inf + 1, sup);
    }
    printf("%d ", inf);
}

int ler_numero(char* msg)
{
    int n1;
    printf("Digite o limite %s: ", msg);
    scanf("%d", &n1);
    return n1;
}

int main(void)
{
    int limite_inferior = ler_numero("inferior");
    int limite_superior = ler_numero("superior"); 
    impressao(limite_inferior, limite_superior);
    return 0;
}