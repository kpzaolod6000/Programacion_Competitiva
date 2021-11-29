#include <bits/stdc++.h>

using namespace std;

  int minFallingPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int dp_grid[m][n];
        if(grid.size()==1) return grid[0][0];
        
        for(size_t i=0; i<m;i++) dp_grid[0][i]=grid[0][i];
        
        for(size_t i=1;i<m;i++)
        {
            for(size_t j=0;j<n;j++)
            {
                int min_;
                min_=INT_MAX;
              
                   for(int l=0;l<n;l++)
                    {
                       
                       if(l==j) continue;
                       else min_=min(min_,dp_grid[i-1][l]);
                    }
                dp_grid[i][j]=grid[i][j]+min_;
                
              
                
            }
        }
        int min_=INT_MAX;
        
        for(int i=n-1;i>=0;i--)
        {
            min_=min(min_,dp_grid[m-1][i]);
        }
        return min_;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> arr = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    cout<<minFallingPathSum(arr)<<"\n";
    return 0;
}