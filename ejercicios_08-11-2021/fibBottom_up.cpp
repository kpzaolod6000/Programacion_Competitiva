
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
        F[i] = F[i-2] + F[i-1];
    }
    return F[n];
}

int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cout<<fib_bottomup(n)<<"\n";
    return 0;
}