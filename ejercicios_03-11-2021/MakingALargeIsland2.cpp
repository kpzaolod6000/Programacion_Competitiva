#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> visited;
int calculateArea(vector<vector<int>>& visited,vector<vector<int>>& grid , int i,int j){ 

    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j] == 1){
        return 0;
    }

    visited[i][j] = 1;
    return (1 + calculateArea(visited,grid,i+1,j) + calculateArea(visited,grid,i-1, j) + calculateArea(visited,grid,i, j-1) + calculateArea(visited,grid,i, j+1));

}

int largestIsland(vector<vector<int>>& grid){

    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;
    bool hasZero = false;

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = 1;
                hasZero = true;
                vector<vector<int>> visited;
                visited.resize(grid.size(), vector<int>(grid[0].size(), 0));
                maxArea = max(maxArea, calculateArea(visited,grid,i,j));
                grid[i][j] = 0;
            }

        }

    }
    return hasZero ? maxArea : m*n;

}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>> grid_ = {   {0,0,0,0,0,0,0},
                                    {0,1,1,1,1,0,0},
                                    {0,1,0,0,1,0,0},
                                    {1,0,1,0,1,0,0},
                                    {0,1,0,0,1,0,0},
                                    {0,1,0,0,1,0,0},
                                    {0,1,1,1,1,0,0}};

    
    cout<<largestIsland(grid_)<<"\n";
    return 0;
}