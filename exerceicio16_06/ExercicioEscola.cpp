#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

class Aluno {
private:
    string nome;
    int idade;
    string curso;

public:
    // Construtor
    Aluno(string n, int id, string c) {
        setNome(n);
        setIdade(id);
        setCurso(c);
    }

    // Getters e Setters com validações
    string getNome() const { return nome; }
    void setNome(string novo_nome) {
        if (!novo_nome.empty()) nome = novo_nome;
    }

    int getIdade() const { return idade; }
    void setIdade(int nova_idade) {
        if (nova_idade > 0) idade = nova_idade;
    }

    string getCurso() const { return curso; }
    void setCurso(string novo_curso) {
        if (!novo_curso.empty()) curso = novo_curso;
    }

    // Retorna a string formatada
    string apresentar() {
        return "Nome: " + nome + " | Idade: " + to_string(idade) + " | Curso: " + curso;
    }
};

class Escola {
private:
    string nome;
    vector<Aluno*> alunos; // Guarda os ponteiros dos alunos para refletir alterações

public:
    Escola(string n) {
        setNome(n);
    }

    string getNome() const { return nome; }
    void setNome(string novo_nome) {
        if (!novo_nome.empty()) nome = novo_nome;
    }

    // Adiciona o aluno usando o endereço de memória dele (&aluno)
    void adicionarAluno(Aluno* aluno) {
        if (aluno != nullptr) {
            alunos.push_back(aluno);
            cout << "Aluno(a) " << aluno->getNome() << " matriculado(a) com sucesso.\n";
        }
    }

    // Exibe chamando o apresentar() de cada ponteiro
    void listarAlunos() {
        cout << "\n= ALUNOS MATRICULADOS: " << nome << " =\n";
        if (alunos.empty()) {
            cout << "Nenhum aluno matriculado.\n";
            return;
        }
        for (Aluno* a : alunos) {
            cout << a->apresentar() << "\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    // 1. Criando a escola
    Escola minhaEscola("Escola Futuro");

    // 2. Criando os 2 alunos
    Aluno aluno1("Leonam", 22, "Informática");
    Aluno aluno2("Raquel", 20, "Engenharia elétrica");

    // 3. Adicionando à escola (usando o & para passar o endereço do objeto)
    minhaEscola.adicionarAluno(&aluno1);
    minhaEscola.adicionarAluno(&aluno2);

    // 4. Exibindo a lista inicial
    minhaEscola.listarAlunos();

    // 5. Testando alterações com os métodos SET
    cout << "\n--- Executando alterações com validações ---\n";
    
    // Testes Inválidos (O sistema vai ignorar e manter os dados antigos)
    aluno1.setIdade(-5); 
    aluno1.setCurso(""); 

    // Testes Válidos (O sistema vai alterar com sucesso)
    aluno2.setNome("Gabriel Luciano");
    aluno2.setCurso("Engenharia de Software");

    // 6. Exibindo novamente para comprovar o funcionamento
    cout << "\nListando novamente (Repare as alterações em tempo real):";
    minhaEscola.listarAlunos();

    return 0;
}