
#include <iostream>
#include <string>
#include <vector> // Incluindo a biblioteca de vetores dinâmicos
#include <limits> // Necessário para limpar o buffer do cin

using namespace std;

// FUNÇÃO REUTILIZÁVEL: Agora recebe vectors por referência constante (evita cópia desnecessária na memória)
int calcular(const vector<int>& rA, const vector<int>& rB, const vector<int>& pA, const vector<int>& pB) {
    int total = 0;
    // O loop se adapta dinamicamente ao tamanho do vetor de jogos
    for (size_t i = 0; i < rA.size(); i++) {
        if (pA[i] == rA[i] && pB[i] == rB[i]) {
            total += 10; // Placar exato
        } else if ((rA[i] > rB[i] && pA[i] > pB[i]) || (rB[i] > rA[i] && pB[i] > pB[i])) {
            total += 5;  // Vitória/Derrota acertada
        } else if (rA[i] == rB[i] && pA[i] == pB[i]) {
            total += 2;  // Empate acertado (mas não o placar exato)
        }
    }
    return total;
}

// FUNÇÃO AUXILIAR: Números inteiros maiores ou iguais a zero
int obterGolsValidos(string mensagem) {
    int valor;
    while (true) {
        cout << mensagem;
        cin >> valor;

        // Validação 1: O usuário digitou um número inteiro?
        // Validação 2: O número de gols é maior ou igual a zero?
        if (cin.fail() || valor < 0) {
            cin.clear(); // Limpa o estado de erro do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida do buffer
            cout << "[ERRO] Entrada inválida! Digite um número inteiro maior ou igual a zero.\n" << endl;
        } else {
            return valor;
        }
    }
}

int main() {
    // 1. VETORES DINÂMICOS (Substituindo os arrays estáticos por std::vector)
    vector<string> timesA = {"BRA", "RSA", "FRA", "GER"};
    vector<string> timesB = {"EGT", "MAR", "AGT", "COS"};
    vector<int> golsReaisA = {3, 1, 1, 4};
    vector<int> golsReaisB = {0, 1, 2, 2};

    // Determinando o tamanho dinamicamente baseado nos vetores base
    size_t numJogos = timesA.size();

    // Inicializando os vetores dinâmicos para receber os palpites (alocando espaço com resize)
    vector<int> pLeonamA(numJogos), pLeonamB(numJogos);
    vector<int> pLucasA(numJogos),  pLucasB(numJogos);
    vector<int> pMariaA(numJogos),  pMariaB(numJogos);

    // 2. ENTRADA DE DADOS COM VALIDAÇÃO
    cout << "=== ENTRADA DE PALPITES DO BOLÃO ===" << endl;
    
    // Palpites do Leonam
    cout << "\n--- Palpites do Leonam ---" << endl;
    for (size_t i = 0; i < numJogos; i++) {
        cout << "Jogo: " << timesA[i] << " x " << timesB[i] << endl;
        pLeonamA[i] = obterGolsValidos("Gols do " + timesA[i] + ": ");
        pLeonamB[i] = obterGolsValidos("Gols do " + timesB[i] + ": ");
    }

    // Palpites do Lucas
    cout << "\n--- Palpites do Lucas ---" << endl;
    for (size_t i = 0; i < numJogos; i++) {
        cout << "Jogo: " << timesA[i] << " x " << timesB[i] << endl;
        pLucasA[i] = obterGolsValidos("Gols do " + timesA[i] + ": ");
        pLucasB[i] = obterGolsValidos("Gols do " + timesB[i] + ": ");
    }

    // Palpites da Maria
    cout << "\n--- Palpites da Maria ---" << endl;
    for (size_t i = 0; i < numJogos; i++) {
        cout << "Jogo: " << timesA[i] << " x " << timesB[i] << endl;
        pMariaA[i] = obterGolsValidos("Gols do " + timesA[i] + ": ");
        pMariaB[i] = obterGolsValidos("Gols do " + timesB[i] + ": ");
    }

    // 3. CÁLCULO DOS PONTOS
    int pontosLeonam = calcular(golsReaisA, golsReaisB, pLeonamA, pLeonamB);
    int pontosLucas  = calcular(golsReaisA, golsReaisB, pLucasA, pLucasB);
    int pontosMaria  = calcular(golsReaisA, golsReaisB, pMariaA, pMariaB);

    // 4. EXIBIÇÃO DOS RESULTADOS REAIS
    cout << "\n=== PLACAR DOS JOGOS REAIS ===" << endl;
    for (size_t i = 0; i < numJogos; i++) {
        cout << timesA[i] << " " << golsReaisA[i] << " x " << golsReaisB[i] << " " << timesB[i] << endl;
    }

    // 5. RANKING DO BOLÃO

    if (pontosLeonam >= pontosLucas && pontosLucas >= pontosMaria) {
        cout << "1º Lugar: Leonam -> " << pontosLeonam << "\n2º Lugar: Lucas -> " << pontosLucas << "\n3º Lugar: Maria -> " << pontosMaria << endl;
    } 
    else if (pontosLeonam >= pontosMaria && pontosMaria >= pontosLucas) {
        cout << "1º Lugar: Leonam -> " << pontosLeonam << "\n2º Lugar: Maria -> " << pontosMaria << "\n3º Lugar: Lucas -> " << pontosLucas << endl;
    } 
    else if (pontosLucas >= pontosLeonam && pontosLeonam >= pontosMaria) {
        cout << "1º Lugar: Lucas -> " << pontosLucas << "\n2º Lugar: Leonam -> " << pontosLeonam << "\n3º Lugar: Maria -> " << pontosMaria << endl;
    } 
    else if (pontosLucas >= pontosMaria && pontosMaria >= pontosLeonam) {
        cout << "1º Lugar: Lucas -> " << pontosLucas << "\n2º Lugar: Maria -> " << pontosMaria << "\n3º Lugar: Leonam -> " << pontosLeonam << endl;
    } 
    else if (pontosMaria >= pontosLeonam && pontosLeonam >= pontosLucas) {
        cout << "1º Lugar: Maria -> " << pontosMaria << "\n2º Lugar: Leonam -> " << pontosLeonam << "\n3º Lugar: Lucas -> " << pontosLucas << endl;
    } 
    else { 
        cout << "1º Lugar: Maria -> " << pontosMaria << "\n2º Lugar: Lucas -> " << pontosLucas << "\n3º Lugar: Leonam -> " << pontosLeonam << endl;
    }

    return 0;
}