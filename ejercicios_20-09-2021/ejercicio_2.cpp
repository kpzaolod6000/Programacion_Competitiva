#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sumsPrefix(vector<int> &array){
    int cont = 0;
    int sum;
    int prev = array[0];
    
    for(int i=0; i<array.size();i++){
        array[i] = array[i] + prev;
        prev = array[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    vector<int> array;
    cin >> n;

    for (int i = 0;i < n; i++){
        cin>>value;
        array.push_back(value);
    }
    sumsPrefix(array);
    for(int i = 0;i < n; i++){
        cout<<array[i]<<" ";
    }
    return 0;
}