#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAX_STR 50
#define TAM 5

typedef struct 
{
    char nome[MAX_STR];
    int idade;
}Pessoa;

typedef struct 
{
    char nome[MAX_STR];
}Clone;

void primeiroNome(Pessoa pessoas[], Clone primeirosNomes[])
{
    int j;
    for(int i = 0; i < TAM; i++)
    {
        j = 0;
        while(pessoas[i].nome[j] != ' ' && pessoas[i].nome[j] != '\0')
        {
            primeirosNomes[i].nome[j] = toupper(pessoas[i].nome[j]);
            j++;
        }
        primeirosNomes[i].nome[j] = '\0';
        
    }
}

void exibiPessoa(Pessoa pessoas)
{
    printf("Nome: %s\n", pessoas.nome);
    printf("Idade: %d\n\n", pessoas.idade);
}

void buscaRec(Pessoa pessoas[], int posicao, char* chaveNome, Clone primeiroNome[])
{
    if((strcmp(primeiroNome[posicao].nome, chaveNome) == 0) && posicao < TAM) exibiPessoa(pessoas[posicao]);
    else if(posicao == TAM) printf("Nome nao encontrado\n");
    else
    {
        buscaRec(pessoas, posicao + 1, chaveNome, primeiroNome);
    }
}

void chamaRec(Pessoa pessoas[], char* chave, Clone primeirosNomes[])
{
    buscaRec(pessoas, 0, chave, primeirosNomes);
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
    Clone primeirosNomes[TAM];
    primeiroNome(pessoas, primeirosNomes);
    chamaRec(pessoas, chave, primeirosNomes);
}