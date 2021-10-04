#include<iostream>
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

int showMultiple(int array[],int n,int k){

    int count = 0;
    int N = n;
    vector<int> p;
    sumsPrefix(p);
    for (size_t i = 0; i < p.size(); i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"\n";
    
    // int cnt = 0;
    // for(int i=0; i<n; i++){
    //     int sum = 0;
    //     for(int j=i; j<n; j++){
    //         sum+=array[j];
    //         if(sum%k == 0){
    //             cnt++;
    //         }
    //     }
    // }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,value,k;
    cin>>n>>k;
    int array[n];
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }
    cout << showMultiple(array,n,k)<<"\n";

    return 0;
}