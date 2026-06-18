#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    // Construtor
    Produto(string n, double n1) : 
    nome(n), 
    preco(n1) {
    }

    // Métodos
    string getNome() const { return nome; }
    double getPreco() const { return preco; }

    void setPreco(double p) {
        if (p > 0) {
            preco = p;
        } else {
            cout << "Erro: O preço do produto " << nome << " não pode ser zero ou negativo!\n";
            preco = 0.01;
        }
    }

    // Método para mostrar os dados
    void exibirDados() {
        cout << "Produto: " << nome << " | " << preco << " por unidade""\n";
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Criando aluno
    Produto produto1("Coxinha de frango com catuperi", 1.48);
    Produto produto2("Coca-Cola",3.50);

    produto1.exibirDados();
    produto2.exibirDados();

    return 0;
}