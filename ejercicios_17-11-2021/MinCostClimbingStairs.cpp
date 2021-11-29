
#include <bits/stdc++.h>

using namespace std;

//bottom up
int minCostClimbingStairs(vector<int>& cost) 
{
    int n = cost.size();
    vector<int>dp_stairs(n);
    
    dp_stairs[0] = cost[0];
    dp_stairs[1] = cost[1];
    
    for(size_t i=2; i<n; i++)
    {
        dp_stairs[i] = cost[i] + min(dp_stairs[i-1], dp_stairs[i-2]);
    }
    
    return min(dp_stairs[n-1], dp_stairs[n-2]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> cost(n);

    for(size_t i=0; i<n; i++) cin>>cost[i];
   
    cout<<minCostClimbingStairs(cost)<<"\n";
    return 0;
}