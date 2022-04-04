#include <iostream> // Trabalho feito por Gustavo Coelho e João Vitor Custódio na disciplina de Algoritmos e Programação II
//#include <time.h>
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
	int hp{}; // Chaves para corrigir o aviso "A variável não foi inicializada. Sempre inicialize uma variável de membro (type.6)."
	Arma arma{};
};

struct Fase
{
	string nome;
	Inimigo ini[5];
};

template <typename MORREU>
bool morreu(MORREU x) {
	if (x.hp <= 0) {
		return true;
	}
	return false;
}

template <typename AGRESSOR, typename ALVO>
int ataque(AGRESSOR x, ALVO y) {
	return y.hp - (rand() % (x.arma.max + 1 - x.arma.min) + x.arma.min);
}

void jogarFase(Jogador& jogador, Fase fase) { // Jogador por referência para salvar as mudanças após a fase
	
	Inimigo inimigo;
	cout << fase.nome << "\n\n";

	for (int i = 0; i < 5; i++) {
		inimigo.arma = fase.ini[i].arma;
		inimigo.hp = fase.ini[i].hp;
		cout << "Encontrou o inimigo " << fase.ini[i].nome << "!\n\n";

		while (morreu(inimigo) == false && morreu(jogador) == false) {
			inimigo.hp = ataque(jogador, inimigo);
			jogador.hp = ataque(inimigo, jogador);
			
			cout << "Jogador atacou: " << fase.ini[i].nome << " ficou com " << inimigo.hp << " de vida.\n";
			cout << fase.ini[i].nome << " atacou: " << "Jogador ficou com " << jogador.hp << " de vida. ";
			system("pause");
		}
		if (morreu(jogador)) {
			cout << "\nMorreu...\n";
			return;
		}
		cout << "Inimigo derrotado.\n\n";
	}
	cout << " - Fase Completa -\n";
}

int main()
{
	srand(time(NULL));

	Arma faca = { 3, 4 };
	Arma lanca = { 1, 8 };
	Arma machado = { 4, 7 };
	Arma espada = { 3, 6 };
	
	Jogador jogador = { 1, 100, espada };
	
	Fase floresta;
	floresta.nome = "Floresta";
	floresta.ini[0] = { "Goblin", 12, faca };
	floresta.ini[1] = { "Orc", 18, faca };
	floresta.ini[2] = { "Guarda", 20, lanca };
	floresta.ini[3] = { "Esqueleto", 14, machado };
	floresta.ini[4] = { "Executor", 30, machado };

	jogarFase(jogador, floresta);
}