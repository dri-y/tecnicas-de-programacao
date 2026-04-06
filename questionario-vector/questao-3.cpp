//implemente uma função removerDuplicados que receba um vector<int: contendo possíveis valores repetidos e retorne um novo vector<int> com paneas a primeira ocorrência de cada valor, mantendo a ordem original dos elementos 

#include <vector>

vector<int> removerDuplicados (vector<int>vetor){
  vector<int>novo;
  bool existe;
  for(auto a : vetor){
  existe = false;
    for(auto b : novo){
      if (a == b){
    existe=true;
      break;
      }
    }
  if(!existe){
  novo.push_back(a);
  }
}
return novo;
}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//USANDO O FIND
#include<vector>
  
  vector<int> removerDuplicados(vector<int> vetor){
    vector<int>novo;
    for (auto elemento :vetor){
      if(find(novo.begin(), novo.end(), elemento) == novo.end){
            novo.push_back(elemento);
      }
    }
  return novo;
}
