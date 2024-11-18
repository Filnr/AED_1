#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void apresentacao()
{
    printf("Programa que calcula o peso ideal por altura\n\n");
}

char genero()
{
    bool invalido;
    char sexo;
    do
    {
        printf("Digite o seu sexo: ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
        invalido = (sexo != 'M') && (sexo != 'F');
        if(invalido) printf("Digite um numero valido\n\n");
    } while (invalido);
    return sexo;
}

int ler_idade()
{
    int idade;
    bool invalido;
    do
    {
        printf("Digite a sua idade: ");
        scanf("%d", &idade);
        invalido = idade < 0;
        if(invalido) printf("Digite um valor valido\n\n");
    } while (invalido);
    return idade;
}

float peso_ideal(char sexo, int idade)
{
    float peso_ideal;
    if(sexo == 'M')
    {
        peso_ideal = 50 + (0.5 * (float)idade);
    }
    else 
    {
        peso_ideal = 45 + (0.4 * (float)idade);
    }
    return peso_ideal;
}

void resultado(float peso_ideal)
{
    printf("Peso ideal: %.1f\n", peso_ideal);
}

int main(void)
{
    apresentacao();
    char sexo = genero();
    int idade = ler_idade();
    float peso = peso_ideal(sexo, idade);
    resultado(peso);
}