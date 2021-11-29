
#include <bits/stdc++.h>

using namespace std;
//bottom up
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    for(size_t i =0; i< m; i++){
        for (size_t j=0; j< n; j++){
            if(obstacleGrid[i][j] == 1)
                obstacleGrid[i][j] = 0;
            else if(i==0 && j==0)
                obstacleGrid[i][j]=1;
            else if(i == 0 )
                obstacleGrid[i][j] = obstacleGrid[i][j-1];
            else if(j == 0 )
                obstacleGrid[i][j] = obstacleGrid[i-1][j];
            else
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
        }
    }
    return obstacleGrid[m-1][n-1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> arr = {{0,0,0},
                               {0,1,0},
                               {0,0,0}};
    cout<<uniquePathsWithObstacles(arr)<<"\n";
    return 0;
}