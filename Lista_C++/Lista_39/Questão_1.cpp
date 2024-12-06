#include <iostream>
#include <string>
#include <cctype>
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
    string cpf;
    Data dataNascimento;

public:
    static int TAM;
    Pessoa() : nome(""), dataNascimento(), cpf("") { TAM++; };
    Pessoa(string nome, int dia, int mes, int ano) : nome(nome), dataNascimento(dia, mes, ano) { TAM++; };
    Pessoa(string nome) : nome(nome), dataNascimento(0) { TAM++; };
    ~Pessoa() { TAM--; };
    void setNome(const string &nome);
    string getNome();
    void setDataNascimento(int dia, int mes, int ano);
    void getDataNascimento(int &dia, int &mes, int &ano);
    void setCPF(const string &cpf);
    string getCPF();
    void deletaPessoas()
    {
        this->~Pessoa();
        TAM++;
    }
};

int Pessoa::TAM = 0;

void Pessoa::setCPF(const string &cpf)
{
    this->cpf = cpf;
}

string Pessoa::getCPF()
{
    return this->cpf;
}

void leNome(string &nome, string mensagem, int caso)
{
    cout << "Digite o nome da " << mensagem << ": ";
    switch (caso)
    {
    case 1: // Caso 1: Usuário digita o nome completo para registro
        cin.ignore();
        getline(cin, nome);
        break;
    case 2: // Caso 2: Usuário digita o primeiro nome para busca
        cin >> nome;
        break;
    }
}
void setNomePessoa(Pessoa *pessoas[], int posicao)
{
    string nome;
    leNome(nome, "pessoa", 1);
    pessoas[posicao]->setNome(nome);
}

void leData(int &dia, int &mes, int &ano)
{
    char delimiter;
    bool erro;
    do
    {
        cout << "Digite a data de nascimento (dia/mes/ano): ";
        cin >> dia >> delimiter >> mes >> delimiter >> ano;
        erro = (dia < 1 || dia > 31) || (mes < 1 || mes > 12) || ano < 1;
        if (erro)
            cout << "Data invalida, tente novamente" << endl;
    } while (erro);
}

void setPessoaData(Pessoa *pessoas[], int posicao)
{
    int dia, mes, ano;
    leData(dia, mes, ano);
    pessoas[posicao]->setDataNascimento(dia, mes, ano);
}

void leCPF(string &cpf, string mensagem)
{
    bool erro;
    do
    {
        cout << "Digite o CPF da " << mensagem << ": ";
        cin >> cpf;
        erro = (cpf.size() != 11);
        if (erro)
            cout << "CPF invalido, tente novamente" << endl;
    } while (erro);
}

void setPessoaCPF(Pessoa *pessoas[], int posicao)
{
    string cpf;
    leCPF(cpf, "pessoa");
    pessoas[posicao]->setCPF(cpf);
}

void setPessoa(Pessoa *pessoas[], int posicao)
{
    pessoas[posicao] = new Pessoa();
    setNomePessoa(pessoas, posicao);
    setPessoaData(pessoas, posicao);
    setPessoaCPF(pessoas, posicao);
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
// Fim das funções de classes
int menu()
{
    int op;
    bool invalido;
    cout << "0 - Sair do programa" << endl;
    cout << "1 - Cadastrar uma pessoa" << endl;
    cout << "2 - Listar todas as pessoas" << endl;
    cout << "3 - Pesquisar por nome" << endl;
    cout << "4 - Pesquisar por CPF" << endl;
    cout << "5 - Excluir Pessoa" << endl;
    cout << "6 - Apagar todos os dados" << endl;
    do
    {
        cout << "Digite a opcao desejada: ";
        cin >> op;
        invalido = (op < 0 || op > 6);
        if (invalido)
            cout << "Opcao invalida, tente novamente" << endl;
    } while (invalido);
    return op;
}

void carregaDados(Pessoa *pessoas[])
{
    FILE *tam = fopen("qtRegistros.dat", "rb");
    if (tam == NULL)
    {
        FILE *tam = fopen("qtRegistros.dat", "wb");
        fprintf(tam, "%d", 0);
        fclose(tam);
    }
    int qtRegistros;
    fscanf(tam, "%d", &qtRegistros);
    fclose(tam);
    Pessoa::TAM = qtRegistros;
    FILE *cadastros = fopen("cadastros.dat", "rb");
    if (cadastros != NULL)
    {
        for (int i = 0; i < qtRegistros; i++)
        {
            int tamNome;
            fread(&tamNome, sizeof(int), 1, cadastros);
            char *buffer = new char[tamNome + 1];
            fread(buffer, sizeof(char), tamNome, cadastros);
            buffer[tamNome] = '\0';
            string nome(buffer);
            delete[] buffer;
            int dia, mes, ano;
            fread(&dia, sizeof(int), 1, cadastros);
            fread(&mes, sizeof(int), 1, cadastros);
            fread(&ano, sizeof(int), 1, cadastros);
            pessoas[i] = new Pessoa(nome, dia, mes, ano);
        }
    }
    fclose(cadastros);
}

void salvaDados(Pessoa *pessoas[])
{
    FILE *tam = fopen("qtRegistros.dat", "wb");
    if (tam != NULL)
    {
        fprintf(tam, "%d", Pessoa::TAM);
        cout << "Salvando " << Pessoa::TAM << " registros" << endl;
    }
    else
        cout << "Erro ao abrir qtRegistros.dat" << endl;
    fclose(tam);

    FILE *cadastros = fopen("cadastros.dat", "wb");
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        string nome = pessoas[i]->getNome();
        int dia, mes, ano;
        pessoas[i]->getDataNascimento(dia, mes, ano);
        int tamNome = nome.size();
        fwrite(&tamNome, sizeof(int), 1, cadastros);
        fwrite(nome.c_str(), sizeof(char), tamNome, cadastros);
        fwrite(&dia, sizeof(int), 1, cadastros);
        fwrite(&mes, sizeof(int), 1, cadastros);
        fwrite(&ano, sizeof(int), 1, cadastros);
    }
    fclose(cadastros);
}

void listaPessoa(Pessoa *pessoas[])
{
    cout << "TAM: " << Pessoa::TAM << endl;
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        string nome = pessoas[i]->getNome();
        int dia, mes, ano;
        pessoas[i]->getDataNascimento(dia, mes, ano);
        cout << "----------------------" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << dia << "/" << mes << "/" << ano << endl;
    }
    cout << "----------------------" << endl
         << endl;
}

bool comparaNomes(const string &nome, const string &nomeProcurado)
{
    int i = 0;
    bool iguais = true;
    // Compara todas as letras das strings até encontrar um caractere nulo
    while (iguais && nome[i] != '\0' && nomeProcurado[i] != '\0')
    {
        if (toupper(nome[i]) != toupper(nomeProcurado[i]))
            iguais = false;
        i++;
    }
    return iguais;
}

void procuraPessoa(Pessoa *pessoas[])
{
    string nomeProcurado;
    leNome(nomeProcurado, "pessoa desejada", 2);
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (comparaNomes(pessoas[i]->getNome(), nomeProcurado))
        {
            cout << "----------------------" << endl;
            cout << "Nome: " << pessoas[i]->getNome() << endl;
            int dia, mes, ano;
            pessoas[i]->getDataNascimento(dia, mes, ano);
            cout << "Data de nascimento: " << dia << "/" << mes << "/" << ano << endl;
            cout << "----------------------" << endl;
        }
    }
}

void pesquisaCPF(Pessoa *pessoas[])
{
    bool encontrado = false;
    string cpfProcurado;
    leCPF(cpfProcurado, "pessoa desejada");
    int i = 0;
    while(i < Pessoa::TAM && !encontrado)
    {
        if(pessoas[i]->getCPF() == cpfProcurado)
        {
            cout << "----------------------" << endl;
            cout << "Nome: " << pessoas[i]->getNome() << endl;
            int dia, mes, ano;
            pessoas[i]->getDataNascimento(dia, mes, ano);
            cout << "Data de nascimento: " << dia << "/" << mes << "/" << ano << endl;
            cout << "----------------------" << endl;
            encontrado = true;
        }
        i++;
    }
    if(!encontrado)
    {
        cout << "Nenhuma pessoa encontrada com o CPF: " << cpfProcurado << endl;
    }
}

void shiftPessoas(Pessoa *pessoas[], int posicao)
{
    for(int i = posicao; i < Pessoa::TAM - 1; i++)
    {
        pessoas[i] = pessoas[i + 1];
    }
    pessoas[Pessoa::TAM - 1] = nullptr; // Definir o último elemento como nullptr
}

void excluiPessoa(Pessoa *pessoas[])
{
    bool encontrado = false;
    string CPF;
    leCPF(CPF, "pessoa a ser excluida");
    int i = 0, tam = Pessoa::TAM;
    while(i < tam && !encontrado)
    {
        if(pessoas[i]->getCPF() == CPF){
            cout << "Pessoa excluida: " << pessoas[i]->getNome() << endl;
            pessoas[i]->deletaPessoas();
            shiftPessoas(pessoas, i);
            Pessoa::TAM--; // Atualizar o tamanho do vetor
            encontrado = true;
        }
        else
        {
            i++; // Incrementar o índice apenas se a pessoa não for encontrada
        }
    }
    if(!encontrado)
    {
        cout << "Nenhuma pessoa encontrada com o CPF: " << CPF << endl;
    }
}

void apagaPessoas(Pessoa *pessoas[])
{
    int tam = Pessoa::TAM;
    for (int i = 0; i < tam; i++)
    {
        cout << "Deletando pessoa " << pessoas[i]->getNome() << endl;
        delete pessoas[i];
    }
}

void encerraPrograma(Pessoa *pessoas[])
{
    cout << "Obrigado por utilizar o programa" << endl;
    // salvaDados(pessoas); // Salva os dados no arquivo
    apagaPessoas(pessoas);
}

int main()
{
    Pessoa *pessoas[MAX];
    // carregaDados(pessoas);

    int op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
            setPessoa(pessoas, Pessoa::TAM);
            cout << endl;
            break;
        case 2:
            listaPessoa(pessoas);
            cout << endl;
            break;
        case 3:
            procuraPessoa(pessoas);
            cout << endl;
            break;
        case 4:
            pesquisaCPF(pessoas);
            cout << endl;
            break;
        case 5:
            excluiPessoa(pessoas);
            cout << endl;
            break;
        case 6:
            cout << "Dados Apagados" << endl;
            apagaPessoas(pessoas);
            cout << endl;
            break;
        }
        op = menu(); // Atualiza a opção
    }
    encerraPrograma(pessoas);
    return 0;
}
