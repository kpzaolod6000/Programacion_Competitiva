#include<iostream>
#include <bits/stdc++.h>


using namespace std;

int showMultiple(int array[],int n,int k){
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        
        for(int j = i ; j < n; j++ ){
            cout<<"[ ";
            int sums = 0;
            for (int l = i ; l <= j; l++){
                cout<<array[l]<<" ";
                sums += array[l];
            }
            cout<<"] ";
            if (sums % k == 0) cnt++;
        }
        cout<<"\n";  
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