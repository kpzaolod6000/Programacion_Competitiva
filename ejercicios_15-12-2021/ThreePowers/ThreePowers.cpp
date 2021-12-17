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
            string h = 
            if (elements == 0) cout<<to_string(pow(3,shifts));
            else cout<<", "<<to_string(pow(3,shifts));
            elements += 1;
        }
        n >>= 1;
        shifts += 1;
    }
    cout<<" }"<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    while(cin>>n){
        if (n == 0) break;
        calc(n-1);
    }
    

    return 0;
}