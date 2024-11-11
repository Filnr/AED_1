#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_STR 50

void lerString(char string[])
{
    printf("Digite uma palavra: ");
    scanf("%s", string);
}

bool inverteString(char string[], char stringInvertida[])
{
    int i = 0;
    int j = (strlen(string) - 1);
    while(j >= 0 && i < MAX_STR)
    {
        stringInvertida[i] = string[j];
        i++;
        j--;
    }
    stringInvertida[i] = '\0';
}

void inverteStringRec(char string[], char stringInvertidaRec[], int i, int j)
{
    if(i == strlen(string) - 1 && j == 0)
    {
        stringInvertidaRec[i] = string[j];
        stringInvertidaRec[i+1] = '\0';
    }
    else if(i < strlen(string) && j > 0)
    {
        stringInvertidaRec[i] = string[j];
        inverteStringRec(string, stringInvertidaRec, i + 1, j - 1);
    }  
}

void chamaRec(char string[], char stringInvertidaRec[])
{
    inverteStringRec(string, stringInvertidaRec, 0, strlen(string) - 1);
}

bool ehPalindromo(char string[], char stringInvertida[])
{
    bool eh_Palindromo = strcmp(string, stringInvertida) == 0;
    return eh_Palindromo;
}

int main(void)
{
    char string[MAX_STR];
    char stringInvertida[MAX_STR];
    char stringInvertidaRec[MAX_STR];
    lerString(string);
    inverteString(string, stringInvertida);
    chamaRec(string, stringInvertidaRec);
    if(ehPalindromo(string, stringInvertida)) printf("A palavra e um palindromo por iterativo\n");
    else printf("Nao e um palindromo por iterativo\n");

    if(ehPalindromo(string, stringInvertidaRec)) printf("A palavra e um palindromo por recursivo\n");
    else printf("Nao e um palindromo por recursivo\n");
}