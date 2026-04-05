//Resolução  da função usando vector
#include <vector> 

struct Pessoa{
string nome;
int idade;
float altura;
}

float somaAlturas(const vector<Pessoa>& vetor) {
    float somaTotal = 0.0;
    for (const auto& p : vetor) { // Aqui o for-each funciona!
        somaTotal += p.altura;
    }
    return somaTotal;
}
