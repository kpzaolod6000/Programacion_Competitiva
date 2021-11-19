#include <bits/stdc++.h>
using namespace std;

void ToNeighbors(vector<vector<char>>& amoebas,int i, int j,int m,int n) {
 
    
    
    vector<int> posX ={-1, 0, 1, 0, 1, -1, 1, -1}; 
    vector<int> posY ={0, -1, 0, 1, 1, 1, -1, -1};

    stack<pair<int,int>> partAme{};
    partAme.push({i,j});
    amoebas[i][j] = '.';

    while (!partAme.empty()) {
        
        pair<int,int> current = partAme.top();
        partAme.pop();
        int r = current.first;
        int c = current.second;
        // cout<<r<<" "<<c<<"\n";

        for (size_t k = 0; k < 8; k++) {
                
            int ir = r + posX[k];
            int jc = c + posY[k];
            // cout<<ir<<" "<<jc<<"\n";
            if ( ir >= 0 && ir < m && jc >= 0 && jc < n){
                if (amoebas[ir][jc] == '#')
                {
                    partAme.push({ir,jc});
                    amoebas[ir][jc] = '.';
                }
            }
        }
    }
}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;
    cin>>m>>n;

    string line;
    vector<vector<char>> amoebas;

    int n_inpt = 0;
    while (n_inpt<m)
    {
        cin>>line;
        // cout<<line<<"\n";
        vector<char> col_(n);
        for (size_t i = 0; i < n; i++) col_[i] = (line[i]); 
        amoebas.push_back(col_);
        n_inpt++; 
    }
    
    int cnt = 0;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (amoebas[i][j] == '#')
            {
                cnt++;
                ToNeighbors(amoebas,i,j,m,n);
            }
            
        }
        
    }
    cout<<cnt<<"\n";


    
    // for(auto line_ : amoebas){
    //     for (auto x : line_)
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
    
}