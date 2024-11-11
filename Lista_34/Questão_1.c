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

bool verificaPalindromoIt(char string[])
{
    bool ehPalindromo = true;
    int i = 0;
    int j = (strlen(string) - 1);
    while(i < j && ehPalindromo)
    {
        if(string[i] != string[j]) ehPalindromo = false;
        i++;
        j--;
    }
    return ehPalindromo;
}

bool verificaPalindromoRec(char string[], int i, int j)
{
    bool ehPalindromo = true;
    if(ehPalindromo && i < j)
    {
        if(string[i] != string[j]) ehPalindromo = false;
        else verificaPalindromoRec(string, i + 1, j - 1);
    }
    return ehPalindromo;
}

bool chamaRec(char string[])
{
    return verificaPalindromoRec(string, 0, strlen(string) - 1);
}

int main(void)
{
    char string[MAX_STR];
    lerString(string);
    if(verificaPalindromoIt(string)) printf("A palavra e um palindromo por iterativo\n");
    else printf("Nao e um palindromo por iterativo\n");

    if(chamaRec(string)) printf("A palavra e um palindromo por recursivo\n");
    else printf("Nao e um palindromo por recursivo\n");
}