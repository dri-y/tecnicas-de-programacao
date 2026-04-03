#include <iostream>
#include <string>

using namespace std;

struct Pessoa{
    string nome;
    int idade;
    float altura;
};

void inicializaPessoa(Pessoa *p, string N, int I, float A){
    p->nome=N;
    p->idade=I;
    p->altura=A;
    
}


int main(){
    Pessoa p1;
    
   inicializaPessoa(&p1, "Geaniny Adriane", 19, 1.69);
    
    cout<<"Nome: "<<p1.nome<<endl;
    cout<<"Idade: "<<p1.idade<< " anos"<<endl;
    cout<< "Altura: "<<p1.altura<<" metros"<<endl;

return 0;
}
