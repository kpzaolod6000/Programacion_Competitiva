#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findPivot(int array[],int n){
    int pivot = -1;
    for(int i=1; i<n-1;i++){
        int sumleft = 0,sumright = 0;
        for(int k=i+1; k<n;k++) sumleft += array[k];
        for(int l=0;l<i;l++) sumright += array[l];
        // cout << sumleft << " " << sumright << endl;
        if(sumleft == sumright){
            pivot = i;
        }
        
    }
    return pivot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,value;
    cin>>n;
    int array[n];
    for(int i=0; i<n;i++) cin>>array[i];
    cout<< findPivot(array,n);
    
    // for(int i=0; i<n;i++) cout<< array[i]<< " ";



    return 0;
}