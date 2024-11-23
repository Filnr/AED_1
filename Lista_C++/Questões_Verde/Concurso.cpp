#include <iostream>
using namespace std;

const int MAX = 100;
class Candidato
{
private:
    string nome;
    double nota;

public:
    Candidato() : nome(""), nota(0) {};
    void setNome(const string &nome);
    string getNome();
    void setNota(double nota);
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
    cin >> n;
    while (n > MAX)
    {
        cin >> lixo >> n;
    }
    return n;
}

float calculaMedia(Candidato *candidatos[], int n)
{
    float media = 0;
    for (int i = 0; i < n; i++)
    {
        media += candidatos[i]->getNota();
    }
    return media / n;
}

void acimaMedia(Candidato *candidatos[], int n, float media)
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

int main(void)
{
    int n, num;
    Candidato *candidatos[MAX];
    cin >> num >> n;
    cin.ignore(); // Ignora o \n após o número
    for (int i = 0; i < n + 1; i++)
    {
        if (i < n)
        {
            candidatos[i] = new Candidato();
            string nome;
            double nota;
            char aspas;
            cin >> num >> aspas;  // Lê o número e a primeira aspas
            getline(cin, nome, '"'); // Lê o nome até a próxima aspas
            cin >> nota;             // Lê a nota
            candidatos[i]->setNome(nome);
            candidatos[i]->setNota(nota);
        }
        else
        {
            cin >> num;
        }
    }
    float media = calculaMedia(candidatos, n);
    acimaMedia(candidatos, n, media);

    for (int i = 0; i < n; i++)
    {
        delete candidatos[i];
    }
}