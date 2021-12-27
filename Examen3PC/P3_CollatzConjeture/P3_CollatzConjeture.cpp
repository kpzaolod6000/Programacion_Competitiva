#include <bits/stdc++.h>
using namespace std; 

#define ll long long
ll rule_Collatz(ll& n){
    if (n%2==0)
    {
        return n/2;
    }else{
        return 3*n + 1;
    }
}

void collatz(ll A, ll B){

    unordered_map<ll, ll> cntMap;
    ll a = A;
    ll b = B;

    ll cnt = 0;
    cntMap[a] = cnt++;
    while (a !=1 )
    {
        a = rule_Collatz(a);
        cntMap[a] = cnt++;
    }
    ll cntB = 0;
    while (!cntMap.count(b))
    {
        b = rule_Collatz(b);
        cntB++;
    }
    cout<<A<<" needs "<< cntMap[b] << " steps, "<<B<<" needs "<<cntB<<" steps, they meet at "<<b<<endl;
}

    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll A,B;

    while (true) {
        cin>>A>>B;
        if (A == 0 && B == 0) {
            break;
        }
        collatz(A,B);
    }
}