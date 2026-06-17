#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

class Restaurante {
private:
    string nome;
    vector<string> cardapio;

public:
    // Construtor
    Restaurante(string n) {
        setNome(n);
    }

    // Getter para obter o nome
    string getNome() const { 
        return nome; 
    }

    // Setter com validação para impedir nomes vazios
    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            cout << "Erro: O nome do restaurante não pode ser vazio.\n";
        }
    }

    // Adiciona prato garantindo que ele não seja repetido
    void adicionarPrato(string prato) {
        if (prato.empty()) return;
        
        for (const string& p : cardapio) {
            if (p == prato) {
                cout << "Aviso: O prato '" << prato << "' já existe no cardápio.\n";
                return;
            }
        }
        cardapio.push_back(prato);
        cout << "Prato '" << prato << "' adicionado com sucesso.\n";
    }

    // Exibe todos os itens do cardápio
    void listarCardapio() {
        cout << "\n= CARDÁPIO: " << nome << " =\n";
        if (cardapio.empty()) {
            cout << "O cardápio está vazio.\n";
            return;
        }
        for (const string& p : cardapio) {
            cout << " - " << p << "\n";
        }

    }

    // Atende o cliente verificando a existência do prato
    void atenderCliente(string nome_cliente, string prato) {
        for (const string& p : cardapio) {
            if (p == prato) {
                cout << "[Pedido Confirmado] " << nome_cliente << " pediu " << prato << ".\n";
                return;
            }
        }
        cout << "[Pedido Negado] Desculpe " << nome_cliente << ", mas '" << prato << "' não está disponível no menu.\n";
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Desafio: Criar restaurante "Sabor Caseiro"
    Restaurante meuRestaurante("Sabor Caseiro");
    cout << "Restaurante criado: " << meuRestaurante.getNome() << "\n\n";

    // Adicionando 3 pratos diferentes
    meuRestaurante.adicionarPrato("Feijoada");
    meuRestaurante.adicionarPrato("Lasanha");
    meuRestaurante.adicionarPrato("Churrasco");
    
    // Exibindo cardápio
    meuRestaurante.listarCardapio();
    cout << "\n";

    // Simulação de clientes fazendo pedidos (um existente e um inexistente)
    meuRestaurante.atenderCliente("Leonam", "Feijoada");
    meuRestaurante.atenderCliente("Raquel", "Sushi"); 

    // Alterando o nome do estabelecimento usando setNome()
    cout << "\nModificando identificação do estabelecimento...\n";
    meuRestaurante.setNome("Sabor Caseiro Premium");
    cout << "Nome atualizado via getNome(): " << meuRestaurante.getNome() << "\n";

    return 0;
}