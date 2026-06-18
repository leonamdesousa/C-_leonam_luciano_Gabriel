#include <iostream>
#include <string>
using namespace std;


// Classe Pai
class Funcionario {
protected:
    string nome;
    double salarioBase;

public:
    Funcionario(string n, double s) : nome(n), salarioBase(s) {}

    virtual void mostrarSalario() {
        cout << "Funcionario: " << nome << " | Salario: R$ " << salarioBase << endl;
    }

};

// Classe Filho
class Gerente : public Funcionario {
public:
    // Reaproveita o construtor da classe pai
    Gerente(string n, double s) : Funcionario(n, s) {}

    // Sobrescrita do método
    void mostrarSalario() override {
        double salarioComBonus = salarioBase * 1.20; // Aplica o bônus de 20%
        cout << "Gerente: " << nome << " | Salario com Bonus (20%): R$ " << salarioComBonus << endl;
    }
};

int main() {
    Funcionario func("Carlos",1612.48);
    Gerente ger("Mariana", 4302.12);

    // Chamadas diretas
    func.mostrarSalario();
    ger.mostrarSalario();

    return 0;
}