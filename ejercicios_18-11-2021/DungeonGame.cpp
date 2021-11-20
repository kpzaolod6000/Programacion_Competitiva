#include <bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    
    int m = dungeon.size();
    int n = dungeon[0].size();
    queue<pair<int,int>> idx;
    queue<int> cache_;

    vector<int> posX = {0,1};
    vector<int> posY = {1,0};
    vector<vector<int>> gridCache(m,vector<int> (n,0));
    
    gridCache[0][0] = dungeon[0][0];
    idx.push({0,0});
    cache_.push(gridCache[0][0]);
    
    while (!cache_.empty())
    {
        pair<int,int> current = idx.front();
        int r = current.first;
        int c = current.second;
        idx.pop();
        int sum = cache_.front();
        cache_.pop();

        for (size_t k = 0; k < 2; k++)
        {
            int ir = r + posX[k];
            int jc = c + posY[k];
            if (ir < m && jc < n)
            {
                int sum_ = gridCache[r][c] + dungeon[ir][jc];
                if (gridCache[ir][jc] == 0)
                {
                    gridCache[ir][jc] = sum_;
                    idx.push({ir,jc});
                    cache_.push(sum_);
                }else{
                    if (gridCache[ir][jc] < 0 && sum_ < 0)
                    {
                        if(sum_ > gridCache[ir][jc]){
                            gridCache[ir][jc] = sum_;
                            idx.push({ir,jc});
                            cache_.push(sum_);
                        }
                    }else
                    {
                        if(sum_ < gridCache[ir][jc]){
                            gridCache[ir][jc] = sum_;
                            idx.push({ir,jc});
                            cache_.push(sum_);
                        }
                        
                    }
                }
            }
            
        }
    }

    if(gridCache[m-1][n-1]>=0){
        if(gridCache[0][0] > 0) return 1;
        else return (gridCache[0][0]*-1) + 1;
        
    }
    return (gridCache[m-1][n-1] * -1) + 1;
}


int calculateMinimumH(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>>gridCache (m,vector<int>(n,0));

    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1)
                gridCache[i][j] = min(0,dungeon[i][j]);
            else if(i==m-1)
                gridCache[i][j] = min(0,dungeon[i][j]+gridCache[i][j+1]);
            else if(j==n-1)
                gridCache[i][j] = min(0,dungeon[i][j]+gridCache[i+1][j]);
            else
                gridCache[i][j] = min(0,dungeon[i][j]+max(gridCache[i+1][j],gridCache[i][j+1]));
        }
    }
    return abs(gridCache[0][0])+1;      
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> dungeon ={{-2,-3,3},
                                  {-5,-10,1},
                                  {10,30,-5}};


    //vector<vector<int>> dungeon ={{-3,5}};

    cout<<calculateMinimumHP(dungeon)<<"\n";
    cout<<calculateMinimumH(dungeon)<<"\n";
    
    return 0;
    
}