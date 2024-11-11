#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_STR 50
#define TAM 5

typedef struct 
{
    char nome[MAX_STR];
    int idade;
}Pessoa;

void exibiPessoa(Pessoa pessoas)
{
    printf("Nome: %s\n", pessoas.nome);
    printf("Idade: %d\n\n", pessoas.idade);
}

bool strIguais(char pessoas[], char chave[])
{
    bool iguais = true;
    int i = 0;
    while(chave[i] != '\0' && pessoas[i] != '\0' && i < MAX_STR && iguais)
    {
        if(toupper(chave[i]) != toupper(pessoas[i])){
            iguais = false;
        }
        i++;
    }
    return iguais;
}

void buscaRec(Pessoa pessoas[], int posicao, char* chaveNome)
{
    if(posicao == TAM - 1 && strIguais(pessoas[posicao].nome, chaveNome)){
            exibiPessoa(pessoas[posicao]);
    }
    else if(posicao < TAM){
        if(strIguais(pessoas[posicao].nome, chaveNome)){
            exibiPessoa(pessoas[posicao]);
        }
        buscaRec(pessoas,posicao + 1, chaveNome);
    }
    else printf("Nome nao encontrado\n");
}

void chamaRec(Pessoa pessoas[], char* chave)
{
    buscaRec(pessoas, 0, chave);
}

void criaChave(char chave[])
{
    printf("Qual nome deseja buscar: ");
    scanf("%s", chave);
    int i = 0;
    while(chave[i] != '\0')
    {
        chave[i] = toupper(chave[i]);
        i++;
    }
}

int main(void)
{
    char chave[MAX_STR];
    criaChave(chave);
    Pessoa pessoas[TAM] = {
        {"Joao Silva", 18},
        {"Maria Santos", 25},
        {"Carlos Oliveira", 19},
        {"Ana Pereira", 22},
        {"Lucas Mendes", 25}};
    chamaRec(pessoas, chave);
}