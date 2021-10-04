#include<iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> sumsPrefix(int array[],int n){
    
    int sum;
    int prev = array[0];
    vector<int> h;
    h.push_back(prev);
    for(int i=1; i<n;i++){
        sum =array[i] + prev;
        h.push_back(sum);
        prev = sum;
    }
    return h;
}
int showMultiple(int array[],int n,int k){
    
    int cnt = 0;
    vector<int> p;
    p = sumsPrefix(array,n+1);
    for(int i=0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }
    return cnt;
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