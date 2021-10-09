#include <bits/stdc++.h>

using namespace std;

void PalindromeQueries(vector<char> &arr,int qline){ // aybabtu

    if(qline == 1){
        int k;
        char u;
        cin>>k>>u;
        arr[k - 1] = u;
    }else if(qline == 2){ 
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        bool isTrue = true;
        while (a<=b)
        {
            isTrue = true;
            // cout<<a<<" "<<b<<"\n";
            if (arr[a] == arr[b])
            {
                a++; b--;
            }else{
                isTrue = false;
                break;
            }            
        }
        if (isTrue) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";

    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q,value;
    cin >> n >>q;

    // string arr;
    // getline(cin,arr);
    vector<char> arr(n);

    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    
    int qline;
    int j = 0;
    while (j < q)
    {
        cin>>qline; 
        PalindromeQueries(arr,qline);
        j++;
    }

    return 0;
}