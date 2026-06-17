#include <iostream>
#include <string>
#include <locale>
using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;

public:
    ContaBancaria(string t, double s) : titular(t), saldo(s) {
    }
    string getTitular() const { 
        return titular; 
    }
    double getSaldo() const { 
        return saldo; 
    }
        
    // Método de depositar
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de R$ " << valor << " realizado com sucesso.\n";
        } else {
            cout << "Valor de depósito inválido.\n";
        }
    }

    // Método de sacar (agora dentro do escopo correto da classe)
    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
        } else if (valor > saldo) {
            cout << "Saldo insuficiente para saque de R$ " << valor << ".\n";
        } else {
            cout << "Valor de saque inválido.\n";
        }
    }

    // Saldo da conta
    void exibirSaldo() {
        cout << "Saldo final da conta de " << titular << ": R$ " << saldo << "\n";
    }
}; // Fim da classe

int main() {
    // Português
    std::setlocale(LC_ALL, "Portuguese");
    // Conta
    ContaBancaria minhaConta("Leonam", 1000.00);
    // Depósito
    minhaConta.depositar(100.00);
    // Saque
    minhaConta.sacar(10.00);
    // Saldo
    minhaConta.exibirSaldo();

    return 0; 
}