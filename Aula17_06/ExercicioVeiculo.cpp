#include <iostream>
#include <string>
using namespace std;

// Classe Pai
class Veiculo {
protected:
    string marca;

public:

    Veiculo(string m) : marca(m) {}
};

// Classe Filho (Subclasse) que herda de Veiculo
class Carro : public Veiculo {
private:
    string modelo;

public:
    Carro(string m, string mod) : Veiculo(m), modelo(mod) {}

    void exibirDetalhes() {
        cout << "Carro: " << marca << " " << modelo << endl;
    }
};

int main() {
    // Criando um objeto da classe Carro
    Carro meuCarro("Honda", "Civic");

    // Exibindo os dados
    meuCarro.exibirDetalhes();

    return 0;
}