
#include <bits/stdc++.h>
using namespace std;


int knapsack(int n,int C,vector<int>& weight,vector<int>& value){

    int result;
    if(n == 0 || C == 0){
        //caso base
        result = 0;
    }
    else if(weight[n] > C){
        result = knapsack(n-1,C,weight,value);
    }else
    {
        int temp1 = knapsack(n-1,C,weight,value);
        int temp2 = value[n]+knapsack(n-1,C-weight[n],weight,value);

        result = max(temp1,temp2);
    }
    return result;
}

int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,C;
    cin>>n>>C;

    vector<int> weight(n+1);
    weight[0] = 0;
    for (size_t i = 1; i < n+1; i++) cin>>weight[i];
    
    vector<int> value(n);
    value[0] = 0;
    for (size_t i = 1; i < n+1; i++) cin>>value[i];
    
    // for (size_t i = 0; i < n+1; i++)
    // {
    //     cout<<weight[i]<<" ";
    // }
    
    

    cout<<knapsack(n,C,weight,value)<<"\n";
    return 0;
}