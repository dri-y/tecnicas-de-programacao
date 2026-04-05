#include <iostream>
#include <cmath> 

using namespace std;

void calcularRaizQuadrada(double numero, double *p) {
    if (numero < 0) {
      
        *p = -1.0; 
        cout << "Nao eh possivel calcular a raiz de um numero negativo" << endl;
    } else {
      
        *p = sqrt(numero);
    }
}

int main() {
    double num = 25.0;
    double resultado; 

    calcularRaizQuadrada(num, &resultado);

    cout << "Resultado: " << resultado << endl;

    return 0;
}
