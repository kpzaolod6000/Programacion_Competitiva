#include <bits/stdc++.h>

using namespace std;

vector<int> sumsPrefix(vector<int> arr){
    
    vector<int> aux;
    aux.push_back(0);

    for (size_t i = 0; i < arr.size(); i++) aux.push_back(aux.back() + arr[i]);

    return aux;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    vector<int> arr;
    cin >> n;

    for (size_t i= 0;i < n; i++){
        cin>>value;
        arr.push_back(value);
    }
    
    arr = sumsPrefix(arr);
    
    for (auto data : arr) // access by value, the type of i is int
        cout << data << ' ';
    cout << '\n';
    
    return 0;
}