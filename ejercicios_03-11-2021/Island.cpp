#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> visited;
int calculateArea(vector<vector<char>>& grid , int i,int j){ 

    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 'W' || visited[i][j] == 1){
        return 0;
    }

    visited[i][j] = 1;
    return (1 + calculateArea(grid,i+1,j) + calculateArea(grid,i-1, j) + calculateArea(grid,i, j-1) + calculateArea(grid,i, j+1));

}

int Island(vector<vector<char>>& grid){

    int m = grid.size();
    int n = grid[0].size();
    int cntIsland = 0;
    bool hasEarth = false;

    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (grid[i][j] == 'L')
            {
                hasEarth = true;
                if (calculateArea(grid,i,j) != 0)
                {
                    for (size_t i = 0; i < visited.size(); i++)
                    {
                        for (size_t j = 0; j < visited[i].size(); j++)
                        {
                            cout<<visited[i][j]<<" ";
                        }
                        cout<<"\n";
                    }

                    cntIsland++;
                }
            }

        }

    }
    return hasEarth ? cntIsland : 0;

}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<char>> grid;
    grid.resize(n, vector<char>(m,' '));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
        
    }
    
    // for (size_t i = 0; i < grid.size(); i++)
    // {
    //     for (size_t j = 0; j < grid[i].size(); j++)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    visited.resize(n, vector<int>(m, 0));
    cout<<Island(grid)<<"\n";
    return 0;
}