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
    int letras = 0, posicao = 0;
    while(!fim && posicao < 100)
    {
        if(isalpha(string[posicao]))
        {
            string[posicao] = toupper(string[posicao]);
            if(string[posicao] == 'A' || string[posicao] == 'E' || string[posicao] == 'I' || string[posicao] == 'O' || string[posicao] == 'U')
            {
                letras++;
            }
        }
        fim = !isalpha(string[posicao]);
        posicao++;
    }
    return letras;
}

int recursivo(char string[], int posicao)
{
    int letras = 0;
    if(isalpha(string[posicao]))
    {
        string[posicao] = toupper(string[posicao]);
        if(string[posicao] == 'A' || string[posicao] == 'E' || string[posicao] == 'I' || string[posicao] == 'O' || string[posicao] == 'U')
        {
            letras = 1;
        }
        letras = letras + recursivo(string, posicao + 1);
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