#include <iostream>
#include <string>
#include <vector> 
#include <limits> 

using namespace std;

// FUNÇÃO AUXILIAR: Mantida exatamente igual à sua original para validar a entrada de gols
int obterGolsValidos(string mensagem) {
    int valor;
    while (true) {
        cout << mensagem;
        cin >> valor;

        if (cin.fail() || valor < 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "[ERRO] Entrada inválida! Digite um número inteiro maior ou igual a zero.\n" << endl;
        } else {
            return valor;
        }
    }
}

// 1. CLASSE JOGO (Com placar real)
class Jogo {
public:
    string timeA;
    string timeB;
    int golsReaisA;
    int golsReaisB;

    Jogo() : timeA(""), timeB(""), golsReaisA(0), golsReaisB(0) {}
};

// 2. CLASSE APOSTADOR (Com nome, palpites dinâmicos e pontuação)
class Apostador {
public:
    string nome;
    int pontuacaoTotal;
    int* palpitesA; // Vetor dinâmico (alocação manual com new[])
    int* palpitesB; // Vetor dinâmico (alocação manual com new[])
    int numJogos;

    // Construtor
    Apostador(string n, int qtdJogos) {
        nome = n;
        pontuacaoTotal = 0;
        numJogos = qtdJogos;
        palpitesA = new int[qtdJogos]; // Alocação dinâmica na memória Heap
        palpitesB = new int[qtdJogos];
    }

    // Destrutor: Obrigatório para liberar a memória alocada e evitar Memory Leak
    ~Apostador() {
        delete[] palpitesA;
        delete[] palpitesB;
    }

    // Método para calcular os pontos (Sua lógica original adaptada para a classe)
    void calcularPontos(const Jogo jogosReais[]) {
        pontuacaoTotal = 0;
        for (int i = 0; i < numJogos; i++) {
            int rA = jogosReais[i].golsReaisA;
            int rB = jogosReais[i].golsReaisB;
            int pA = palpitesA[i];
            int pB = palpitesB[i];

            if (pA == rA && pB == rB) {
                pontuacaoTotal += 10; // Placar exato
            } else if ((rA > rB && pA > pB) || (rB > rA && pB > pB)) {
                pontuacaoTotal += 5;  // Vitória/Derrota acertada
            } else if (rA == rB && pA == pB) {
                pontuacaoTotal += 2;  // Empate acertado
            }
        }
    }
};

int main() {
    const int NUM_JOGOS = 4;
    
    // REQUISITO: Vetor estático para os 4 jogos reais
    Jogo jogos[NUM_JOGOS];
    jogos[0].timeA = "BRA"; jogos[0].timeB = "EGT";
    jogos[1].timeA = "RSA"; jogos[1].timeB = "MAR";
    jogos[2].timeA = "FRA"; jogos[2].timeB = "AGT";
    jogos[3].timeA = "GER"; jogos[3].timeB = "COS";

    // Inicializando os 3 apostadores fixos exigidos
    Apostador* apostadores[3] = {
        new Apostador("Leonam", NUM_JOGOS),
        new Apostador("Lucas", NUM_JOGOS),
        new Apostador("Maria", NUM_JOGOS)
    };

    int opcao;
    bool resultadosCadastrados = false;
    bool palpitesCadastrados = false;

    do {
        cout << "\n================ MENU DO BOLÃO ================" << endl;
        cout << "1. Cadastrar Resultados Reais dos Jogos" << endl;
        cout << "2. Cadastrar Palpites dos Apostadores" << endl;
        cout << "3. Calcular Pontuações" << endl;
        cout << "4. Exibir Ranking Final" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "\n=== CADASTRO DOS RESULTADOS REAIS ===" << endl;
                for (int i = 0; i < NUM_JOGOS; i++) {
                    cout << "Jogo: " << jogos[i].timeA << " x " << jogos[i].timeB << endl;
                    jogos[i].golsReaisA = obterGolsValidos("Gols do " + jogos[i].timeA + ": ");
                    jogos[i].golsReaisB = obterGolsValidos("Gols do " + jogos[i].timeB + ": ");
                }
                resultadosCadastrados = true;
                cout << "\n[OK] Resultados cadastrados com sucesso!" << endl;
                break;

            case 2:
                cout << "\n=== CADASTRO DOS PALPITES ===" << endl;
                for (int a = 0; a < 3; a++) {
                    cout << "\n--- Palpites do(a) " << apostadores[a]->nome << " ---" << endl;
                    for (int i = 0; i < NUM_JOGOS; i++) {
                        cout << "Jogo: " << jogos[i].timeA << " x " << jogos[i].timeB << endl;
                        apostadores[a]->palpitesA[i] = obterGolsValidos("Gols do " + jogos[i].timeA + ": ");
                        apostadores[a]->palpitesB[i] = obterGolsValidos("Gols do " + jogos[i].timeB + ": ");
                    }
                }
                palpitesCadastrados = true;
                break;

            case 3:
                if (!resultadosCadastrados || !palpitesCadastrados) {
                    cout << "[AVISO] Cadastre os resultados e palpites primeiro antes de calcular!" << endl;
                } else {
                    for (int a = 0; a < 3; a++) {
                        apostadores[a]->calcularPontos(jogos);
                    }
                    cout << "\n[OK] Pontuações calculadas com sucesso!" << endl;
                }
                break;

            case 4:
                if (!resultadosCadastrados || !palpitesCadastrados) {
                    cout << "[AVISO] Preencha os dados no menu antes de ver o ranking." << endl;
                    break;
                }

                // REQUISITO: Exibir o Placar Real antes do ranking (igual ao seu original)
                cout << "\n=== PLACAR DOS JOGOS REAIS ===" << endl;
                for (int i = 0; i < NUM_JOGOS; i++) {
                    cout << jogos[i].timeA << " " << jogos[i].golsReaisA << " x " 
                         << jogos[i].golsReaisB << " " << jogos[i].timeB << endl;
                }

                // REQUISITO: Ordenação do Ranking (Algoritmo Bubble Sort para ordenar os ponteiros dos apostadores)
                for (int i = 0; i < 2; i++) {
                    for (int j = i + 1; j < 3; j++) {
                        if (apostadores[i]->pontuacaoTotal < apostadores[j]->pontuacaoTotal) {
                            Apostador* temp = apostadores[i];
                            apostadores[i] = apostadores[j];
                            apostadores[j] = temp;
                        }
                    }
                }

                cout << "\n=== RANKING DO BOLÃO ===" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << "º Lugar: " << apostadores[i]->nome 
                         << " -> " << apostadores[i]->pontuacaoTotal << " pontos" << endl;
                }
                break;

            case 0:
                cout << "Saindo do sistema do Bolão..." << endl;
                break;

            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (opcao != 0);

    // Liberando a memória dos objetos apostadores criados com 'new'
    for (int i = 0; i < 3; i++) {
        delete apostadores[i]; 
    }

    return 0;
}