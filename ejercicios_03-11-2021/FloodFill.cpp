#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> visited;
 

void floodNeighbors(vector<vector<int>>& image ,int x,int y,int color,int tmp){ 
    
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != tmp || visited[x][y] == 1){
        return ;
    }
        
    image[x][y] = color;
    visited[x][y] = 1;
    floodNeighbors(image,x+1,y,color,tmp);
    floodNeighbors(image,x-1,y,color,tmp);
    floodNeighbors(image,x,y+1,color,tmp);
    floodNeighbors(image,x,y-1,color,tmp);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int tmp = image[sr][sc];
    // image[sr][sc] = newColor;
    floodNeighbors(image,sr,sc,newColor,tmp);
    return image;
}


int main(int argc, char const * argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // vector<vector<int>> grid_ = {   {0,0,1,1,0,0},
    //                                 {0,0,0,0,0,0},
    //                                 {0,0,0,0,0,0}};

    vector<vector<int>> grid_ = {   {1,1,1},
                                    {1,1,0},
                                    {1,0,1}};
    visited.resize(grid_.size(), vector<int>(grid_[0].size(), 0));//colocar dentro de la funcion en el leetcode OJO

    
    vector<vector<int>> image = floodFill(grid_,1,1,2);

    for(auto row: image){
        for(auto x:row){
            cout<< x <<" ";
        }
        cout<<"\n";
    }
    return 0;
}