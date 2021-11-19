#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
 
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    
    int m = grid.size();
    int n = grid[0].size();
    
    stack<pair<int,int>> storeE{};
    
    
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i == 0 || (m-1) == i) storeE.push({i,j});
                else if (j == 0 || (n-1) == j) storeE.push({i,j});
            }
        }
        
    }
    
    while (!storeE.empty())
    {
        
        pair<int,int> current = storeE.top();
        storeE.pop();
        
        int r = current.first;
        int c = current.second;

        grid[r][c] = 0;
        
        for (size_t k = 0; k < 4; k++) {
            
            int ir = r + posX[k];
            int jc = c + posY[k];
            if ((ir >= 0 && ir < m && jc >= 0 && jc < n) && grid[ir][jc] == 1)
            {
                storeE.push({ir,jc});
            }
            
        }
    }

    int sumE = 0;

    for( auto line : grid){
        for (auto x : line){
            if (x == 1) sumE++;
        }
    }

    return sumE;

}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vector<vector<int>> grid = {{0,0,0,0},
    //                             {1,0,1,0},
    //                             {0,1,1,0},
    //                             {0,0,0,0},};

    vector<vector<int>> grid = {{0,0,1,1,1,0,1,1,1,0,1},
                                {1,1,1,1,0,1,0,1,1,0,0},
                                {0,1,0,1,1,0,0,0,0,1,0},
                                {1,0,1,1,1,1,1,0,0,0,1},
                                {0,0,1,0,1,1,0,0,1,0,0},
                                {1,0,0,1,1,1,0,0,0,1,1},
                                {0,1,0,1,1,0,0,0,1,0,0},
                                {0,1,1,0,1,0,1,1,1,0,0},
                                {1,1,0,1,1,1,0,0,0,0,0},
                                {1,0,1,1,0,0,0,1,0,0,1}};
 
    cout<<numEnclaves(grid)<<"\n";
    return 0;
    
}


