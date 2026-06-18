#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Classe Base
class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string n, double p) : nome(n), preco(p) {}

    virtual void exibirDados() const {
        cout << "Produto: " << nome << " | Preco: R$ " << preco;
    }
}; 

// Subclasse Livro
class Livro : public Produto {
private:
    string autor;

public:
    Livro(string n, double p, string a) : Produto(n, p), autor(a) {}

    void exibirDados() const override {
        Produto::exibirDados();
        cout << " | Autor: " << autor << endl;
    }
};

// Subclasse Eletronico
class Eletronico : public Produto {
private:
    string marca;

public:
    Eletronico(string n, double p, string m) : Produto(n, p), marca(m) {}

    void exibirDados() const override {
        Produto::exibirDados();
        cout << " | Marca: " << marca << endl;
    }
};


int main() {

    Livro livro1("O Senhor dos Aneis", 59.90, "alguém");
    Livro livro2("1984", 39.90, "outro alguém");

    Eletronico eletronico1("OPPO Reno 13", 4500.00, "Oppo");
    Eletronico eletronico2("Notebook NitroV", 6200.00, "Acer");


    cout << " LISTA DE PRODUTOS " << endl;
    livro1.exibirDados();
    livro2.exibirDados();
    eletronico1.exibirDados();
    eletronico2.exibirDados();

    return 0;
}