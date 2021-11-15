#include <bits/stdc++.h>
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    char grid[n][m+1];
    
    for (int i = 0; i < n; i++) scanf("%s", grid[i]);

    
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
            
            int val = grid[r][c] - '0';
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