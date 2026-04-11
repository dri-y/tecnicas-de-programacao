#include <iostream>
#include <vector>

using namespace std;


double calcularMedia(vector<double> leituras_temp) {
    double acumulador = 0.0;

    
    for (double t : leituras_temp) {
        acumulador += t;
    }

    
    if (leituras_temp.empty()) {
        return 0.0;
    }

   
    return acumulador / leituras_temp.size();
}

int main() {
    
    vector<double> leituras = {25.0, 23.0, 30.0};

    
    double media = calcularMedia(leituras);

    
    cout << "Media das leituras: " << media << endl;

    return 0;

