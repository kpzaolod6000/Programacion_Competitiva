#include <bits/stdc++.h>
using namespace std;

void ToNeighbors(vector<vector<char>>& stars,int i, int j,int m,int n) {
 
    
    
    vector<int> posX ={-1, 0, 1, 0}; 
    vector<int> posY ={0, -1, 0, 1};

    stack<pair<int,int>> part{};
    part.push({i,j});
    stars[i][j] = '#';

    while (!part.empty()) {
        
        pair<int,int> current = part.top();
        part.pop();
        int r = current.first;
        int c = current.second;
        // cout<<r<<" "<<c<<"\n";

        for (size_t k = 0; k < 4; k++) {
                
            int ir = r + posX[k];
            int jc = c + posY[k];
            // cout<<ir<<" "<<jc<<"\n";
            if ( ir >= 0 && ir < m && jc >= 0 && jc < n){
                if (stars[ir][jc] == '-')
                {
                    part.push({ir,jc});
                    stars[ir][jc] = '#';
                }
            }
        }
    }
}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n,n_test = 0;
    

    while(cin>>m && cin>>n){
        
        n_test++;
        string line;
        vector<vector<char>> stars;

        int n_inpt = 0;
        while (n_inpt<m)
        {
            cin>>line;
            // cout<<line<<"\n";
            vector<char> col_(n);
            for (size_t i = 0; i < n; i++) col_[i] = (line[i]); 
            stars.push_back(col_);
            n_inpt++; 
        }
        
        int cnt = 0;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (stars[i][j] == '-')
                {
                    cnt++;
                    ToNeighbors(stars,i,j,m,n);
                }
                
            }
            
        }
        cout<<"Case "<<n_test<<": "<<cnt<<"\n";
        
    }
    
    return 0;
    
}