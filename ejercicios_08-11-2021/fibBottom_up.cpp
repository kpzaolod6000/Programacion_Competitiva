
#include <bits/stdc++.h>
using namespace std;

long fib_bottomup(int n){
    if(n<=1)
        return n;
    vector<long> F(n+1);
    F[0] = 0;
    F[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        F[i] = F[i-2] + F[i-2];
    }
    return F[n];
}
long fib_memorization(int n){
    vector<long> memo(n+1);
    return fib(n,memo);
}

int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<fib(n)<<"\n";
    return 0;
}