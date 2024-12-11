#include <iostream>
#include <typeinfo>
#include <cmath>
#define MAX 5
using namespace std;
int TAM = 0;
class FigGeo
{
protected:
    int quantidade;
    string cor;

public:
    FigGeo() : quantidade(0), cor("") {};
    ~FigGeo() {};
    void setQuantidade(int quantidade)
    {
        this->quantidade = quantidade;
    }
    void setCor(string cor)
    {
        this->cor = cor;
    }
    int getQuantidade()
    {
        return this->quantidade;
    }
    string getCor()
    {
        return this->cor;
    }
    virtual void leia();
    virtual void escreva() const = 0;
    virtual float area() const = 0;
    virtual float perimetro() const = 0;
};

class Circulo : public FigGeo
{
private:
    float raio;

public:
    Circulo() : FigGeo(), raio(0) {};
    Circulo(float raio) : FigGeo(), raio(raio) {};
    Circulo(float raio, string cor) : FigGeo(), raio(raio) { setCor(cor); };
    void setRaio(float raio)
    {
        this->raio = raio;
    }
    float getRaio()
    {
        return this->raio;
    }
    void leia() override
    {
        cout << "Digite o raio do circulo: ";
        cin >> raio;
    }
    void escreva() const override
    {
        cout << "Circulo de raio " << raio << " e area " << area() << " e perimetro " << perimetro() << endl;
    }
    float area() const override
    {
        return 3.14 * raio * raio;
    }
    float perimetro() const override
    {
        return 2 * 3.14 * raio;
    }
};

class Quadrado : public FigGeo
{
private:
    float lado;

public:
    Quadrado() : FigGeo(), lado(0) {};
    Quadrado(float lado) : FigGeo(), lado(lado) {};
    Quadrado(float lado, string cor) : FigGeo(), lado(lado) { setCor(cor); };
    void setLado(float lado)
    {
        this->lado = lado;
    }
    float getLado()
    {
        return this->lado;
    }
    void leia() override
    {
        cout << "Digite o lado do quadrado: ";
        cin >> lado;
    }
    void escreva() const override
    {
        cout << "Quadrado de lado " << lado << " e area " << area() << " e perimetro " << perimetro() << endl;
    }
    float area() const override
    {
        return lado * lado;
    }
    float perimetro() const override
    {
        return 4 * lado;
    }
};

class Triangulo : public FigGeo
{
private:
    float a;
    float b;
    float c;

public:
    Triangulo() : FigGeo(), a(0), b(0), c(0) {};
    Triangulo(float a, float b, float c) : FigGeo(), a(a), b(b), c(c) {};
    Triangulo(float a, float b, float c, string cor) : FigGeo(), a(a), b(b), c(c) { setCor(cor); };
    void setTriangulo(float a, float b, float c, string cor)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        setCor(cor);
    }
    float getA()
    {
        return this->a;
    }
    float getB()
    {
        return this->b;
    }
    float getC()
    {
        return this->c;
    }
    void leia() override
    {
        cout << "Digite o lado A do triangulo: ";
        cin >> a;
        cout << "Digite o lado B do triangulo: ";
        cin >> b;
        cout << "Digite o lado C do triangulo: ";
        cin >> c;
    }
    void escreva() const override
    {
        cout << "Triangulo de lados " << a << ", " << b << " e " << c << " e area " << area() << " e perimetro " << perimetro() << endl;
    }
    float perimetro() const override
    {
        return a + b + c;
    }
    float area() const override
    {
        float p = perimetro() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    bool valido();
};

bool Triangulo::valido()
{
    return (a < b + c && b < a + c && c < a + b);
}

int menu()
{
    cout << "0 – Sair do programa" << endl;
    cout << "1 – Círculos" << endl;
    cout << "2 - Quadrados" << endl;
    cout << "3 – Triângulos" << endl;
    cout << "Digite a opção desejada: ";
    int op;
    cin >> op;
    return op;
}

int menuSec()
{
    cout << "1 - Cadastrar figura" << endl;
    cout << "2 - Listar figuras" << endl;
    int op;
    cin >> op;
    return op;
}

void setFig(FigGeo *figuras[], int op)
{
    string cor;
    if (TAM < MAX)
    {
        switch (op)
        {
        case 1:
            float raio;
            figuras[TAM] = new Circulo();
            figuras[TAM]->leia();
            cout << "Digite a cor do circulo: ";
            cin >> cor;
            figuras[TAM]->setCor(cor);
            break;
        case 2:
            float lado;
            figuras[TAM] = new Quadrado();
            figuras[TAM]->leia();
            cout << "Digite a cor do quadrado: ";
            cin >> cor;
            figuras[TAM]->setCor(cor);
            break;
        case 3:
            float a, b, c;
            figuras[TAM] = new Triangulo();
            figuras[TAM]->leia();
            cout << "Digite a cor do triangulo: ";
            cin >> cor;
            figuras[TAM]->setCor(cor);
            break;
        }
        TAM++;
    }
    else
    {
        cout << "Memoria cheia" << endl;
    }
}

void lista(FigGeo *figuras[], int op)
{
    switch (op)
    {
    case 1:
        for (int i = 0; i < TAM; i++)
        {
            if (typeid(*figuras[i]) == typeid(Circulo))
            {
                figuras[i]->escreva();
            }
        }
        break;
    case 2:
        for (int i = 0; i < TAM; i++)
        {
            if (typeid(*figuras[i]) == typeid(Quadrado))
            {
                figuras[i]->escreva();
            }
        }
        break;
    case 3:
        for (int i = 0; i < TAM; i++)
        {
            if (typeid(*figuras[i]) == typeid(Triangulo))
            {
                figuras[i]->escreva();
            }
        }
        break;
    }
}

void limpaMemoria(FigGeo *figuras[])
{
    for (int i = 0; i < TAM; i++)
    {
        delete figuras[i];
    }
}

int main(void)
{
    FigGeo *figuras[MAX];
    int op = menu();
    int escolha;
    do
    {
        switch (op)
        {
        case 1:
            escolha = menuSec();
            if (escolha == 1)
                setFig(figuras, 1);
            else
                lista(figuras, 1);
            break;
        case 2:
            escolha = menuSec();
            if (escolha == 1)
                setFig(figuras, 2);
            else
                lista(figuras, 2);
            break;
        case 3:
            escolha = menuSec();
            if (escolha == 1)
                setFig(figuras, 3);
            else
                lista(figuras, 3);
            break;
        }
    } while (op != 0);
    limpaMemoria(figuras);
    return 0;
}
