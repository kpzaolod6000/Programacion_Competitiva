#include <iostream>

void fibonacci(int n){
    if(n<=1){std::cout<< n; return;}
    if(n==2){std::cout<< n; return;}
    long actual, ant1, ant2;
    actual = 0;
    ant1=1;
    ant2=1;
   
    for (int i = 3; i <= n; i++)
    {
        actual=ant1+ant2;
        ant1 = ant2;
        ant2 = actual;
        std::cout<<actual<<" ";
    } 
    
}

int main() {
  int number;
  std::cin >> number;
  if (number >=2) std::cout<<0<<" "<<1<<" "<<1<<" ";
  fibonacci(number);
}