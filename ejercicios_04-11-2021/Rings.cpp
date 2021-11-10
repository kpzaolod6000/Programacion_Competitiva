#include <bits/stdc++.h>
using namespace std;

void findOuterLayer(vector<vector<int>>& visited, vector<vector<char>>& grid ,int i,int j){

    int n = grid.size();
    int m = grid[0].size();
    
    
    
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    queue<pair<int,int>> search{};
    search.push({i,j});
    
    while (!search.empty()) {
        
        pair<int,int> current = search.front();
        search.pop();
        int r = current.first;
        int c = current.second;

        for (size_t k = 0; k < 4; k++) {
            
            int ir = r + posX[k];
            int jc = c + posY[k];
            
            // if (visited[r][c] == 1)
            // {
            // }

            if (ir < 0 && ir >= n && jc < 0 && jc >= m){
                // grid[ir][jc] = grid[r][c] + 1;
                // search.push({ir,jc});
                visited[r][c] == 1;
            }else if(grid[ir][jc] == '.'){
                visited[r][c] == 1;
            }else if(grid[ir][jc] == 'T'){
                search.push({ir,jc});
            }
        }
    }
    
}


vector<vector<int>> BreadthFirstSearch(vector<vector<char>>& grid){
    
    vector<vector<int>> visited;
    visited.resize(grid.size(), vector<int>(grid[0].size(), 0));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'T')
            {
                findOuterLayer(visited,grid,i,j);
            }
        }
        
    }
    return visited;
}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<char>> grid_ = {  {'.','T','T','.','.','.'},
                                    {'T','T','T','T','.','.'},
                                    {'T','T','T','T','T','.'},
                                    {'T','T','T','T','T','.'},
                                    {'T','T','T','T','T','T'},
                                    {'.','.','T','.','.','.'}};

    vector<vector<int>> result = BreadthFirstSearch(grid_);


    

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[0].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}