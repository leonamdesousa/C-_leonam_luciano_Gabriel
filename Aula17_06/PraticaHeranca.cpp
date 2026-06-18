#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Pessoa {
protected:
    string name;

public:

    Pessoa (string n) : name (n) {}

    virtual ~Pessoa() {}

    virtual void falar(){ // virtual permite escrita.
        cout << name << " está falando" << endl;
    }
};
class Professor : public Pessoa {
private:
    string disciplina;

public: 

    Professor(string n, string d) : Pessoa (n), disciplina(d){}

    void falar() override{ // virtual permite escrita.
        cout <<"Professor(a)" << name << " está ensinando" << endl; 
    }
};

class Aluno : public Pessoa{
private:
    int matricula;
public:
    Aluno(string n, int m) : Pessoa(n), matricula(m) {}

    void falar() override{ // virtual permite escrita.
        cout <<"Aluna(a)" << name << "( matrícula: " << matricula <<" ) está aprendendo." << endl; 
    }
};

void fazerFalar(Pessoa*p){
        p->falar();
    }

int main(){
    // Pessoa p("Leonam");
    // Professor prof("Raquel","Elétrica");
    // Aluno aluno("Geovana",101);
    Pessoa* p1 = new Pessoa("João");
    Pessoa* p2 = new Professor("João","Física");
    Pessoa* p3 = new Aluno("João",202);

    fazerFalar(p1);
    fazerFalar(p2);
    fazerFalar(p3);

    delete p1;
    delete p2;
    delete p3;
    //p.falar();
    //prof.falar();
    //aluno.falar();

    return 0;
}