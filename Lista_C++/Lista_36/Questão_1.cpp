#include <iostream>
using namespace std;

class Quadrado
{
    private:
        float lado;
    public:
        float getLado();
        void setLado(float lado);
        float calcularArea();
        float calcularPerimetro();
};

float Quadrado::getLado()
{
    return this->lado;
}

float Quadrado::calcularArea()
{
    return this->lado * this->lado;
}

float Quadrado::calcularPerimetro()
{
    return this->lado * 4;
}

void Quadrado::setLado(float lado)
{
    if(lado > 0)
    {
        this->lado = lado;
    }
    else
    {
        cout << "Valor invalido, definindo o lado como 0" << endl;
        this->lado = 0;
    }
}

int main() 
{
    int MAX = 5;
    Quadrado quadrados[MAX];
    for(int i = 0; i < MAX; i++)
    {
        float lado;
        cout << "Digite o lado do quadrado " << i + 1 << ": " << endl;
        cin >> lado;
        quadrados[i].setLado(lado);
    }
    cout << "Apresentacao dos quadrados: " << endl;
    for(int i = 0; i < MAX; i++)
    {
        cout << "----------------------" << endl;
        cout << "Quadrado " << i + 1 << endl;
        cout << "Lado: " << quadrados[i].getLado() << endl;
        cout << "Area: " << quadrados[i].calcularArea() << endl;
        cout << "Perimetro: " << quadrados[i].calcularPerimetro() << endl;
    }
    

}