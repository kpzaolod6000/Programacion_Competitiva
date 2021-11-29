
#include <bits/stdc++.h>

using namespace std;

//bottom up
int climbStairs(int n) {
    vector<int> dp_stairs(n+1, 0);
    dp_stairs[0] = 1;
    dp_stairs[1] = 1;
    for(int i=2; i<=n; i++)
        dp_stairs[i] = dp_stairs[i-1]+dp_stairs[i-2];  
    return dp_stairs[n];
        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    cout<<climbStairs(n)<<"\n";
    return 0;
}