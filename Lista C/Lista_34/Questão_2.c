#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_STR 50
#define TAM 5

typedef struct
{
    int ano;
    char campeao[MAX_STR];
}CampeonatoBrasileiro;

void ler_string(char string[])
{
    printf("Digite o nome do time que deseja procurar: ");
    scanf("%s", string);
}

int ContaIt(CampeonatoBrasileiro campeoes[], char time[])
{
    int qtCampeoes = 0;
    for(int i = 0; i < TAM; i++)
    {
        if(strcmp(campeoes[i].campeao, time) == 0) qtCampeoes++;
    }
    return qtCampeoes;
}

int contaRec(CampeonatoBrasileiro campeoes[], char time[], int posicao)
{
    int qtCampeoes = 0;
    if(posicao == 0)
    {
        if(strcmp(campeoes[posicao].campeao, time) == 0) qtCampeoes = 1;
    }
    else if(posicao > 0)
    {
        if(strcmp(campeoes[posicao].campeao, time) == 0)
        {
            qtCampeoes = 1;
        }
        qtCampeoes = qtCampeoes + contaRec(campeoes, time, posicao - 1);
    }
    return qtCampeoes;
}

int chamaRec(CampeonatoBrasileiro campeoes[], char time[])
{
    return contaRec(campeoes, time, TAM - 1);
}

bool verificaTime(CampeonatoBrasileiro campeoes[], char time[])
{
    bool encontrado = false;
    int i = 0;
    while(i < TAM && !encontrado)
    {
        if(strcmp(campeoes[i].campeao, time) == 0) encontrado = true;
        i++;
    }
    return encontrado;
}

void resultado(int qtCampeos, char* msg)
{
    printf("O time selecionado foi campeao %d vezes%s\n\n", qtCampeos, msg);
}

void arrumaTimes(CampeonatoBrasileiro campeoes[], char time[])
{
    int i = 0;
    while(time[i] != '\0')
    {
        time[i] = toupper(time[i]);
        i++;
    }

    for(int j = 0; j < TAM; j++)
    {
        i = 0;
        while(campeoes[j].campeao[i] != '\0')
        {
            campeoes[j].campeao[i] = toupper(campeoes[j].campeao[i]);
            i++;
        }
    }
}

int main(void)
{
    CampeonatoBrasileiro campeoes[TAM] = {
    {2020, "Flamengo"},
    {2019, "Flamengo"},
    {2018, "Palmeiras"},
    {2017, "Corinthians"},
    {2016, "Palmeiras"}};

    char time[MAX_STR];
    ler_string(time);
    arrumaTimes(campeoes, time);
    if(verificaTime(campeoes, time))
    {
        resultado(ContaIt(campeoes, time), ", por iteracao");
        resultado(chamaRec(campeoes, time), ", por recursao");
    }
    else 
    {
        resultado(0, "");
    }
}