#include <bits/stdc++.h>
using namespace std;



// bool contains(vector<int>& visited,int elem) { 
//     return find(begin(visited), end(visited), elem) != end(visited);
// };


// int calculateArea(vector<int>& visited,vector<vector<int>>& grid , int i,int j){ 
    
//     if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || contains(visited,i*grid.size()+j) == true){
//         return 0;
//     }

//     visited.push_back(i*grid.size()+j);
//     return (1 + calculateArea(visited,grid,i+1,j) + calculateArea(visited,grid,i-1, j) + calculateArea(visited,grid,i, j-1) + calculateArea(visited,grid,i, j+1));

// }


bool contains(vector<int>& visited,int elem) { 
    return find(begin(visited), end(visited), elem) != end(visited);
}

int calculateArea(vector<vector<int>>& grid , int i,int j){ 
 
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    int n = grid.size();
    stack<int> visited;
    vector<int> storeVisit;
    visited.push(i * n + j);
    storeVisit.push_back(i * n + j);

    while (!visited.empty()) {
        int index = visited.top();
        visited.pop();
        int i_ = index / n;
        int j_ = index % n;

        for (size_t k = 0; k < 4; ++k) {
            
            int ki_ = i_ + posX[k];
            int kj_ = j_ + posY[k];
            if (!contains(storeVisit,ki_* n + kj_) && ki_>= 0 && ki_ < n && kj_ >= 0 && kj_ < n && grid[ki_][kj_] == 1) {
                visited.push(ki_ * n + kj_);
                storeVisit.push_back(ki_ * n + kj_);
            }
        }
    }

    return storeVisit.size();
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
                // vector<int> visited(m*n,-1);
                maxArea = max(maxArea, calculateArea(grid,i,j));
                // for (size_t i = 0; i < visited.size(); i++)
                // {
                //     for (size_t j = 0; j < visited[i].size(); j++)
                //     {
                //         cout<<visited[i][j]<<" ";
                //     }
                //     cout<<"\n";    
                // }
                // cout<<maxArea<<"\n";
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

    // vector<vector<int>> grid_ = {   {1,0},
    //                                 {0,1}};
    // visited.resize(grid_.size(), vector<int>(grid_[0].size(), 0));//colocar dentro de la funcion en el leetcode OJO

    
    cout<<largestIsland(grid_)<<"\n";
    return 0;
}