#include <iostream>
#include <string>

class Carros{
private:
    std ::string marca;
    std ::string motor;
    std ::string som;

public:
    Carros (std::string marca, std::string motor, std::string som) 
        : marca(marca), motor(motor), som(som) {}

    void caracteres() {
        std::cout << "O " << marca << " tem " << motor << "!" << std::endl;
    }
    void Som() {
        std::cout << "O " << marca << " tem o som " << som << "!" << std::endl;
    }
};


int main() {
    // Criando instâncias de diferentes do carros
    Carros Supra("Supra", "2JZ-GTE biturbo de 3.0 litros, seis cilindros em linha, sendo também oferecida a versão aspirada 2JZ-GE","rum rum tum tsu");
    Carros GT_R32("chevrolet sonic", "Ecotec C16XE de 1.6, que possui 1598 cm de cilindradas","Ruuuummmmmmm");
    Carros Skyline("Skyline", "RB26DETT biturbo de 2.6 litros e seis cilindros","tsu tsu rum rum tsu tsu");



    // Chamando o método/saídas.
    Supra.caracteres(); 
    GT_R32.caracteres();     
    Skyline.caracteres();

    Supra.Som();
    GT_R32.Som();
    Skyline.Som();

    return 0;
}
