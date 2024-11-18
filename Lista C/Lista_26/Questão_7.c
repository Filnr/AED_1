#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define TAM 100

void ler_string(char string[], char* msg)
{
    printf("Digite %s palavra: ", msg);
    fgets(string, TAM, stdin);
}

bool saoiguais(char string1[], char string2[])
{
    bool iguais = true;
    int i = 0;
    while(string1[i] != '\0' && string2[i] != '\0' && iguais)
    {   
        string1[i] = toupper(string1[i]);
        string2[i] = toupper(string2[i]);
        if(string1[i] != string2[i]) iguais = false;
        i++;
    }
    if(string1[i] != string2[i]) iguais = false;
    return iguais;
}

int main(void)
{
    char string1[TAM];
    ler_string(string1, "a primeira");
    char string2[TAM];
    ler_string(string2, "a segunda");
    if(saoiguais(string1, string2)) printf("As strings sao iguais!!\n");
    else printf("As strings sao diferentes!!\n");

}