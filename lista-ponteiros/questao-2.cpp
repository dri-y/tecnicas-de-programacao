
#include <iostream>
using namespace std;

void trocaValores (int*p1, int*p2){
    int caixa = 0;
    caixa = *p1;
    *p1 = *p2;
    *p2 = caixa;
}

int main(){
    int a=10, b=20;
    
    trocaValores(&a,&b);

cout<<"o valor de a e b agora são: "<<a<<" e "<<b<<endl;
    return 0;
}
