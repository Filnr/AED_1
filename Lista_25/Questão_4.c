#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void ler_string(char string[])
{
    printf("Digite uma palavra: ");
    scanf("%s", string);
}


int contar_letras(char string[])
{
    bool fim = false;
    int letras = 0, i = 0;
    while(!fim && i < 100)
    {
        if(isalpha(string[i])) letras++;
        fim = !isalpha(string[i]);
        i++;
    }
    return letras;
}

int recursivo(char string[], int posicao)
{
    int letras = 0;
    if(isalpha(string[posicao]))
    {
        letras = 1 + recursivo(string, posicao + 1);
    }
    return letras;
}

void resultado(char string[])
{
    printf("Quantidade de letras por iterativo: %d\n", contar_letras(string));
    printf("Quantidade de letras por recursivo: %d\n", recursivo(string, 0));
}

int main(void)
{
    char str[100];
    ler_string(str);
    resultado(str);
}