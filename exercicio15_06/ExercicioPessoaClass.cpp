#include <iostream>
#include <string>

using namespace std;


class Pessoa {
public:
    string nome;
    int idade;

    
    Pessoa(string n, int i) {
        nome = n;
        idade = i;
    }
};

int main() {
    
    Pessoa pessoa1("Leonam", 22);
    Pessoa pessoa2("Raquel", 20);

    // Mostrando os dados na tela
    cout << "Dados da Pessoa 1:" << endl;
    cout << "Nome: " << pessoa1.nome << " | Idade: " << pessoa1.idade << endl;

    cout << "\nDados da Pessoa 2:" << endl;
    cout << "Nome: " << pessoa2.nome << " | Idade: " << pessoa2.idade << endl;

    return 0;
}
    