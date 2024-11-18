#include <stdio.h>

void ler_palavra(char palavra[])
{
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
}

void concatenacao(char s1[], char s2[], char s3[], char concatenado[])
{
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        concatenado[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0') {
        concatenado[i] = s2[j];
        i++;
        j++;
    }

    j = 0; 

    while (s3[j] != '\0') {
        concatenado[i] = s3[j];
        i++;
        j++;
    }

    concatenado[i] = '\0';
}

void ler_string(char s1[], char s2[], char s3[], char concatenado[])
{
    concatenacao(s1, s2, s3, concatenado);
    int i = 0;
    while(concatenado[i] != '\0')
    {
        printf("%c", concatenado[i]);
        i++;
    }
}

int main(void)
{
    char palavra1[100];
    ler_palavra(palavra1);
    char palavra2[100];
    ler_palavra(palavra2);
    char palavra3[100];
    ler_palavra(palavra3);
    char concatenado[300];
    printf("\nConcatenação por iteracao: ");
    ler_string(palavra1, palavra2, palavra3, concatenado);
}