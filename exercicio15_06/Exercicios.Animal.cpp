#include <iostream>
#include <string>

class Animal {
private:
    std::string especie;
    std::string som;

public:
    Animal(std::string especie, std::string som) 
        : especie(especie), som(som) {}

    void efeito_sonoro() {
        std::cout << "O " << especie << " faz: " << som << "!" << std::endl;
    }
};

int main() {
    // Criando instâncias de diferentes animais
    Animal cachorro("Cachorro", "Au");
    Animal gato("Gato", "Miau");
    Animal corvo("Corvo", "Crow");

    // Chamando o método/saídas.
    cachorro.efeito_sonoro(); 
    gato.efeito_sonoro();     
    corvo.efeito_sonoro();

    return 0;
}
