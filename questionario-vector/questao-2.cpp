//Dado um vetor de inteiros, crie uma função chamada filtrarPares que receba esse vetor e retorne um novo vetor contendo apenas os valores pares.
#include <vector>
using namespace std;

vector<int> filtrarPares(vector<int> valores) {
    vector<int> pares; // Vetor que armazenará os números pares

    for (auto valor : valores) { // Percorre todos os elementos do vetor         
        if (valor % 2 == 0) {    // Verifica se o número é par          
            pares.push_back(valor); // Adiciona ao vetor de pares
        }
    }

    return pares; // Retorna o novo vetor contendo apenas os pares
}
