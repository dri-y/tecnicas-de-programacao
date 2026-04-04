
#include <iostream>
#include <string>
#include <vector>

using namespace std;


  struct Pessoa{
      string nome;
      int idade;
      float altura;
  };

 void alteraIdade(Pessoa *ptr, int novaIdade){
     ptr-> idade = novaIdade;
 }
 int main() {
    
    Pessoa* ptr = nullptr; 

    Pessoa p1 = {"Joao", 25, 1.75};

    
    ptr = &p1;

    alteraIdade(ptr, 30);
    
    
    if (ptr != nullptr) {
        cout << "Nova idade: " << ptr->idade << endl;
    }

    return 0;
}
