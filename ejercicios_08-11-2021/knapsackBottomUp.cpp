
#include <bits/stdc++.h>
using namespace std;

int knapsack_Bottomup(int n,int C,vector<int>& weight,vector<int>& value){
    
    int default_value = 0;
    vector<int> col_(C+1,default_value);
    vector<vector<int>> memo(n+1,col_);

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= C; j++)
        {
            if(weight[i] > j){
                memo[i][j] = memo[i-1][j];
            }else
            {
                int temp1 = memo[i-1][j];
                int temp2 = value[i] + memo[i-1][j-weight[i]];
                memo[i][j]= max(temp1,temp2);
            }
            
        }
        
    }
    return memo[n][C];
    
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
    

    cout<<knapsack_Bottomup(n,C,weight,value)<<"\n";
    return 0;
}
