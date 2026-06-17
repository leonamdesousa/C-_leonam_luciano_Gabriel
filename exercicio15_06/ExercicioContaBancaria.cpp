#include <iostream>
#include <string>
#include <locale>

class ContaBancaria{
private:
    std::string titular;
    double saldo;

public:
    ContaBancaria(std::string nomeTitular, double saldoInicial) {
        titular = nomeTitular;
        saldo = saldoInicial;
        }
// Metódo de depositar.
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            std::cout << "Depósito de R$ " << valor << " realizado com sucesso.\n";
        } else {
            std::cout << "Valor de depósito inválido.\n";
        }
    }
// Metódo de sacar.
    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
        } else if (valor > saldo) {
            std::cout << "Saldo insuficiente para saque de R$ " << valor << ".\n";
        } else {
            std::cout << "Valor de saque inválido.\n";
        }
    }
// Saldo da conta.
    void exibirSaldo() {
            std::cout << "Saldo final da conta de " << titular << ": R$ " << saldo << "\n";
    }
};

int main() {
    //portugues
    std::setlocale(LC_ALL, "Portuguese");
    //conta
    ContaBancaria minhaConta("Leonam",1000.00);
    //Deposito
    minhaConta.depositar(200.00);
    //Saque
    minhaConta.sacar(3000.00);
    //Saldo
    minhaConta.exibirSaldo();

return 0; 

}
