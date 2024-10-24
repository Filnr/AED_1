#include <stdio.h>

void ler_palavra(char palavra[])
{
    printf("Digite uma palavra para ser invertida: ");
    scanf("%s", palavra);
}

int conta_letras(char string[])
{
    int letras = 0, i = 0;
    while(string[i] != '\0')
    {
        letras++;
        i++;
    }
    return letras;
}

void inverte_stringIt(char palavra[])
{
    int i = conta_letras(palavra);
    while(i >= 0)
    {
        printf("%c", palavra[i]);
        i--;
    }
}

void inverte_stringRec(char palavra[], int posicao)
{
    if(posicao == 0) printf("%c", palavra[posicao]);
    else if(posicao > 0)
    {
        printf("%c", palavra[posicao]);
        inverte_stringRec(palavra, posicao - 1);
    }
}

void chamaRec(char palavra[])
{
    inverte_stringRec(palavra, conta_letras(palavra));
}

int main(void)
{
    char string[100];
    ler_palavra(string);
    printf("Palavra inverso por iteracao: ");
    inverte_stringIt(string);
    printf("\nPalavra inverso por recurcao: ");
    chamaRec(string);
}