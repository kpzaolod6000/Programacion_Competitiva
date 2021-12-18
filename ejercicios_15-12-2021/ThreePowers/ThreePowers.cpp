#include <bits/stdc++.h>

using namespace std;
#define ll long long

void calc(ll n){
    ll shifts = 0;
    ll elements = 0;
    if (n == 0)
    {
        cout<<"{ }"<<endl; 
        return;  
    }
    
    cout<<"{ ";
    while (n > 0){
        if ( (n & 1) == 1){
            
            if (elements == 0) cout<<pow(3,shifts);
            else cout<<", "<<pow(3,shifts);
            elements++;
        }
        n >>= 1;
        shifts++;
    }
    cout<<" }"<<endl;
}

int main(){

 
    while (true)
    {
        ll n;
        cin >> n;
        if (n == 0) break;
        calc(n-1);
    }
    

    return 0;
}