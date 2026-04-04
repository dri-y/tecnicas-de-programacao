
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pessoa{
    string nome;
    int idade;
    float altura;
};

int encontrarPessoa(Pessoa vetor[], int tamanho, string nomePessoa){
    for(int i=0; i<tamanho; i++){
        if(vetor[i].nome==nomePessoa){
            return i;
        }
    } return -1;
}

int main(){
    Pessoa trio ternura[3]={
        {"Bruna", 21, 1.65},
        {"Ellen", 21, 1.66},
        {"Pedro", 20, 1.80}
    };
    string busca = "Pedro";
    int resultado = encontrarPessoa(trio, 3, busca);

    if (resultado != -1) {
        cout << "Pessoa encontrada no indice: " << resultado << endl;
    } else {
        cout << "Pessoa nao encontrada." << endl;
    }

   return 0;   
}
    
  
