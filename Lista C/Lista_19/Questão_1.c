#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void peso_ideal(char sexo, float altura)
{   float *peso_ideal;
    peso_ideal = malloc(sizeof(int));
    if(sexo == 'M')
    {
        *peso_ideal = (72.7 * (altura)) - 58;
    }
    else if(sexo == 'F')
    {
        *peso_ideal = (62.1 * (altura)) - 44.7;
    }
    printf("Peso ideal: %.2f", *peso_ideal);
}

char sexo()
{
    bool invalido;
    char sexo;
    do
    {
        printf("Digite o sexo: ");
        scanf("%c", &sexo);
        sexo = toupper(sexo);
        invalido = (sexo != 'M') && (sexo != 'F');
        if(invalido) printf("Digite um sexo valido\n");
    } while (invalido);
    return sexo;
}

float ler_numero()
{
    float *num;
    num = malloc(sizeof(int));
    printf("Digite a altura: ");    
    scanf("%f", num);
    return *num;
}

int main()
{
    char genero = sexo();
    float *altura;
    altura = malloc(sizeof(int));
    *altura = ler_numero();
    peso_ideal(genero, *altura);
    return 0;
}