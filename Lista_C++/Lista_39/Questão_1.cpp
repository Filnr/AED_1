#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data() : dia(0), mes(0), ano(0) {};
    Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {};
    Data(int ano) : dia(0), mes(0), ano(ano) {};
    void setData(int dia, int mes, int ano);
    int getDia();
    int getMes();
    int getAno();
};

class Pessoa
{
private:
    string nome;
    Data dataNascimento;

public:
    static int TAM;
    Pessoa() : nome(""), dataNascimento() {};
    Pessoa(string nome, int dia,  int mes, int ano) : nome(nome), dataNascimento(dia, mes, ano) {};
    Pessoa(string nome) : nome(nome), dataNascimento(0) {};
    void setNome(const string &nome);
    string getNome();
    void setDataNascimento(int dia, int mes, int ano);
    void getDataNascimento(int &dia, int &mes, int &ano);
};

int Pessoa::TAM = 0;

void setNomePessoa(Pessoa *pessoas[], int posicao)
{
    string nome;
    cout << "Digite o nome da pessoa: ";
    cin.ignore();       // Ignora qualquer caractere pendente no buffer de entrada
    getline(cin, nome); // Usa getline para ler o nome completo
    pessoas[posicao]->setNome(nome);
}

void setPessoaData(Pessoa *pessoas[], int posicao)
{
    int dia, mes, ano;
    char delimiter;
    cout << "Digite a data de nascimento (dia/mes/ano): ";
    cin >> dia >> delimiter >> mes >> delimiter >> ano;
    pessoas[posicao]->setDataNascimento(dia, mes, ano);
}

void setPessoa(Pessoa *pessoas[], int posicao)
{
    setNomePessoa(pessoas, posicao);
    setPessoaData(pessoas, posicao);
    Pessoa::TAM++;
}

void Data::setData(int dia, int mes, int ano)
{
    if ((dia > 0 && dia <= 31) && (mes > 0 && mes < 13) && ano > 0)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }
    else
    {
        cout << "Data invalida, definindo a data como 0/0/0" << endl;
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
}

int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}

void Pessoa::setNome(const string &nome)
{
    this->nome = nome;
}

string Pessoa::getNome()
{
    return this->nome;
}

void Pessoa::setDataNascimento(int dia, int mes, int ano)
{
    this->dataNascimento.setData(dia, mes, ano);
}

void Pessoa::getDataNascimento(int &dia, int &mes, int &ano)
{
    dia = this->dataNascimento.getDia();
    mes = this->dataNascimento.getMes();
    ano = this->dataNascimento.getAno();
}

int menu()
{
    int op;
    cout << "1 - Cadastrar pessoa" << endl;
    cout << "2 - Listar pessoas" << endl;
    cout << "3 - Apagar dados" << endl;
    cout << "0 - Sair" << endl;
    cout << "Digite a opcao desejada: ";
    cin >> op;
    return op;
}

void carregaDados(Pessoa *pessoas[])
{
    FILE *tam = fopen("qtRegistros.dat", "rb");
    if (tam == NULL) // Verificando se o arquivo foi aberto corretamente
    {
        FILE *tam = fopen("qtRegistros.dat", "wb");
        fprintf(tam, "%d", 0);
    }
    fscanf(tam, "%d", &Pessoa::TAM); // Lê o número de registros
    fclose(tam);

    for(int i = 0; i < Pessoa::TAM; i++)
    {
        pessoas[i] = new Pessoa();
    }

    FILE *cadastros = fopen("cadastros.dat", "rb");
    if (cadastros == NULL) // Verificação se o arquivo binário de cadastros existe
    {
        cout << "Erro ao abrir cadastros.dat" << endl;
        exit(1);
    }
    fread(pessoas, sizeof(Pessoa), Pessoa::TAM, cadastros); // Lê os cadastros de pessoas
    fclose(cadastros);
}

void salvaDados(Pessoa *pessoas[])
{
    FILE *tam = fopen("qtRegistros.dat", "wb");
    if (tam == !NULL)
    {
        fprintf(tam, "%d", Pessoa::TAM);
    }
    else
        cout << "Erro ao abrir qtRegistros.dat" << endl;
    fclose(tam);

    FILE *cadastros = fopen("cadastros.dat", "wb");
    if (cadastros == !NULL) 
    {
        fwrite(pessoas, sizeof(Pessoa), Pessoa::TAM, cadastros);
    }
    else
         cout << "Erro ao abrir cadastros.dat" << endl;
    fclose(cadastros);
}

void listaPessoa(Pessoa *pessoas[])
{
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        string nome = pessoas[i]->getNome();
        int dia, mes, ano;
        pessoas[i]->getDataNascimento(dia, mes, ano);
        cout << "----------------------" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << dia << "/" << mes << "/" << ano << endl;
    }
    cout << "----------------------" << endl << endl;
}

void encerraPrograma(Pessoa *pessoas[])
{
    cout << "Obrigado por utilizar o programa" << endl;
    salvaDados(pessoas); // Salva os dados no arquivo
    for(int i = 0; i < Pessoa::TAM; i++)
    {
        delete pessoas[i];
    }
}

int main()
{
    Pessoa *pessoas[MAX];
    carregaDados(pessoas);

    int op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            setPessoa(pessoas, Pessoa::TAM);
            break;
        case 2:
            listaPessoa(pessoas);
            break;
        case 3:
            cout << "Dados Apagados" << endl;
            Pessoa::TAM = 0;
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
        op = menu(); // Atualiza a opção
    }
    encerraPrograma(pessoas);
    return 0;
}
