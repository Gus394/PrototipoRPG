#include <iostream>
using namespace std;

struct Arma
{
    int min;
    int max;
};

struct Jogador
{
    int level;
    int hp;
    Arma arma;
};

struct Inimigo
{
    string nome;
    int hp;
    Arma arma;
};

struct Fase
{
    string nome;
    Inimigo ini[5];
};

template <typename MORREU>
bool morreu(MORREU x) {
    if (MORREU.hp <= 0) {
        return true;
    }
    return false;
}

template <typename AGRESSOR, typename ALVO>
ALVO ataque(AGRESSOR x, ALVO y) {
    return ALVO.hp - rand() % ((AGRESSOR.arma.max + 1) - AGRESSOR.arma.min) + AGRESSOR.arma.min;
}

void JogarFase(Jogador x, Fase y) {
    cout << y.nome << endl;
}

int main()
{
    srand(time(NULL));
    
    Arma faca = { 3, 4 };
    Arma lanca = { 1, 8 };
    Arma machado = { 4, 7 };
    Arma espada = { 3, 6 };

    Inimigo ini[5];
    
    ini[0] = {"goblin", 12, faca};
    ini[1] = {"ladino", 26, faca};
    ini[2] = {"goblino", 20, lanca};
    ini[3] = {"guerreiro", 14, machado};
    ini[4] = {"executor", 30, machado};

    Jogador jogador = { 1, 25, espada };

    Fase floresta = { "floresta", ini };
}