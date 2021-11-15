#include <bits/stdc++.h>
using namespace std;

long fib(int n){
    if(n <= 1) return n;
    return fib(n-2) + fib(n-1);
}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<fib(n)<<"\n";
    return 0;
}