
#include <bits/stdc++.h>
using namespace std;



int knapsack(int n,int C,vector<int>& weight,vector<int>& value,vector<vector<int>>& memo){

    int result;
    if (memo[n][C])
    {
        result = memo[n][C];
    }
    
    if(n == 0 || C == 0){
        //caso base
        result = 0;
    }
    else if(weight[n] > C){
        result = knapsack(n-1,C,weight,value,memo);
    }else
    {
        int temp1 = knapsack(n-1,C,weight,value,memo);
        int temp2 = value[n]+knapsack(n-1,C-weight[n],weight,value,memo);

        result = max(temp1,temp2);
    }
    memo[n][C] = result;
    return result;
}

int knapsack_Memorization(int n,int C,vector<int>& weight,vector<int>& value){
    
    int default_value = 0;
    vector<int> col_(C+1,default_value);
    vector<vector<int>> memo(n+1,col_);


    return knapsack(n,C,weight,value,memo);
    

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
    
    

    cout<<knapsack_Memorization(n,C,weight,value)<<"\n";
    return 0;
}

//otra forma de inicializar matrices

// vector<vector<int>> memo;
// memo.resize(n+1, vector<int>(C+1,default_value));

// for (size_t i = 0; i < n+1; i++)
// {
//     for (size_t j = 0; j < C+1; j++)
//     {
//         cout<<memo[i][j]<<" ";
//     }
//     cout<<"\n";
// }


// for (auto col : memo){
//     for(auto x:col){
//         cout<<x<<" ";
//     }
//     cout<<"\n";
// }
