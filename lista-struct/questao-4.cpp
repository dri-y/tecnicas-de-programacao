#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;


  struct Pessoa{
      string nome;
      int idade;
      float altura;
  };
float somaAlturas (Pessoa vetor[], int tamanho){
  float somaTotal = 0.0;
  for (int i= 0; i<tamanho; i++){
    somaTotal+=vetor[i].altura;
  }
return somaTotal;
}
int main() {
    Pessoa pessoas[] = {
        {"Joao", 25, 1.75},
        {"Maria", 30, 1.65},
        {"Pedro", 22, 1.80}
    };

    assert(abs(somaAlturas(pessoas, 3) - 5.20) < 0.0001);  // 1.75 + 1.65 + 1.80 = 5.20

    Pessoa pessoas2[] = {
        {"Ana", 20, 1.50},
        {"Carlos", 40, 1.90}
    };

    assert(abs(somaAlturas(pessoas2, 2) - 3.40) < 0.0001);  // 1.50 + 1.90 = 3.40

    cout << "Todos os testes passaram!" << endl;
    return 0;
}

  
