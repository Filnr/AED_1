#include <stdio.h>
#include <stdbool.h>

int ler_lado(char* msg)
{
    bool invalido;
    int lado;
    do
    {
        printf("Digite o valor do %s lado do triangulo: ", msg);
        scanf("%d", &lado);
        invalido = lado < 1;
        if(invalido) printf("Digite um valor valido\n\n");
    } while (invalido);
    return lado;
}

bool eh_triangulo(int l1, int l2, int l3)
{
    bool triangulo = false, verificado;
    verificado = (l1 + l2 > l3) && (l1 + l3 > l2) && (l2 + l3 > l1); 
    if(verificado) triangulo = true;
    return triangulo;
}

int tipo_triangulo(int l1, int l2, int l3)
{
    int tipo;
    if(!(eh_triangulo(l1, l2, l3))) tipo = 0;
    //verificação de se é triangulo
    else if(l1 == l2 && l2 == l3) tipo = 1;
    else if((l1 == l2 || l2 == l3 || l3 == l1)) tipo = 2;
    else tipo = 3;
    return tipo;
}

void resultado(char* tipo)
{
    printf("Triangulo digitado: %s", tipo);
}

void apresentacao()
{
    printf("Bem vindo, irei determinar o tipo de triangulo digitado\n\n");
}

int main(void)
{
    int lado1, lado2, lado3, tipo;
    apresentacao();
    lado1 = ler_lado("primeiro");
    lado2 = ler_lado("segundo");
    lado3 = ler_lado("terceiro");
    tipo = tipo_triangulo(lado1, lado2, lado3);
    switch (tipo)
    {
    case 1:
        resultado("Equilatero");
        break;
    case 2:
        resultado("Isoscele");
        break;
    case 3:
        resultado("Escaleno");
    }
    return 0;
}