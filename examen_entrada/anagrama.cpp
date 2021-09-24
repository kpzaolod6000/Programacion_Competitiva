#include <iostream>
#include <string>
using namespace std;
int main(){
 
  string word1;
  string word2;
  cout << "word 1: ";
  getline (cin, word1);
  cout << "word 2: ";
  getline (cin, word2);
  
  //CASO DE PRUEBAS: neo-one
  //SALIDA ESPERADA: La palabra es un anagrama 

  //CASO DE PRUEBAS: fresa-frase
  //SALIDA ESPERADA: La palabra es un anagrama
    //CASO DE PRUEBAS: carro-carla
  //SALIDA ESPERADA: La palabra no es un anagrama


  bool isAnagr = false;
  if(word1.size() == word2.size())
  {
    while( word1.size() != 0){
      int i = 0; 
      bool is = false;
      int index;
      for (int j = 0;j < word2.size(); j++){
        if(word1[i] == word2[j]){
          is = true;
          index = j;
          break;
        }
      }
      if (is){
        //cout<< word1[i] <<"..."<< word2[index]<<endl;
        
        word1.erase(i,1);
        word2.erase(index,1);
        //cout<< word1 << "..." << word2 <<endl;
      }else{
        word1.erase(i,1);
      }
    }
    if(word1.size() == 0 && word2.size() == 0) cout<<"La palabra es un anagrama ";
    else cout<<"La palabra no es un anagrama ";
    
  }else{
    cout<<"La palabra no es un anagrama ";
    return 0;
  }
  
  return 0;
}

