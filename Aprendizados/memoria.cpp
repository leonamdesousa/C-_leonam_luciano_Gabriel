#include <iostream>
using namespace std;

int main()
{
    // Alocação do inteiro
    int *pi = new int;
    *pi = 1001;
    cout << "Valor inteiro = " << *pi << endl; // Aspas corrigidas aqui
    cout << "Localizacao = " << pi << endl << endl;

    // Alocação do double
    double *pd = new double;
    *pd = 500.35;
    cout << "Valor ponto-flutuante = " << *pd << endl; // Aspas corrigidas aqui
    cout << "Localizacao = " << pd << endl << endl;

    // Exibição dos tamanhos
    cout << "Tamanho de pi = " << sizeof(pi) << endl; // Aspas corrigidas aqui
    cout << "Tamanho de *pi = " << sizeof(*pi) << endl << endl; // Aspas corrigidas aqui
    cout << "Tamanho de pd = " << sizeof(pd) << endl; // Aspas corrigidas aqui
    cout << "Tamanho de *pd = " << sizeof(*pd) << endl;

    // Boa prática: Liberar a memória alocada dinamicamente
    delete pi;
    delete pd;

    return 0;
}