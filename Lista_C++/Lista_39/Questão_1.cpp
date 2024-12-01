#include <iostream>
#include <string>
using namespace std;
#define MAX 100

class Data
{
private:
    int dia, mes, ano;

public:
    Data()
    {
        dia = mes = ano = 0;
    }
    Data(int dia, int mes, int ano)
    {
        this->setData(dia, mes, ano);
    }
    Data(int ano)
    {
        this->setData(0, 0, ano);
    }
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
    Pessoa()
    {
        nome = "";
        dataNascimento = Data();
    }
    Pessoa(string nome, int dia, int mes, int ano)
    {
        this->setNome(nome);
        this->setDataNascimento(dia, mes, ano);
        TAM++;
    }
    Pessoa(string nome)
    {
        this->setNome(nome);
        this->setDataNascimento(0, 0, 0);
        TAM++;
    }
    ~Pessoa()
    {
        TAM--;
    }
    void setNome(const string &nome);
    string getNome();
    void setDataNascimento(int dia, int mes, int ano);
    void getDataNascimento(int &dia, int &mes, int &ano);
};

int Pessoa::TAM = 0;

void setNomePessoa(Pessoa pessoas[], int posicao)
{
    string nome;
    cout << "Digite o nome da pessoa: ";
    cin.ignore();       // Ignora qualquer caractere pendente no buffer de entrada
    getline(cin, nome); // Usa getline para ler o nome completo
    pessoas[posicao].setNome(nome);
}

void setPessoaData(Pessoa pessoas[], int posicao)
{
    int dia, mes, ano;
    char delimiter;
    cout << "Digite a data de nascimento (dia/mes/ano): ";
    cin >> dia >> delimiter >> mes >> delimiter >> ano;
    pessoas[posicao].setDataNascimento(dia, mes, ano);
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
    FILE *cadastros = fopen("cadastros.dat", "rb");
    if (cadastros == NULL)
    {
        cout << "Nenhum dado foi carregado." << endl;
        Pessoa::TAM = 0;
        return;
    }

    fread(&Pessoa::TAM, sizeof(int), 1, cadastros); // Lê o número de registros
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        pessoas[i] = new Pessoa(); // Aloca um novo objeto
        fread(pessoas[i], sizeof(Pessoa), 1, cadastros); // Lê cada objeto
    }

    fclose(cadastros);
}


void salvaDados(Pessoa *pessoas[])
{
    FILE *cadastros = fopen("cadastros.dat", "wb");
    if (cadastros == NULL)
    {
        cout << "Erro ao abrir cadastros.dat para salvar." << endl;
        return;
    }

    fwrite(&Pessoa::TAM, sizeof(int), 1, cadastros); // Salva o número de registros
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        fwrite(pessoas[i], sizeof(Pessoa), 1, cadastros); // Salva cada objeto
    }

    fclose(cadastros);
}


void setPessoa(Pessoa *pessoas[])
{
    if (Pessoa::TAM < MAX)
    {
        string nome;
        cout << "Digite o nome da pessoa: ";
        cin.ignore();
        getline(cin, nome); // Para ler nomes compostos

        int dia, mes, ano;
        cout << "Digite a data de nascimento (dia/mes/ano): ";
        cin >> dia;
        cin.ignore(); // Ignora o '/'
        cin >> mes;
        cin.ignore(); // Ignora o '/'
        cin >> ano;

        pessoas[Pessoa::TAM] = new Pessoa(nome, dia, mes, ano);
    }
    else
    {
        cout << "Limite de pessoas atingido!" << endl;
    }
}

void listaPessoas(Pessoa *pessoas[])
{
    if (Pessoa::TAM == 0)
    {
        cout << "Nenhuma pessoa cadastrada" << endl;
        return;
    }

    for (int i = 0; i < Pessoa::TAM; i++)
    {
        cout << "Nome: " << pessoas[i]->getNome() << endl;
        int dia, mes, ano;
        pessoas[i]->getDataNascimento(dia, mes, ano);
        cout << "Data de nascimento: " << dia << "/" << mes << "/" << ano << endl;
        cout << "----------------------" << endl;
    }
}

void encerraPrograma(Pessoa *pessoas[])
{
    salvaDados(pessoas);
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        delete pessoas[i];
        pessoas[i] = nullptr;
    }
    cout << "Obrigado por utilizar o programa" << endl; 
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
            setPessoa(pessoas);
            break;
        case 2:
            listaPessoas(pessoas);
            break;
        case 3:
            Pessoa::TAM = 0; // Apaga todos os registros
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
        op = menu(); // Atualiza a opção
    }
    return 0;
}
