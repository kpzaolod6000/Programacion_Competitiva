#include <iostream>
using namespace std;

bool verificar(int n){
    bool result = ((n & (n-1)) == 0);
    return result;
}
int main()
{
  cout<<"verificando con el numero: "<<7<<endl;
  cout<<"el resultado es:" <<verificar(7)<<endl;

  cout<<"verificando con el numero: "<<8<<endl;
  cout<<"el resultado es:" <<verificar(8)<<endl;
    
    return 0;
}

/* Explique qué es lo que hace el siguiente código ((n & (n-1)) == 0)

Es la forma de calcular si un numero es la potencia de 2 a nivel binario ya que las
potencias son las que cumplen con dicha condicion
 0   0000  0000 & -1 = 0000
 
 2   0010  0010 & 0001 = 0000
 
 4   0100  0100 & 0011 = 0000
 
 8   1000  1000 % 0111 = 0000

y asi sucesivamente

*/