#include <stdio.h>

void ler_palavra(char palavra[])
{
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
}

void limpa_vetor(int contaVogal[])
{
    for(int i = 0; i < 5; i++)
    {
        contaVogal[i] = 0;
    }
}

void contaVogais(char palavra[], int contaVogal[])
{
    limpa_vetor(contaVogal);
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; palavra[i] != '\0'; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(palavra[i] == vogais[j]) contaVogal[j]++;
        }
    }
}

void imprime_vetor(char string[], int contador[])
{
    contaVogais(string, contador);
    for(int i = 0; i < 5; i++)
    {
        printf("%d, ", contador[i]);
    }
}

int main(void)
{
    char string[100];
    int contVogal[5];
    ler_palavra(string);
    imprime_vetor(string, contVogal);
}

