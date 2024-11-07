#ifndef PESSOA_H
#define PESSOA_H
#include "data.h"
#include "definicoes.h"

#define MAX_STR 50
#define TAM_CPF 12
typedef struct
{
    char nome[MAX_STR];
    Data dataNascimento;
    char cpf[TAM_CPF];
} Pessoa;

void exibePessoas(Pessoa pessoas[], int i)
{
    printf("Nome: %s, data de aniversário: %d/%d/%d", pessoas[i].nome, pessoas[i].dataNascimento.dia, pessoas[i].dataNascimento.mes, pessoas[i].dataNascimento.ano);
    printf("CPF: %s", pessoas[i].cpf)
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

bool cpfValido(Pessoa pessoas[])
{
    bool valido = true;
    if (len != 11)
        {
            printf("CPF deve ter 11 dígitos\n");
            valido = false;
            continue;
        }
    for (int i = 0; pessoas[TAM].cpf[i] != '\0' && valido; i++)
    {
        if (!isdigit(pessoas[TAM].cpf[i]))
        {
            valido = false;
        }
    }
    return valido;
}

void cadastraCPF(Pessoa pessoas[])
{
    do
    {
        printf("CPF: ");
        fgets(pessoas[TAM].cpf, sizeof(pessoas[TAM].cpf), stdin);
        size_t len = strlen(pessoas[TAM].cpf);
        if (len > 0 && pessoas[TAM].cpf[len - 1] == '\n')
        {
            pessoas[TAM].cpf[len - 1] = '\0';
            len--;
        }
        if (cpfValido(pessoas))
            printf("cpf invalido\n");
    } while (cpfValido(pessoas));
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

#endif // PESSOA_H