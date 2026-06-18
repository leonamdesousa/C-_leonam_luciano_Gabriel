#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Personagem {
public:
    string nome;
    int nivel_poder;
    string tipo;

    Personagem(string n, int p, string t) : nome(n), nivel_poder(p), tipo(t) {}

    // O 'virtual' permite que as classes filhas modifiquem o comportamento deste método
    virtual void exibir() {
        cout << "Nome: " << nome << " | Tipo: " << tipo << " | Poder: " << nivel_poder;
    }
};

// ChefeFloresta herda de Personagem
class ChefeFloresta : public Personagem {
public:
    string reino;

    ChefeFloresta(string n, int p, string t, string r) : Personagem(n, p, t), reino(r) {}

    void exibir() override {
        Personagem::exibir(); // Chama a exibição da classe mãe
        cout << " | [Chefe do Reino: " << reino << "]";
    }
};


struct Nodo {
    shared_ptr<Personagem> personagem; // pointers para gerenciar a memória automaticamente
    Nodo* esquerda = nullptr;
    Nodo* direita = nullptr;

    Nodo(shared_ptr<Personagem> p) : personagem(p) {}
};

class ArvoreFloresta {
private:
    Nodo* raiz = nullptr;

    void inserirRecursivo(Nodo*& nodoAtual, shared_ptr<Personagem> novo) {
        if (nodoAtual == nullptr) {
            nodoAtual = new Nodo(novo);
        } else if (novo->nivel_poder < nodoAtual->personagem->nivel_poder) {
            inserirRecursivo(nodoAtual->esquerda, novo);
        } else {
            inserirRecursivo(nodoAtual->direita, novo);
        }
    }

    void percorrerEmOrdemRecursivo(Nodo* nodoAtual) {
        if (nodoAtual != nullptr) {
            percorrerEmOrdemRecursivo(nodoAtual->esquerda);  
            nodoAtual->personagem->exibir();                 
            cout << endl;
            percorrerEmOrdemRecursivo(nodoAtual->direita);   // Visita a direita (maiores)
        }
    }

public:
    void inserir(shared_ptr<Personagem> p) {
        inserirRecursivo(raiz, p);
    }

    void percorrerEmOrdem() {
        cout << "\n--- Habitantes da Floresta Encantada (Ordem Crescente de Poder) ---\n\n";
        percorrerEmOrdemRecursivo(raiz);
       
    }
};

int main() {
    ArvoreFloresta floresta;

    // Criando os personagens usando make_shared para gerenciar melhor os ponteiros de herança
    auto p1 = make_shared<Personagem>("Rock", 15, "Animal");
    auto p2 = make_shared<Personagem>("Maga raquel", 85, "Mago");
    auto p3 = make_shared<ChefeFloresta>("Chefe Dragao Ignis", 150, "Dragao", "Montanhas de Fogo");
    auto p4 = make_shared<Personagem>("Fada Luiana", 45, "Fada");
    auto p5 = make_shared<Personagem>("Goblin Recruta", 8, "Goblin");
    auto p6 = make_shared<ChefeFloresta>("Rainha Elfa Elena", 120, "Elfo", "Bosque Sagrado");

    // Inserindo os 6 personagens na árvore
    floresta.inserir(p1);
    floresta.inserir(p2);
    floresta.inserir(p3);
    floresta.inserir(p4);
    floresta.inserir(p5);
    floresta.inserir(p6);

    // Resultado
    floresta.percorrerEmOrdem();

    return 0;
}