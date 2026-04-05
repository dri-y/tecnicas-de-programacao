#include <iostream>

using namespace std;

void removeNegativos (int *array, int tamanho){
  for(int i= 0;i<tamanho;i++){
    if(array[i]<0){
    array[i]=0;
    }
  }
}
int main() {
    int dados[] = {10, -5, 20, -1, 0, -33};
    int tam = 6;
  removeNegativos(dados, tam);

   for(int i = 0; i < tam; i++) {
        cout << dados[i] << " ";
    }

    return 0;
}
