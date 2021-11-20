#include <bits/stdc++.h>
using namespace std;

        
        
void dfs(vector<vector<int>>& heights, int i, int j, int prev,vector<vector<bool>>& ocean){
        
    vector<int> posX ={0, 0, 1, -1}; 
    vector<int> posY ={1, -1, 0, 0};

    if(i < 0 || i >= ocean.size() || j < 0 || j >= ocean[0].size()) return;
    
    if(heights[i][j] < prev || ocean[i][j]) return;
    ocean[i][j] = true;

    for (size_t k = 0; k < 4; k++)
    {
        dfs(heights, i+posX[k], j+posY[k], heights[i][j], ocean);
    }
    
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> output;
    if(n == 0 && m == 0) return output;

    vector<vector<bool>> pacific(n,vector<bool> (m,false));
    vector<vector<bool>> atlantic (n,vector<bool> (m,false));



    for (size_t i = 0; i < m; i++)
    {
        dfs(heights, 0, i, INT_MIN, pacific);
        dfs(heights, n-1, i, INT_MIN, atlantic);
        
    }
    

    for (size_t i = 0; i < n; i++)
    {
        dfs(heights, i, 0, INT_MIN, pacific);
        dfs(heights, i, m-1, INT_MIN, atlantic);
    }
    
       
    for(int i = 0; i < m; i++){
        vector<int> line_;
        int p = 0;
        for(int j = 0; j < n; j++) {
            if(pacific[i][j] && atlantic[i][j]) {
                line_.push_back(i);
                line_.push_back(j);
            }
        }
        if (line_.size() > 2)
        {
            vector<int> pos_;
            for (size_t l = 0; l < line_.size(); l++) 
            {
                pos_.push_back(line_[l]);
                if((l+1) % 2 == 0) {
                    output.push_back(pos_);
                    pos_.clear();      
                }
            }
            
        }else output.push_back(line_);
        
        
    }
    
    return output;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vector<vector<int>> heights = {{1,2,2,3,5},
    //                                {3,2,3,4,4},
    //                                {2,4,5,3,1},
    //                                {6,7,1,4,5},
    //                                {5,1,1,2,4}};
    vector<vector<int>> heights = {{2,1},
                                   {1,2}};

    vector<vector<int>> output = pacificAtlantic(heights);

    for(int i = 0; i < output.size(); i++){
        
        for(int j = 0; j < output[i].size(); j++) {
            cout<< output[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
    
}