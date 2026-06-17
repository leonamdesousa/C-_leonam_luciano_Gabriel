#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Carro {
private:
    string marca;
    double velocidade;

public:
    // Construtor: todo carro começa parado (velocidade 0)
    Carro(string m) : marca(m), velocidade(0.0) {
    }

    // Getters para exibir as informações
    string getMarca() const { return marca; }
    double getVelocidade() const { return velocidade; }

    // Método acelerar: aumenta a velocidade pelo valor passado
    void acelerar(double valor) {
        if (valor > 0) {
            velocidade += valor;
            cout << marca << " acelerou para " << velocidade << " km/h.\n";
        }
    }

    // Método frear: reduz
    void frear(double valor) {
        if (valor > 0) {
            // Se o freio fosse zerar 
            if (velocidade - valor <= 0) {
                velocidade = 1.0; // Velocidade mínima
                cout << marca << " freou bruscamente! Mantendo velocidade mínima de segurança: " << velocidade << " km/h.\n";
            } else {
                velocidade -= valor;
                cout << marca << " reduziu para " << velocidade << " km/h.\n";
            }
        }
    }
};

int main() {
    std::setlocale(LC_ALL, "Portuguese");

    // Criando um carro
    Carro meuCarro("Ferrari");

    // Testando as funções
    meuCarro.acelerar(100.0); 
    meuCarro.frear(40.0);     
    

    meuCarro.frear(80.0);    

    cout << "\n--- Informações Finais ---\n";
    cout << "Carro: " << meuCarro.getMarca() << "\n";
    cout << "Velocidade Atual: " << meuCarro.getVelocidade() << " km/h\n";

    return 0;
}