#include <bits/stdc++.h>
using namespace std;



void DFS(vector<vector<int>> G,int s){
    stack<int> nod_visit;
    nod_visit.push(s);
    unordered_map<int,int> visited;

    for (size_t i = 0; i < G.size(); i++)
    {
        visited[i] = 0;
    }
    visited[s] = 1;

    while (!nod_visit.empty())
    {
        
        int v = nod_visit.top();
        cout<<v<<" ";
        nod_visit.pop();

        // for (size_t j = 0; j < G[v].size(); j++)
        for (int j = G[v].size()-1; j >= 0 ; j--)
        {
            
            if(G[v][j] != 0 ){
                if (visited[j] == 0 ) //  w is not visited
                {
                    nod_visit.push(j);
                }
                visited[j] = 1;
            }
            
        }
    }
    cout<<"\n";
    
    // for (auto& x: visited) {
    //     cout << "Element [" << x.first << ":" << x.second << "]\n";
    // }

}

// int maxAreaOfIsland(vector<vector<int>>& grid){
//     int m = grid.size();
//     int n = grid[0].size();
//     int maxArea = 0;

//     for (size_t i = 0; i < m; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             if (grid[i][j] == 1)
//             {
//                 maxArea = max(maxArea, dfs(grid,i,j))
//             }
            
//         }
        
//     }
//     return maxArea;

// }



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
    
    int q;
    cin>>q;

    int N_nodos,
    vector<int> arr(4);

    while (q--)
    {
        for (size_t i = 0; i < arr.size(); i++) cin>>arr[i]; 
    }
    

    DFS(test_,0);

    // for (size_t i = 0; i < grid_.size(); i++)
    // {
    //     for (size_t j = 0; j < grid_[i].size(); j++)
    //     {
    //         cout<<grid_[i][j]<<" ";
    //     }
    //     cout<<"\n";    
    // }
    

    // cout<<DisastrousDowntime(arr,k);

    // for(auto elem : arr){
    //     cout<<elem<<" ";
    // }
    cout<<"\n";
    return 0;
}