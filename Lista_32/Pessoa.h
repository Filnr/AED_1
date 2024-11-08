#ifndef PESSOA_H
#define PESSOA_H
#include "data.h"
#include "definicoes.h"
#include <ctype.h>
#include <string.h>

#define MAX_STR 50
#define MAX_CPF 20
#define TAM_CPF
typedef struct
{
    char nome[MAX_STR];
    Data dataNascimento;
    char cpf[MAX_CPF];
} Pessoa;

void exibePessoas(Pessoa pessoas[], int i)
{
    printf("Nome: %s, data de aniversario: %d/%d/%d ", pessoas[i].nome, pessoas[i].dataNascimento.dia, pessoas[i].dataNascimento.mes, pessoas[i].dataNascimento.ano);
    printf("CPF: %s\n", pessoas[i].cpf);
}

void listar_pessoas(Pessoa pessoas[])
{
    printf("\nLista de todas as pessoas registradas:\n");
    for (int i = 0; i < TAM; i++)
    {
        exibePessoas(pessoas, i);
    }
}

void cadastraNome(Pessoa pessoas[])
{
    printf("Digite o nome da pessoa: ");
    while (getchar() != '\n')
        ; // Clear the input buffer
    fgets(pessoas[TAM].nome, sizeof(pessoas[TAM].nome), stdin);
}

int contaTamanho(Pessoa pessoas[])
{
    int i = 0;
    while (pessoas[TAM].cpf[i] != '\0')
    {
        i++;
    }
    return i;
}

bool cpfValido(Pessoa pessoas[])
{
    bool valido = true;
    if (contaTamanho(pessoas) != 11)
    {
        printf("CPF deve ter 11 dígitos\n");
        valido = false;
    }
    int i = 0;
    while (pessoas[TAM].cpf[i] != '\0' && valido)
    {
        if (!isdigit(pessoas[TAM].cpf[i]))
        {
            valido = false;
        }
        i++;
    }
    return valido;
}

void ler_cpf(Pessoa pessoas[])
{
    printf("CPF: ");
    scanf("%s", pessoas[TAM].cpf);
}

void cadastraCPF(Pessoa pessoas[])
{
    do
    {
        ler_cpf(pessoas);
        if (!cpfValido(pessoas))
            printf("cpf invalido\n");
    } while (!cpfValido(pessoas));
}

void cadastraIdades(Pessoa pessoas[])
{
    bool invalido;
    do
    {
        printf("Digite a data de nascimento: ");
        scanf("%d/%d/%d", &pessoas[TAM].dataNascimento.dia, &pessoas[TAM].dataNascimento.mes, &pessoas[TAM].dataNascimento.ano);
        if (!dataValida(pessoas[TAM].dataNascimento))
            printf("Digite uma data valida\n");
    } while (!dataValida(pessoas[TAM].dataNascimento));
}

void cadastraPessoas(Pessoa pessoas[])
{
    if (TAM >= MAX)
    {
        printf("Limite de cadastro atingido!\n");
    }
    else
    {
        cadastraNome(pessoas);
        cadastraIdades(pessoas);
        cadastraCPF(pessoas);
        TAM++;
    }
}

void lerNome(char nome[])
{
    printf("Digite o nome");
    while (getchar() != '\n')
        ; // Clear the input buffer
    scanf("%s", nome);
}

void extraiNome(Pessoa pessoas[], char primeiroNome[])
{
    int i = 0;
    while (pessoas[TAM].nome[i] != '\0' && pessoas[TAM].nome[i] != ' ')
    {
        primeiroNome[i] = pessoas[TAM].nome[i];
        i++;
    }
    primeiroNome[i] = '\0';
}
void pesquisaNome(Pessoa pessoas[])
{
    bool naoEncontrado = true;
    char nome[MAX_STR], primeiroNome[MAX_STR];
    lerNome(nome);
    extraiNome(pessoas, primeiroNome);
    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(nome, primeiroNome) == 0)
        {
            exibePessoas(pessoas, i);
            naoEncontrado = false;
        }
    }
    if (naoEncontrado)
        printf("Nenhuma pessoa foi encontrada");
}

void leitorCpf(char *cpf)
{
    printf("Digite o CPF: ");
    scanf("%s", cpf);
}

void pesquisaCPF(Pessoa pessoas[])
{
    bool naoEncontrado = true;
    char cpf[MAX_CPF];
    leitorCpf(cpf);
    int i = 0;
    while(i < TAM && naoEncontrado)
    {
        if (strcmp(pessoas[i].cpf, cpf) == 0)
        {
            exibePessoas(pessoas, i);
            naoEncontrado = false;
        }
    }

    if (naoEncontrado)
    {
        printf("Nenhuma pessoa encontrada com o CPF %s.\n", cpf);
    }
}

void apagaPessoa(Pessoa pessoas[], int i)
{
    for(int j = i; j < TAM; j++)
    {
        pessoas[i] = pessoas[i + 1];
    }
}

void apagaSelecionado(Pessoa pessoas[])
{
    bool naoEncontrado = true;
    char cpf[MAX_CPF];
    leitorCpf(cpf);
    int i = 0;
    while(i < TAM && naoEncontrado)
    {
        if (strcmp(pessoas[i].cpf, cpf) == 0)
        {
            apagaPessoa(pessoas, i);
            TAM--;
        }
    }

    if (naoEncontrado)
    {
        printf("Nenhuma pessoa encontrada com o CPF %s.\n", cpf);
    }
}
#endif // PESSOA_H