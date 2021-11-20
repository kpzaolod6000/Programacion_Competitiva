#include <bits/stdc++.h>
using namespace std;


int countCoast(vector<vector<char>>& grid,int i, int j){
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};
    int sum_ = 0;

    for (size_t k = 0; k < 4; k++) {
            
        int ir = i + posX[k];
        int jc = j + posY[k];
        if (grid[ir][jc] == 'M')
        {
            sum_++;
        }
        
    }
    return sum_;
}

int CoastLength(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    
    queue<pair<int,int>> celAdjacent{};
    celAdjacent.push({0,0});

    while (!celAdjacent.empty())
    {
        pair<int,int> current = celAdjacent.front();
        celAdjacent.pop();
        int r = current.first;
        int c = current.second;
        grid[r][c] = 'M';

        for (size_t k = 0; k < 4; k++) {
                
            int ir = r + posX[k];
            int jc = c + posY[k];
            // cout<<ir<<" "<<jc<<"\n";
            if (( ir >= 0 && ir < m && jc >= 0 && jc < n) && grid[ir][jc] == '0'){
                celAdjacent.push({ir,jc});
            }
        }
    }
        

    int sum_ = 0;

    for (size_t i = 1; i <= m-2; i++)
    {
        for (size_t j = 1; j <= n-2; j++)
        {
            if(grid[i][j] == '1') sum_ += countCoast(grid,i,j);
        }
    }
    

    return sum_;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;
    cin>>m>>n;

    vector<vector<char>> grid;
    grid.resize(m+2, vector<char>(n+2, '0'));

    // Read in data
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    cout<<CoastLength(grid)<<"\n";
    return 0;
    
}