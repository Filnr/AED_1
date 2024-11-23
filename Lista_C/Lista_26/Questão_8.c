#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define TAM 100

void ler_string(char string[])
{
    printf("Digite uma palavra: ");
    fgets(string, TAM, stdin);
}

int conta_letras(char string[])
{
    int i = 0, letras = 0;
    while(string[i] != '\0')
    {
        letras++;
        i++;
    }
    return letras;
}

void inverte_string(char string[])
{
    int i = conta_letras(string);
    while(i >= 0)
    {
        printf("%c", string[i]);
        i--;
    }
}

int main(void)
{
    char string[TAM];
    ler_string(string);
    inverte_string(string);
    return 0;
}