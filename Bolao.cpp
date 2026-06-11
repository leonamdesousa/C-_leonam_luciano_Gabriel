
#include <iostream>
#include <string>

using namespace std;

// FUNÇÃO: Calcula os pontos de um apostador
int calcular(int rA[], int rB[], int pA[], int pB[]) {
    int total = 0;
    for (int i = 0; i < 4; i++) {
        if (pA[i] == rA[i] && pB[i] == rB[i]) total += 10; // Placar exato
        else if ((rA[i] > rB[i] && pA[i] > pB[i]) || (rB[i] > rA[i] && pB[i] > pA[i])) total += 5; // Vitória
        else if (rA[i] == rB[i] && pA[i] == pB[i]) total += 2; // Empate
    }
    return total;
}

int main() {
    // 1. DADOS DOS TIMES E RESULTADOS REAIS
    string timesA[] = {"BRA", "RSA", "FRA", "GER"}, timesB[] = {"EGT", "MAR", "AGT", "COS"};
    int golsReaisA[] = {3, 1, 1, 4}, golsReaisB[] = {0, 1, 2, 2};

    // 2. PALPITES 
    int pLeonamA[] = {2, 0, 1, 2}, pLeonamB[] = {1, 0, 0, 0};
    int pLucasA[]  = {1, 1, 0, 1}, pLucasB[]  = {0, 1, 2, 1};
    int pMariaA[]  = {2, 1, 0, 3}, pMariaB[]  = {1, 1, 2, 0};

    // 3. VARIÁVEIS SIMPLES PARA OS PONTOS
    int pontosLeonam = calcular(golsReaisA, golsReaisB, pLeonamA, pLeonamB);
    int pontosLucas  = calcular(golsReaisA, golsReaisB, pLucasA, pLucasB);
    int pontosMaria  = calcular(golsReaisA, golsReaisB, pMariaA, pMariaB);

    // 4. EXIBIÇÃO DOS JOGOS
    cout << " PLACAR DOS JOGOS " << endl;
    for (int i = 0; i < 4; i++) {
        cout << timesA[i] << " " << golsReaisA[i] << " x " << golsReaisB[i] << " " << timesB[i] << endl;
    }

    // 5. LÓGICA DO RANKING POR ARVORE DE DECISÃO (Sem loops de ordenação)
    cout << "\n RANKING DO BOLAO " << endl;

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
    else { // Maria >= Lucas >= Leonam
        cout << "1º Lugar: Maria -> " << pontosMaria << "\n2º Lugar: Lucas -> " << pontosLucas << "\n3º Lugar: Leonam -> " << pontosLeonam << endl;
    }

    return 0;
}