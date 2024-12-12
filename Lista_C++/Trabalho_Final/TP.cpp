#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <typeinfo>

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
    virtual ~Pessoa() = default;
    void setNome(const string &nome);
    string getNome();
    void setDataNascimento(int dia, int mes, int ano);
    void getDataNascimento(int &dia, int &mes, int &ano);
    void setCPF(const string &cpf);
    string getCPF();
    virtual void escreve() = 0;
    virtual string getEspecifico() = 0;
    virtual int getTipo() = 0;
};

class Aluno : public Pessoa
{
private:
    string matricula;

public:
    Aluno() : Pessoa(), matricula("") { TAM++; };
    Aluno(string nome, string cpf, int dia, int mes, int ano, string matricula) : Pessoa(nome, cpf, dia, mes, ano), matricula(matricula) {};
    void setMatricula(const string &matricula)
    {
        this->matricula = matricula;
    }
    string getMatricula()
    {
        return this->matricula;
    }
    void escreve() override
    {
        cout << "----------------------" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << dataNascimento.getDia() << "/" << dataNascimento.getMes() << "/" << dataNascimento.getAno() << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Matricula: " << matricula << endl;
        cout << "----------------------" << endl
             << endl;
    }
    string getEspecifico() override
    {
        return matricula;
    }
    int getTipo() override
    {
        return 1;
    }
};

class Professor : public Pessoa
{
private:
    string titulo;

public:
    Professor() : Pessoa(), titulo("") {};
    Professor(string nome, string cpf, int dia, int mes, int ano, string titulo) : Pessoa(nome, cpf, dia, mes, ano), titulo(titulo) {};
    void setTitulo(const string &titulo)
    {
        this->titulo = titulo;
    }
    string getTitulo()
    {
        return this->titulo;
    }
    void setProfessor(const string &nome, const string &cpf, const string &titulo, int dia, int mes, int ano)
    {
        setNome(nome);
        setCPF(cpf);
        setDataNascimento(dia, mes, ano);
        this->titulo = titulo;
    }
    void escreve() override
    {
        cout << "----------------------" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << dataNascimento.getDia() << "/" << dataNascimento.getMes() << "/" << dataNascimento.getAno() << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "----------------------" << endl
             << endl;
    }
    string getEspecifico() override
    {
        return titulo;
    }
    int getTipo() override
    {
        return 2;
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

void leNome(string &nome, string mensagem)
{
    cout << "Digite o nome " << mensagem << ": ";
    cin.ignore();
    getline(cin, nome);
}
void setNomePessoa(string &nome, string mensagem)
{
    leNome(nome, mensagem);
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
        cin.clear();
        cin.ignore();
    } while (erro);
}

void leCPF(string &cpf, string mensagem)
{
    bool erro;
    do
    {
        cout << "Digite o CPF " << mensagem << ": ";
        cin >> cpf;
        erro = (cpf.size() != 11);
        if (erro)
            cout << "CPF invalido, tente novamente" << endl;
    } while (erro);
}

void setCPF(string &cpf, string mensagem)
{
    leCPF(cpf, mensagem);
}

void leMatricula(string &matricula)
{
    cout << "Digite a matricula do aluno: ";
    cin >> matricula;
}

void setProfessorTitulo(string &titulo)
{
    bool erro;
    do
    {
        cout << "Digite o titulo do professor[Especialista, Mestre ou Doutor]: ";
        cin >> titulo;
        erro = titulo != "Especialista" && titulo != "Mestre" && titulo != "Doutor";
        if (erro)
            cout << "Titulo invalido, tente novamente" << endl;
    } while (erro);
}

void setPessoa(Pessoa *pessoas[], int posicao, int escolha)
{
    if (Pessoa::TAM < MAX)
    {
        string nome, cpf;
        int dia, mes, ano;
        string titulo;
        string matricula;
        switch (escolha)
        {
        case 1:
            setNomePessoa(nome, "do aluno");
            leData(dia, mes, ano);
            setCPF(cpf, "do aluno");
            leMatricula(matricula);
            pessoas[posicao] = new Aluno(nome, cpf, dia, mes, ano, matricula);
            break;
        case 2:
            setNomePessoa(nome, "do professor");
            leData(dia, mes, ano);
            setCPF(cpf, "do professor");
            setProfessorTitulo(titulo);
            pessoas[posicao] = new Professor(nome, cpf, dia, mes, ano, titulo);
            break;
        }
        Pessoa::TAM++;
    }
}

void Data::setData(int dia, int mes, int ano)
{
    // Array de dias por mês (ano não bissexto)
    int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica ano bissexto
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    {
        diasNoMes[1] = 29;
    }

    // Validação da data
    if (ano > 0 && mes > 0 && mes <= 12 &&
        dia > 0 && dia <= diasNoMes[mes - 1])
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
        cin.ignore();
        cin >> op;
        switch (caso) // caso 1: menu principal, caso 2: menu secundário
        {
        case 1:
            invalido = (op < 0 || op > 7);
            break;
        case 2:
            invalido = (op < 0 || op > 3);
        }
        if (invalido)
            cout << "Opcao invalida, tente novamente" << endl;
    } while (invalido);
    return op;
}

int menuSecundario(int op, bool &voltaMenu)
{
    int subOp;
    cout << endl;
    switch (op)
    {
    case 1: // menu de cadastro
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Cadastrar Professor " << endl;
        cout << "2 - Cadastrar Aluno" << endl;
        subOp = leOpcao(2);
        break;
    case 2: // menu de listagem
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Listar Professores" << endl;
        cout << "2 - Listar Alunos" << endl;
        subOp = leOpcao(2);
        break;
    case 3: // menu de pesquisa
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Pesquisar Professor por nome" << endl;
        cout << "2 - Pesquisar Aluno por nome" << endl;
        subOp = leOpcao(2);
        break;
    case 4: // menu de pesquisa
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Pesquisar Professor por CPF" << endl;
        cout << "2 - Pesquisar Aluno por CPF" << endl;
        subOp = leOpcao(2);
        break;
    case 5: // menu de exclusão
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Excluir Professor(pelo CPF)" << endl;
        cout << "2 - Excluir Aluno(pelo CPF)" << endl;
        subOp = leOpcao(2);
        break;
    case 6: // menu de exclusão total
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Apagar todos os Professores" << endl;
        cout << "2 - Apagar todos os Alunos" << endl;
        subOp = leOpcao(2);
        break;
    case 7: // menu de aniversariantes
        cout << "0 - Voltar ao menu anterior" << endl;
        cout << "1 - Informar mes a ser pesquisado" << endl;
        cout << "2 - Listar Aniversariantes do mes" << endl;
        subOp = leOpcao(2);
        break;
    }
    if (subOp == 0)
    {
        voltaMenu = true;
    }
    return op * 10 + subOp; // soma os valores para formar a opção
}

int menu()
{
    float op;
    bool retornaMenu = false;
    do
    {

        cout << endl
             << "0 - Sair do programa" << endl;
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
    cout << endl;
    return op;
}

void listaPessoa(Pessoa *pessoas[], int escolha)
{
    bool encontrado = false;
    // Varre o vetor de pessoas e imprime os dados de acordo com a escolha
    // 1 lista alunos, 2 lista professores
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        if (pessoas[i] != nullptr)
        {
            if (typeid(*pessoas[i]) == typeid(Aluno) && escolha == 1)
            {
                pessoas[i]->escreve();
                encontrado = true;
            }
            else if (typeid(*pessoas[i]) == typeid(Professor) && escolha == 2)
            {
                pessoas[i]->escreve();
                encontrado = true;
            }
        }
    }
    if (!encontrado)
    {
        if (escolha == 1)
        {
            cout << "Nenhum aluno cadastrado" << endl;
        }
        else
        {
            cout << "Nenhum professor cadastrado" << endl;
        }
    }
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

void procuraPessoa(Pessoa *pessoas[], int escolha)
{
    bool encontrado = false;
    string nomeProcurado;
    // Seleciona o texto a depender da escolha, 1 para aluno, 2 para professor
    if (escolha == 1)
    {
        setNomePessoa(nomeProcurado, "do aluno");
    }
    else
    {
        setNomePessoa(nomeProcurado, "do professor");
    }
    for (int i = 0; i < Pessoa::TAM; i++)
    {
        //Varre o array procurando pessoas com o nome procurado
        if (pessoas[i] != nullptr)
        {
            if (typeid(*pessoas[i]) == typeid(Aluno) && escolha == 1)
            {
                if (comparaNomes(pessoas[i]->getNome(), nomeProcurado))
                {
                    pessoas[i]->escreve();
                    encontrado = true;
                }
            }
            else if (typeid(*pessoas[i]) == typeid(Professor) && escolha == 2)
            {
                if (comparaNomes(pessoas[i]->getNome(), nomeProcurado))
                {
                    pessoas[i]->escreve();
                    encontrado = true;
                }
            }
        }
    }
    if (!encontrado && escolha == 1)
    {
        cout << "Nenhum aluno encontrado com o nome: " << nomeProcurado << endl;
    }
    else if (!encontrado && escolha == 2)
    {
        cout << "Nenhum professor encontrado com o nome: " << nomeProcurado << endl;
    }
}

void pesquisaCPF(Pessoa *pessoas[], int escolha)
{
    // Função que pesquisa uma pessoa pelo CPF
    bool encontrado = false;
    string cpfProcurado;
    // Seleciona o texto a depender da escolha, 1 para aluno, 2 para professor
    if (escolha == 1)
    {
        setCPF(cpfProcurado, "do aluno");
    }
    else
    {
        setCPF(cpfProcurado, "do professor");
    }
    int i = 0;
    // Itera sobre o vetor de pessoas até encontrar a pessoa com o CPF procurado
    while (i < Pessoa::TAM && !encontrado)
    {
        if (pessoas[i] != nullptr)
        {
            if (typeid(*pessoas[i]) == typeid(Aluno) && escolha == 1)
            {
                if (pessoas[i]->getCPF() == cpfProcurado)
                {
                    pessoas[i]->escreve();
                    encontrado = true;
                }
            }
            else if (typeid(*pessoas[i]) == typeid(Professor) && escolha == 2)
            {
                if (pessoas[i]->getCPF() == cpfProcurado)
                {
                    pessoas[i]->escreve();
                    encontrado = true;
                }
            }
            i++;
        }
    }
    if (!encontrado && escolha == 1)
    {
        cout << "Nenhum aluno encontrado com o CPF: " << cpfProcurado << endl;
    }
    else if (!encontrado && escolha == 2)
    {
        cout << "Nenhum professor encontrado com o CPF: " << cpfProcurado << endl;
    }
}

void shiftPessoas(Pessoa *pessoas[], int posicao)
{
    // Função tapa o buraco deixado pela exclusão de uma pessoa
    for (int i = posicao; i < Pessoa::TAM; i++)
    {
        pessoas[i] = pessoas[i + 1];
    }
    pessoas[Pessoa::TAM - 1] = nullptr; // Definir o último elemento como nullptr
}

void excluiPessoa(Pessoa *pessoas[], int escolha)
{
    bool encontrado = false;
    string CPF;
    // Seleciona o texto a depender da escolha, 1 para aluno, 2 para professor
    if (escolha == 1)
    {
        setCPF(CPF, "do aluno");
    }
    else
    {
        setCPF(CPF, "do professor");
    }
    int i = 0, tam = Pessoa::TAM;
    while (i < tam && !encontrado)
    {
        // Itera sobre o vetor de pessoas até encontrar a pessoa com o CPF procurado
        if (pessoas[i] != nullptr)
        {
            //Exclui a pessoa e chama a função shiftPessoas para tapar o buraco
            if (typeid(*pessoas[i]) == typeid(Aluno) && escolha == 1)
            {
                if (pessoas[i]->getCPF() == CPF)
                {
                    cout << "Aluno excluido: " << pessoas[i]->getNome() << endl;
                    delete pessoas[i];
                    Pessoa::TAM--;
                    shiftPessoas(pessoas, i);
                    encontrado = true;
                }
            }
            else if (typeid(*pessoas[i]) == typeid(Professor) && escolha == 2)
            {
                if (pessoas[i]->getCPF() == CPF)
                {
                    cout << "Professor excluido: " << pessoas[i]->getNome() << endl;
                    delete pessoas[i];
                    Pessoa::TAM--;
                    shiftPessoas(pessoas, i);
                    encontrado = true;
                }
            }
            i++;
        }
    }
    if (!encontrado && escolha == 1)
    {
        cout << "Nenhum aluno encontrado com o CPF: " << CPF << endl;
    }
    else if (!encontrado && escolha == 2)
    {
        cout << "Nenhum professor encontrado com o CPF: " << CPF << endl;
    }
}

void apagaPessoas(Pessoa *pessoas[], int escolha)
{
    int i = 0;
    switch (escolha)
    {
    case 1: // Apaga todos os alunos
        while (i < Pessoa::TAM)
        {
            if (typeid(*pessoas[i]) == typeid(Aluno))
            {
                delete pessoas[i];
                shiftPessoas(pessoas, i);
            }
            else
            {
                i++;
            }
        }
        cout << "Todos os alunos foram excluidos" << endl;
        break;

    case 2: // Apaga todos os professores
        while (i < Pessoa::TAM)
        {
            if (typeid(*pessoas[i]) == typeid(Professor))
            {
                delete pessoas[i];
                shiftPessoas(pessoas, i);
            }
            else
            {
                i++;
            }
        }
        cout << "Todos os professores foram excluidos" << endl;
        break;

    case 3: // Apaga todos os registros
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            delete pessoas[i];
            pessoas[i] = nullptr;
        }
        Pessoa::TAM = 0;
        cout << "Todos os registros foram excluidos" << endl;
        break;
    }
}

void setAniversarioMes(int &aniversarioMes)
{
    // Função que solicita o mês a ser pesquisado
    bool erro;
    do
    {
        cout << "Digite o mes a ser pesquisado: ";
        cin >> aniversarioMes;
        erro = aniversarioMes < 1 || aniversarioMes > 12;
        if (erro)
            cout << "Mes invalido, tente novamente" << endl;
    } while (erro);
}

void listaAniversarios(Pessoa *pessoas[], int aniversarioMes)
{
    //Função que lista os aniversariantes do mês
    bool encontrado = false;
    if (aniversarioMes > 0 && aniversarioMes < 13)
    {
        cout << "Aniversariantes do mes " << aniversarioMes << endl;
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            if (pessoas[i] != nullptr)
            {
                int dia, mes, ano;
                pessoas[i]->getDataNascimento(dia, mes, ano);
                if (mes == aniversarioMes)
                {
                    pessoas[i]->escreve();
                    encontrado = true;
                }
            }
        }
        if (!encontrado)
        {
            cout << "Nenhum aniversariante encontrado no mes " << aniversarioMes << endl;
        }
    }
    else
        cout << "Digite um mes antes de prosseguir" << endl;
}

void carregaDados(Pessoa *pessoas[])
{
    //Carrega o TAM dos arquivos
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
    //Carrega as pessoas do arquivo 
    ifstream cadastros("cadastros.dat", ios::binary);
    if (cadastros.is_open())
    {
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            int escolha;
            cadastros >> escolha;
            string nome, cpf;
            int dia, mes, ano;
            if (escolha == 1)
            {
                string matricula;
                cadastros >> nome;
                cadastros >> cpf;
                cadastros >> dia >> mes >> ano;
                cadastros >> matricula;
                pessoas[i] = new Aluno(nome, cpf, dia, mes, ano, matricula);
            }
            else
            {
                string titulo;
                cadastros >> nome;
                cadastros >> cpf;
                cadastros >> dia >> mes >> ano;
                cadastros >> titulo;
                pessoas[i] = new Professor(nome, cpf, dia, mes, ano, titulo);
            }
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
    //salva o TAM no arquivo qtRegistros.dat
    ofstream arq("qtRegistros.dat");
    if (!arq.is_open())
        throw std::runtime_error("Não foi possível abrir o arquivo qtRegistros.dat");

    arq << Pessoa::TAM;
    arq.close();

    //salva os dados das pessoas no arquivo cadastros.dat
    ofstream cadastros("cadastros.dat", ios::binary);
    if (!cadastros.is_open())
        throw std::runtime_error("Não foi possível abrir o arquivo cadastros.dat");

    try
    {
        for (int i = 0; i < Pessoa::TAM; i++)
        {
            cadastros << pessoas[i]->getTipo() << endl;
            cadastros << pessoas[i]->getNome() << endl;
            cadastros << pessoas[i]->getCPF() << endl;
            int dia, mes, ano;
            pessoas[i]->getDataNascimento(dia, mes, ano);
            cadastros << dia << " " << mes << " " << ano << endl;
            cadastros << pessoas[i]->getEspecifico() << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "Erro ao salvar dados: " << e.what() << endl;
    }

    cadastros.close();
}

void encerraPrograma(Pessoa *pessoas[])
{
    //Função responsavel por encerrar o programa corretamente
    salvaDados(pessoas);
    cout << "Obrigado por utilizar o programa" << endl;
    apagaPessoas(pessoas, 3);
}

int main()
{
    Pessoa *pessoas[MAX];
    carregaDados(pessoas);
    int aniversarioMes;
    int op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 11:
            setPessoa(pessoas, Pessoa::TAM, 2);
            break;
        case 12:
            // cadastra aluno
            setPessoa(pessoas, Pessoa::TAM, 1);
            break;
        case 21:
            // lista professores
            try:
                listaPessoa(pessoas, 2);
            catch (const std::exception &e)
            {
                cout << "Erro ao listar professores: " << e.what() << endl;
            }
            break;
        case 22:
            // lista alunos
            try:
                listaPessoa(pessoas, 1);
            catch (const std::exception &e)
            {
                cout << "Erro ao listar alunos: " << e.what() << endl;
            }
            break;
        case 31:
            // procura professor por nome
            procuraPessoa(pessoas, 2);
            break;
        case 32:
            // procura aluno por nome
            procuraPessoa(pessoas, 1);
            break;
        case 41:
            // pesquisa professor por cpf
            pesquisaCPF(pessoas, 2);
            break;
        case 42:
            // pesquisa aluno por cpf
            pesquisaCPF(pessoas, 1);
            break;
        case 51:
            // exclui professor
            excluiPessoa(pessoas, 2);
            break;
        case 52:
            // exclui aluno
            excluiPessoa(pessoas, 1);
            break;
        case 61:
            // apaga todos os professores
            apagaPessoas(pessoas, 2);
            break;
        case 62:
            // apaga todos os alunos
            try
            {
                apagaPessoas(pessoas, 1);
            }
            catch (const std::exception &e)
            {
                cout << "Erro ao apagar dados dos alunos: " << e.what() << endl;
            }
            break;
        case 71:
            setAniversarioMes(aniversarioMes);
            break;
        case 72:
            // lista os professos aniversariantes do mes
            listaAniversarios(pessoas, aniversarioMes);
        }
        op = menu(); // Atualiza a opção
    }
    encerraPrograma(pessoas);
    return 0;
}
