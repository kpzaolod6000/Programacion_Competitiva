#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // codigo
    // int n, k,cont,x;
    // cin>>n;cin>>k;
    // if (k<= pow(10,7)){
    //     while(n--){
    //         cin>>x;
    //         cont = (x%k == 0) ? cont + 1 : cont; 
    //     }
    // }
    // cout << cont <<"\n";
    int n,k,value,cnt = 0;
    
    cin>>n>>k;

    for (size_t i = 0; i < n; i++)
    {
        cin>>value;
        cnt = (value % k == 0) ? cnt + 1 : cnt; 
    }
    
    cout<<cnt<<"\n";
    
    return 0;
}