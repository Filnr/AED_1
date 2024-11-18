#include <stdio.h>
#include <string.h>
#define MAX_STR 50
#define TAM 5

typedef struct
{
    char nome[MAX_STR];
    float salario;
} Funcionario;

float mediaSalario(Funcionario funcionarios[])
{
    float soma = 0;
    for (int i = 0; i < TAM; i++)
    {
        soma += funcionarios[i].salario;
    }
    soma /= TAM;
    return soma;
}

int salarioAcima(Funcionario funcionarios[])
{
    int salarioAcimaMedia = 0;
    float media = mediaSalario(funcionarios);
    for (int i = 0; i < TAM; i++)
    {
        if (funcionarios[i].salario > media)
            salarioAcimaMedia++;
    }
    return salarioAcimaMedia;
}

void resultado(Funcionario funcionarios[])
{
    printf("Quantidade de funcionarios com o salario acima da media: %d\n", salarioAcima(funcionarios));
    printf("Media salarial: %.2f", mediaSalario(funcionarios));
}

int main(void)
{
    Funcionario funcionarios[TAM] = {
        {"João Silva", 2500.00},
        {"Maria Santos", 3200.00},
        {"Carlos Oliveira", 2750.50},
        {"Ana Pereira", 3100.75},
        {"Lucas Mendes", 2900.00}};
    resultado(funcionarios);
    return 0;
}