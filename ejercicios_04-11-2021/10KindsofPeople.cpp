#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> visited;

int talkingField(vector<vector<int>>& grid ,int i,int j,int x,int y,int iniVal){ 

    
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != iniVal  || visited[i][j] == 1){
        return 0;
    }
    if (i == x && j == y) return 1;
    

    visited[i][j] = 1;
    
    talkingField(grid,i+1,j,x,y,iniVal);
    talkingField(grid,i-1,j,x,y,iniVal);
    talkingField(grid,i,j+1,x,y,iniVal);
    talkingField(grid,i,j-1,x,y,iniVal);
    
    

}

string KindsofPeople10(vector<vector<int>>& grid, vector<int>& arr){
    
    int iniVal = grid[arr[0]][arr[1]];
    int endVal = grid[arr[2]][arr[3]];

    if (iniVal != endVal) return "neither";

    
    // image[sr][sc] = newColor;
    
    int isTrue = talkingField(grid,arr[0],arr[1],arr[2],arr[3],iniVal);

    if (iniVal == 0 && isTrue == 1) return "binary";
    else if (iniVal == 1  && isTrue == 1) return "decimal";
    return "neither";
}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    // vector<vector<int>> grid_ = {   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    //                                 {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}
    //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0}
    //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0}
    //                                 {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1}
    //                                 {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    //                                 {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    //                                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}
    //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    // vector<vector<int>> grid_ = {{1,1,0,0}};

    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid;
    grid.resize(n, vector<int>(m,-1));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }

    int q;
    cin>>q;
    vector<int> arr(4);
    int val;
    while (q--)
    {
        for (size_t i = 0; i < arr.size(); i++) {
            cin>>val; 
            arr[i] = val - 1;
        }
        cout<<KindsofPeople10(grid,arr)<<"\n";
    }
    cout<<"\n";
    return 0;
}