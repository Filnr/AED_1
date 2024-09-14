#include <stdio.h>
#include <stdbool.h>

void apresentacao()
{
	printf("Seja bem-vindo, Nesse programa irei calcular a area de um triangulo\n\n");
}

float ler_valor(char* msg)
{
	float valor;
	bool invalido;
	do
	{
		printf("Digite o valor da %s: ", msg);
		scanf("%f", &valor);
		invalido = valor <= 0;
		if(invalido) printf("Digite um numero valido\n\n");
	}
	while(invalido);
	return valor;
}

float calcular_area(float base, float altura)
{
	float area = (base * altura) / 2;
	return area;
}

void resultado(float base, float altura, float area)
{
	printf("\nO valor da base %.2f e da altura %.2f vale %.2f", base, altura, area);
}

int main(void)
{
	apresentacao();
	float base = ler_valor("base");
	float altura = ler_valor("altura");
	float area = calcular_area(base, altura);
	resultado(base, altura, area);
	return 0;
}