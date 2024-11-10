#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include "data.h"
#include "Pessoa.h"
#include "definicoes.h"
#include "saveLoad.h"
#include <ctype.h>
#include <string.h>

int menu()
{
    int op;
    bool invalido;
    printf("\n\tMenu\n\n");
    printf("0 - Encerrar programa\n");
    printf("1 - Cadastrar uma pessoa\n");
    printf("2 - Listar todas as pessoas\n");
    printf("3 - Pesquisar por nome\n");
    printf("4 - Pesquisar por CPF\n");
    printf("5 - Excluir pessoa\n");
    printf("6 - Excluir todos os registros\n\n");
    {
        printf("Qual acao deseja realizar?: ");
        scanf("%d", &op);
        invalido = op < 0 || op > 6;
        if (invalido)
            printf("Digite um numero válido\n");
    } while (invalido);
    return op;
}

int main(void)
{
    setlocale(LC_ALL, "");
    Pessoa pessoas[MAX];
    int op = menu();
    backupDados(pessoas);
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            cadastraPessoas(pessoas);
            break;
        case 2:
            listar_pessoas(pessoas);
            break;
        case 3:
            pesquisaNome(pessoas);
            break;
        case 4:
            pesquisaCPF(pessoas);
            break;
        case 5:
            apagaSelecionado(pessoas);
            break;
        case 6:
            apagaDados();
        }
        op = menu();
    }
    encerramento(pessoas);
    return 0;
}