#include <iostream>
#include <string>

using namespace std;
#define TAM 5
class Data
{
    private:
        int dia, mes, ano;
    public:
        void setData(int dia, int mes, int ano){
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        }
        void getData(int &dia, int &mes, int &ano){
            dia = this->dia;
            mes = this->mes;
            ano = this->ano;
        }
};

class Aluno
{
    private:
        string nome;
        Data dataNascimento;
    public:
        Aluno() : nome(""), dataNascimento() {}
        string getNome(){
            return this->nome;
        }
        void setDataNascimento(int dia, int mes, int ano){
            this->dataNascimento.setData(dia, mes, ano);
        }
        void getDataNascimento(int &dia, int &mes, int &ano){
            this->dataNascimento.getData(dia, mes, ano);
        }
        void setNome(string nome){
            this->nome = nome;
        }
};

void setNome(Aluno &aluno, int posicao)
{
    string nome;
    cout << "Digite o nome do aluno" << posicao << ": ";
    getline(cin, nome);
    aluno.setNome(nome);
}

void setData(Aluno &aluno, int posicao)
{
    char barra;
    int dia, mes, ano;
    cout << "Digite a data de nascimento do aluno" << posicao << ": ";
    cin >> dia >> barra >> mes >> barra >> ano;
    cin.ignore();
    aluno.setDataNascimento(dia, mes, ano);
}

void lerPessoa(Aluno alunos[])
{
    for(int i = 0; i < TAM; i++)
    {
        setNome(alunos[i], i+1);
        setData(alunos[i], i+1);
        cout << endl;
    }
}

int contaLetras(string nome)
{
    int contador = 0;
    while(nome[contador] != '\0')
    {
        contador++;
    }
    return contador;
}

int main(void)
{
    Aluno alunos[TAM];
    lerPessoa(alunos);
    int contador = 0;
    for(Aluno aluno: alunos)
    {
        string nome = aluno.getNome();
        if(contaLetras(nome) > 5)
        {
            
            contador++;
        }
    }
    cout << "Quantidade de alunos com nome maior que 5 letras: " << contador << endl;
}