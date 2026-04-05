#include <iostream>

using namespace std;

void ajustaValor(int*p1,int*p2){
  (*p1)++; //os parenteses sao necessarios pois o "++" tem maior preferencia que o ponteiro então ele não incrementaria, com o parenteses ele aponta para o endereço e depois incrementa
  (*p2)--;
}
int main(){
  int a=19, b=21;

ajustaValor (&a,&b);

cout<<"os valores ajustados sao: "<<a<< " e "<<b<<endl;
return 0;
}
  
