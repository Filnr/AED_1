#ifndef DATA_H
#define DATA_H

typedef struct
{
    int dia;
    int mes;
    int ano;
}Data;

int diasMes(Data data)
{
    int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return dias[data.mes - 1];
}

char* mesExtenso(Data data)
{
    char* meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho",
                      "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    return meses[data.mes - 1];
}

bool ehBissexto(Data data)
{
    bool bissexto = false;
    if(data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0))
    {
        bissexto = true;
    }
    return bissexto;
}

bool dataValida(Data data)
{
    bool valido = false;
    int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(data.ano > 0 && data.mes > 0 && data.mes <= 12 && data.dia > 0 && data.dia <= dias[data.mes - 1])
    {
        valido = true;
    }
    return valido;
}

char* diaSemana(Data data)
{
    int A = data.ano / 100;
    int B = A / 4;
    int C = 2 - A + B;
    float D = 365.25 * (data.ano + 4716);
    float E =  30.6001 * (data.mes + 1);
    float diajuliano = D + E + data.dia - 1524.5;
    int diaSemana = (int)diajuliano % 7;
    char* dias[] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    return dias[diaSemana];
}

#endif // DATA_H