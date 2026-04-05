#include <iostream>

using namespace std;

void duplicaValor(int* p) {
    *p *= 2; 
}

int main() {
    int numero = 10; 

    duplicaValor(&numero);
    cout << numero << endl; // Vai imprimir 20

    return 0;
}
