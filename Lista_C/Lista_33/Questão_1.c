#include <stdio.h>
#include <string.h>
#include "../Bibliotecas/Pessoa.h"
#include <stdbool.h>

bool compCPF(Pessoa pessoa1, Pessoa pessoa2)
{
    bool iguais = false;
    if(strcmp(pessoa1.nome, pessoa2.nome) == 0) iguais = true;
    return iguais;
}

bool compDatas(Pessoa pessoa1, Pessoa pessoa2)
{
    bool dataIgual = false;
    if((pessoa1.dataNascimento.dia == pessoa2.dataNascimento.dia) && (pessoa1.dataNascimento.mes == pessoa2.dataNascimento.mes) && (pessoa1.dataNascimento.ano == pessoa2.dataNascimento.ano))
    {
        dataIgual = true;
    }
    return dataIgual;
}

bool saoIguais(Pessoa pessoa1, Pessoa pessoa2)
{
    bool ehIguais = false;
    if((strcmp(pessoa1.nome, pessoa2.nome) == 0) && (compDatas(pessoa1, pessoa2)) && (compCPF(pessoa1, pessoa2)))
    {
        ehIguais = true;
    }
    return ehIguais;
}

int main(void)
{
    Pessoa pessoa1 = {"Filipe", {22, 02, 2006}, "16821123999"};
    Pessoa pessoa2 = {"Filipe", {22, 02, 2006}, "16821123999"};
    if(saoIguais(pessoa1, pessoa2)) printf("Sao iguais\n");
    else printf("Nao sao iguais");

}