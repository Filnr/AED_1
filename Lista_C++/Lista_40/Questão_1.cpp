#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

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
    bool verificaMes(int mes)
    {
        return this->mes == mes;
    }
};

class Pessoa
{
protected:
    string nome;
    string cpf;
    Data dataNascimento;

public:
    static int TAM;
    Pessoa() : nome(""), dataNascimento(), cpf("") { TAM++; };
    Pessoa(string nome, string cpf, int dia, int mes, int ano) : nome(nome), cpf(cpf), dataNascimento(dia, mes, ano) {};
    Pessoa(string nome) : nome(nome), dataNascimento(0) { TAM++; };
    ~Pessoa() { TAM--; };
    void setNome(const string &nome);
    string getNome();
    void setDataNascimento(int dia, int mes, int ano);
    void getDataNascimento(int &dia, int &mes, int &ano);
    void setCPF(const string &cpf);
    string getCPF();
    void deletaPessoas() // Para deletar uma pessoa, sem mexer com o valor de tam
    {
        this->~Pessoa();
        TAM++;
    }
};

class Aluno : public Pessoa
{
private:
    string matricula;

public:
    static int TAM;
    Aluno() : Pessoa(), matricula("") { TAM++; };
    Aluno(string nome, string cpf, int dia, int mes, int ano, string matricula) : Pessoa(nome, cpf, dia, mes, ano), matricula(matricula) { TAM++; };
    ~Aluno() { TAM--; };
    void setMatricula(const string &matricula)
    {
        this->matricula = matricula;
    }
    string getMatricula()
    {
        return this->matricula;
    }
    setAluno(const string &nome, const string &cpf, const string &matricula, int dia, int mes, int ano)
    {
        setNome(nome);
        setCPF(cpf);
        setDataNascimento(dia, mes, ano);
        this->matricula = matricula;
    }
};

class Professor : public Pessoa
{
private:
    string titulo;

public:
    static int TAM;
    Professor() : Pessoa(), titulo("") {};
    Professor(string nome, string cpf, int dia, int mes, int ano, string titulo) : Pessoa(nome, cpf, dia, mes, ano), titulo(titulo) {};
    ~Professor() { TAM--; };
    setTitulo(const string &titulo)
    {
        this->titulo = titulo;
    }
    string getTitulo()
    {
        return this->titulo;
    }
    setProfessor(const string &nome, const string &cpf, const string &titulo, int dia, int mes, int ano)
    {
        setNome(nome);
        setCPF(cpf);
        setDataNascimento(dia, mes, ano);
        this->titulo = titulo;
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

void setAlunoMatricula(Aluno *pessoas[], int posicao)
{
    string matricula;
    cout << "Digite a matricula do aluno: ";
    cin >> matricula;
    pessoas[posicao]->setMatricula(matricula);
}

void setAluno(Aluno *pessoas[], int posicao)
{
    pessoas[posicao] = new Aluno();
    setNomePessoa(pessoas, posicao);
    setPessoaData(pessoas, posicao);
    setPessoaCPF(pessoas, posicao);
    setAlunoMatricula(pessoas, posicao);
}

void setProfessorTitulo(Professor *pessoas[], int posicao)
{
    string titulo;
    bool erro;
    do
    {
        cout << "Digite o titulo do professor[Especialista, Mestre ou Doutor]: ";
        cin >> titulo;
        erro = titulo != "Especialista" && titulo != "Mestre" && titulo != "Doutor";
        if (erro)
            cout << "Titulo invalido, tente novamente" << endl;
    } while (erro);
    pessoas[posicao]->setTitulo(titulo);
}

void setProfessor(Professor *pessoas[], int posicao)
{
    pessoas[posicao] = new Professor();
    setNomePessoa(pessoas, posicao);
    setPessoaData(pessoas, posicao);
    setPessoaCPF(pessoas, posicao);
    setProfessorTitulo(pessoas, posicao);
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
int leOpcao(int caso)
{
    int op;
    bool invalido;
    do
    {
        cout << "Digite a opcao desejada: ";
        cin >> op;
        switch (caso) // caso 1: menu principal, caso 2: menu secundário
        {
        case 1:
            invalido = (op < 0 || op > 7);
            break;
        case 2:
            invalido = (op < 0 || op > 3);
            break;
        case 3:
            invalido = (op < 0 || op > 4);
        }
        if (invalido)
            cout << "Opcao invalida, tente novamente" << endl;
    } while (invalido);
    return op;
}

float menuSecundario(int op, bool &voltaMenu)
{
    int escolha;
    switch (op)
    {
    case 1: // menu de cadastro
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Cadastrar Professor " << endl;
        cout << "2 - Cadastrar Aluno" << endl;
        escolha = leOpcao(2);
        break;
    case 2: // menu de listagem
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Listar Professores" << endl;
        cout << "2 - Listar Alunos" << endl;
        escolha = leOpcao(2);
        break;
    case 3: // menu de pesquisa
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Pesquisar Professor por nome" << endl;
        cout << "2 - Pesquisar Aluno por nome" << endl;
        escolha = leOpcao(2);
        break;
    case 4: // menu de pesquisa
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Pesquisar Professor por CPF" << endl;
        cout << "2 - Pesquisar Aluno por CPF" << endl;
        escolha = leOpcao(2);
        break;
    case 5: // menu de exclusão
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Excluir Professor(pelo CPF)" << endl;
        cout << "2 - Excluir Aluno(pelo CPF)" << endl;
        escolha = leOpcao(2);
        break;
    case 6: // menu de exclusão total
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Apagar todos os Professores" << endl;
        cout << "2 - Apagar todos os Alunos" << endl;
        escolha = leOpcao(2);
        break;
    case 7: // menu de aniversariantes
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Informar mes a ser pesquisado" << endl;
        cout << "2 - Listar os professores aniversariantes do mes" << endl;
        cout << "3 - Listar os alunos aniversariantes do mes" << endl;
        escolha = leOpcao(3);
        break;
    }
    if (escolha == 0)
    {
        voltaMenu = true;
    }
    return op + (escolha / 10);
}

float menu()
{
    float op;
    bool retornaMenu = false;
    do
    {
        cout << "0 - Sair do programa" << endl;
        cout << "1 - Cadastrar uma pessoa" << endl;
        cout << "2 - Listar todas as pessoas" << endl;
        cout << "3 - Pesquisar por nome" << endl;
        cout << "4 - Pesquisar por CPF" << endl;
        cout << "5 - Excluir Pessoa" << endl;
        cout << "6 - Apagar todos os dados" << endl;
        cout << "7 - Aniversariantes do mes" << endl;
        op = leOpcao(1);
        if (op != 0)
        {
            op = menuSecundario(op, retornaMenu);
        }
    } while (retornaMenu);

    cout << "teste: " << op << endl;
    return op;
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
    while (i < Pessoa::TAM && !encontrado)
    {
        if (pessoas[i]->getCPF() == cpfProcurado)
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
    if (!encontrado)
    {
        cout << "Nenhuma pessoa encontrada com o CPF: " << cpfProcurado << endl;
    }
}

void shiftPessoas(Pessoa *pessoas[], int posicao)
{
    for (int i = posicao; i < Pessoa::TAM - 1; i++)
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
    while (i < tam && !encontrado)
    {
        if (pessoas[i]->getCPF() == CPF)
        {
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
    if (!encontrado)
    {
        cout << "Nenhuma pessoa encontrada com o CPF: " << CPF << endl;
    }
}

void apagaPessoas(Pessoa *pessoas[])
{
    int tam = Pessoa::TAM;
    for (int i = 0; i < tam; i++)
    {
        delete pessoas[i];
    }
}

void carregaDados(Pessoa *pessoas[])
{
    ifstream arq("qtRegistros.dat");
    if (arq.is_open())
    {
        arq >> Pessoa::TAM;
        arq.close();
    }
    else
    {
        Pessoa::TAM = 0;
    }

    ifstream cadastros("cadastros.dat", ios::binary);
    if (cadastros.is_open())
    {
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            string nome, cpf;
            int dia, mes, ano;
            cadastros >> nome;
            cadastros >> cpf;
            cadastros >> dia >> mes >> ano;
            pessoas[i] = new Pessoa(nome, cpf, dia, mes, ano);
        }
        cadastros.close();
    }
    else
    {
        cout << "Nenhum cadastro encontrado" << endl;
    }
}

void salvaDados(Pessoa *pessoas[])
{
    ofstream arq("qtRegistros.dat");
    arq << Pessoa::TAM;
    arq.close();

    ofstream cadastros("cadastros.dat", ios::binary);
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        cadastros << pessoas[i]->getNome() << endl;
        cadastros << pessoas[i]->getCPF() << endl;
        int dia, mes, ano;
        pessoas[i]->getDataNascimento(dia, mes, ano);
        cadastros << dia << " " << mes << " " << ano << endl;
    }
    cadastros.close();
}

void encerraPrograma(Pessoa *pessoas[])
{
    salvaDados(pessoas);
    cout << "Obrigado por utilizar o programa" << endl;
    apagaPessoas(pessoas);
}

int main()
{
    Pessoa *pessoas[MAX];
    Professor *professores[MAX];
    Aluno *alunos[MAX];
    carregaDados(pessoas);
    int aniversarioMes;
    float op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1.1:
            // cadastra professor
            setProfessor(professores, Professor::TAM);
            break;
        case 1.2:
            // cadastra aluno
            setAluno(alunos, Aluno::TAM);
            break;
        case 2.1:
            // lista professores
            listaPessoa(professores);
            break;
        case 2.2:
            // lista alunos
            listaPessoa(alunos);
            break;
        case 3.1:
            // procura professor por nome
            procuraPessoa(professores);
            break;
        case 3.2:
            // procura aluno por nome
            procuraPessoa(alunos);
            break;
        case 4.1:
            // pesquisa professor por cpf
            pesquisaCPF(professores);
            break;
        case 4.2:
            // pesquisa aluno por cpf
            pesquisaCPF(alunos);
            break;
        case 5.1:
            // exclui professor
            excluiPessoa(professores);
            break;
        case 5.2:
            // exclui aluno
            excluiPessoa(alunos);
            break;
        case 6.1:
            // apaga todos os professores
            apagaPessoas(professores);
            break;
        case 6.2:
            // apaga todos os alunos
            apagaPessoas(alunos);
            break;
        case 7.1:
            setAniversarioMes(aniversarioMes);
            break;
        case 7.2:
            // lista os professos aniversariantes do mes
            listaAniversariantesProfessores(professores, aniversarioMes);
            break;
        case 7.3:
            // lista os alunos aniversariantes do mes
            listaAniversariantesAlunos(alunos, aniversarioMes);
        }
        op = menu(); // Atualiza a opção
    }
    encerraPrograma(pessoas);
    return 0;
}
