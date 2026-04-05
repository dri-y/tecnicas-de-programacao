#include <iostream>

using namespace std;
void multiplicaArray(int *array, int tamanho, int multiplicador){
  for(int i= 0;i<tamanho; i++){
  array[i] *=multiplicador;
  }
}
int main() {
    int meusNumeros[] = {1, 2, 3, 4, 5};
    int tam = 5;
    int mult = 10;

   
    multiplicaArray(meusNumeros, tam, mult);

    
    for(int i = 0; i < tam; i++) {
        cout << meusNumeros[i] << " ";
    }

    return 0;
}
