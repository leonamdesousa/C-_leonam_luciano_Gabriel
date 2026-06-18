#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

class Biblioteca {
private:
    string nome;
    vector<string> livros;

public:
    // Construtor
    Biblioteca(string n) {
        setNome(n);
    }

    // Getter
    string getNome() const { 
        return nome; 
    }

    // Setter com validação para o nome da instituição
    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            cout << "Erro: O nome da biblioteca não pode ser vazio.\n";
        }
    }

    // Adiciona o título caso seja válido e não duplicado
    void adicionarLivro(string titulo) {
        if (titulo.empty()) {
            cout << "Erro: Não é possível cadastrar um título vazio.\n";
            return;
        }
        
        for (const string& l : livros) {
            if (l == titulo) {
                cout << "Erro de Cadastro: O livro '" << titulo << "' já consta no acervo.\n";
                return;
            }
        }
        livros.push_back(titulo);
        cout << "Livro '" << titulo << "' registrado com sucesso.\n";
    }

    // Lista o acervo completo ou aponta se está vazia
    void listarLivros() {
        cout << "\n= ACERVO: " << nome << " =\n";
        if (livros.empty()) {
            cout << "Nenhum livro cadastrado.\n";
            return;
        }
        for (const string& l : livros) {
            cout << " [Disponível] - " << l << "\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Desafio: Criar biblioteca "Biblioteca Central"
    Biblioteca minhaBiblioteca("Biblioteca");
    cout << "Biblioteca configurada: " << minhaBiblioteca.getNome() << "\n\n";

    // Adicionando 3 livros diferentes
    minhaBiblioteca.adicionarLivro("C++ Puro e Simples");
    minhaBiblioteca.adicionarLivro("POO");
    minhaBiblioteca.adicionarLivro("Código Limpo");
    
    // Tentando adicionar um título repetido (o sistema deve impedir)
    cout << "\nTestando tentativa de duplicidade:\n";
    minhaBiblioteca.adicionarLivro("Código Limpo"); 

    // Exibindo listagem atualizada
    minhaBiblioteca.listarLivros();

    // Alterando o nome da biblioteca
    cout << "\nAtualizando cadastro...\n";
    minhaBiblioteca.setNome("Biblioteca");
    cout << "Nome atualizado verificado: " << minhaBiblioteca.getNome() << "\n";

    return 0;
}