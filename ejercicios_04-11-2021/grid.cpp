#include <bits/stdc++.h>
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int n_inpt = 0;
    //char grid[n][m+1];
    
    string line;
    vector<vector<int>> grid;

    while (n_inpt<n)
    {
        cin>>line;
        // cout<<line<<"\n";
        vector<int> col_(m);
        for (size_t i = 0; i < m; i++) col_[i] = (line[i] - '0'); 
        grid.push_back(col_);
        n_inpt++; 
    }


    vector<vector<int>> sum_;
    sum_.resize(n, vector<int>(m, -1));

    
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    // grid[i][j] = 0;

    queue<pair<int,int>> search{};
    search.push({0,0});
    sum_[0][0] = 0;
    
    while (!search.empty()) {
        
        pair<int,int> current = search.front();
        search.pop();
        int r = current.first;
        int c = current.second;
        // cout<<r<<" "<<c<<"\n";

        for (size_t k = 0; k < 4; k++) {
            
            int val = grid[r][c];
            int ir = r + (val * posX[k]);
            int jc = c + (val * posY[k]);
            // cout<<ir<<" "<<jc<<"\n";
            if ( ir >= 0 && ir < n && jc >= 0 && jc < m){
                
                if (sum_[ir][jc] == -1)
                {
                    search.push({ir, jc});
                    sum_[ir][jc] = sum_[r][c] + 1;
                }
            }
        }
    }

    // for (size_t i = 0; i < n; i++)
    // {
    //     for (size_t j = 0; j < m; j++)
    //     {
    //         cout<<sum_[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<sum_[n-1][m-1]<<"\n";
    return 0;
}