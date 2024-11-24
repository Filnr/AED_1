#include <iostream>
using namespace std;
#define MAX 100

class Candidato
{
private:
    string nome;
    double nota;

public:
    Candidato() : nome(""), nota(0) {};
    void setNome(const string &nome);
    void setNota(double nota);
    string getNome();
    double getNota();
};

void Candidato::setNome(const string &nome)
{
    this->nome = nome;
}

void Candidato::setNota(double nota)
{
    this->nota = nota;
}

string Candidato::getNome()
{
    return this->nome;
}

double Candidato::getNota()
{
    return this->nota;
}

int lerNumero()
{
    int n, lixo;
    cin >> lixo >> n;
    while (n > MAX && n < 0)
    {
        cin >> lixo >> n;
    }
    cin.ignore(); // Ignora o \n após o número
    return n;
}

Candidato *criarCandidato()
{
    Candidato *candidato = new Candidato();
    string nome;
    double nota, lixo;
    char aspas;
    cin >> lixo >> aspas;     // Lê o número e a primeira aspas
    getline(cin, nome, '"'); // Lê o nome até a próxima aspas
    cin >> nota;             // Lê a nota
    candidato->setNome(nome);
    candidato->setNota(nota);
    return candidato;
}

double calculaMedia(Candidato *candidatos[], int n)
{
    double media = 0;
    for (int i = 0; i < n; i++)
    {
        media += candidatos[i]->getNota();
    }
    media /= n;
    return media;
}

void acimaMedia(Candidato *candidatos[], int n, double media)
{
    int linha = 1;
    char aspas = '"';
    for (int i = 0; i < n; i++)
    {
        if (candidatos[i]->getNota() > media)
        {
            cout << linha << " " << aspas << candidatos[i]->getNome() << aspas << " " << candidatos[i]->getNota() << endl;
            linha++;
        }
    }
    cout << linha << endl;
}

int main()
{
    int lixo;
    Candidato *candidatos[MAX];
    int n = lerNumero();
    for (int i = 0; i < n + 1; i++)
    {
        if (i < n)
        {
            candidatos[i] = criarCandidato();
        }
        else
        {
            cin >> lixo;
        }
    }
    float media = calculaMedia(candidatos, n);
    acimaMedia(candidatos, n, media);

    for (int i = 0; i < n; i++)
    {
        delete candidatos[i];
    }
}