#include <iostream>

using namespace std;

class Veiculo
{
protected:
    string modelo;
    int ano;

public:
    Veiculo() : modelo(""), ano(0) {};
    virtual void escreve() = 0;
};

class Carro : public Veiculo
{
private:
    string tracao;

public:
    Carro() : Veiculo(), tracao("") {};
    Carro(string modelo, int ano, string tracao)
    {
        this->modelo = modelo;
        this->ano = ano;
        this->tracao = tracao;
    }
    void escreve() override
    {
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Tracao: " << tracao << endl;
    }
};

class Moto : public Veiculo
{
private:
    int cilindradas;

public:
    Moto() : Veiculo(), cilindradas(0) {};
    Moto(string modelo, int ano, int cilindradas)
    {
        this->cilindradas = cilindradas;
        this->modelo = modelo;
        this->ano = ano;
    }
    void escreve() override
    {
        cout << "Modelo : " << modelo << endl;
        cout << "Ano :" << ano << endl;
        cout << "Cilindradas: " << cilindradas << endl;
    }
};


int main(void)
{
    Veiculo *veiculo[4];
    veiculo[0] = new Carro("Gol", 2020, "dianteira");
    veiculo[1] = new Carro();
    veiculo[2] = new Moto();
    veiculo[3] = new Moto("XL125", 2019, 125);

    for(Veiculo *veiculo: veiculo)
    {
        veiculo->escreve();
    }
}