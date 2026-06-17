#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Aluno {
private:
    string nome;
    double nota;

public:

    Aluno(string n, double n1) : nome(n) {
        setNota(n1); 
    }

    // Métodos Getters e Setters
    string getNome() const { return nome; }
    double getNota() const { return nota; }
    
    void setNota(double n1) {
        if (n1 >= 0) {
            nota = n1;
        } else {
            cout << "Erro: A nota do aluno '" << nome << "' não pode ser negativa!\n";
            nota = 0.01; 
        }
    }

    // Método
    void exibirDados() {
        cout << "Aluno: " << nome << " | Nota: " << nota << "\n";
    }
};

int main() {
    std::setlocale(LC_ALL, "Portuguese");

    // Criando aluno
    Aluno aluno1("Carlos", -8.5);
    aluno1.exibirDados();

    return 0;
}