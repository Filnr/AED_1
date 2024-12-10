#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
    srand(time(0));
    string atividades[] = {"Estudar", "Brincar", "Jogar", "Trabalhar", "Dormir", "Comer"};
    cout << "Lançando um dado..." << endl;
    int dado = rand() % 6;
    cout << "Dado sorteado: "<< dado << endl << "Atividade: " << atividades[dado] << endl;
}