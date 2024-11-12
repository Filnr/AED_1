#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX_STR 50
const int TAM = 5;

typedef struct
{
    int idade;
    char nome[MAX_STR];
}Pessoa;


void lerChave(char chave[])
{
    printf("Digite o nome que deseja procurar: ");
    scanf("%s", chave);
}

bool verificaStr(char nome[], char chave[])
{
    bool iguais = true;
    int i = 0;
    while(iguais && nome[i] != '\0' && chave[i] != '\0')
    {
        if(toupper(nome[i]) != toupper(chave[i]))
        {
            iguais = false;
        }
        i++;
    }
    return iguais;
}

void listaPessoa(Pessoa pessoa)
{
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n\n", pessoa.idade);
}

void procuraPessoaIt(Pessoa pessoas[], char chave[])
{
    for(int i = 0; i < TAM; i++)
    {
        if(verificaStr(pessoas[i].nome, chave))
        {
            listaPessoa(pessoas[i]);
        }
    }
}

void procuraPessoaRec(Pessoa pessoas[], char chave[], int posicao)
{
    if(posicao == TAM - 1){
        if(verificaStr(pessoas[posicao].nome, chave))
        {
            listaPessoa(pessoas[posicao]);
        }
    }
    else if(posicao < TAM){
        if(verificaStr(pessoas[posicao].nome, chave))
        {
            listaPessoa(pessoas[posicao]);
        }
        procuraPessoaRec(pessoas, chave, posicao + 1);
    }

}

void chamaRec(Pessoa pessoas[], char chave[])
{
    procuraPessoaRec(pessoas, chave, 0);
}

int main(void)
{
    Pessoa pessoas[5] = {
    {25, "Alice"},
    {32, "Bruno"},
    {29, "Carlos"},
    {40, "Diana"},
    {35, "Elena"}};
    char chave[MAX_STR];
    lerChave(chave);
    printf("Iterativo: \n");
    procuraPessoaIt(pessoas, chave);
    printf("Recursivo: \n");
    chamaRec(pessoas, chave);
}