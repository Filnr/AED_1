#include <stdio.h>

#define DIAS_NO_ANO 365

int ler_numero();
int contar_dias(int);
void resposta(int, int);

int main(void)
{
	int idade, dias;
	printf("Calculadora de dias vividos\n\n");
	idade = ler_numero();
	dias = contar_dias(idade);
	resposta(idade, dias);
	return 0;
}

int ler_numero()
{
	int idade;
	printf("Digite sua idade: ");
	scanf("%d", &idade);
	return idade;
}

int contar_dias(int idade)
{
	return (idade * DIAS_NO_ANO);
}

void resposta(int idade, int dias)
{
	printf("Quantidade de dias vividos em %d anos: %d", idade, dias);
}