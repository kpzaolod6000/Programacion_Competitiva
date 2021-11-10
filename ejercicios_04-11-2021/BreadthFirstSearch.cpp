#include <bits/stdc++.h>
using namespace std;

void BreadthFirstSearch(vector<vector<int>>& grid,int i, int j){
    
    int n = grid.size();
    int m = grid[0].size();
    
    
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    grid[i][j] = 0;

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
            
            if ( (ir >= 0 && ir < n && jc >= 0 && jc < m) && grid[ir][jc] == -1){
                grid[ir][jc] = grid[r][c] + 1;
                search.push({ir,jc});
            }
        }
    }
    
}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>> grid_ = {   {-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1}};

    BreadthFirstSearch(grid_,1,2);

    for (size_t i = 0; i < grid_.size(); i++)
    {
        for (size_t j = 0; j < grid_[0].size(); j++)
        {
            cout<<grid_[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}