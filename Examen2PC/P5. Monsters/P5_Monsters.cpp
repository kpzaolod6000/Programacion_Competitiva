#include <bits/stdc++.h>
using namespace std;

//BFS
void Monsters(vector<vector<char>>& labyrinth){
    
    vector<int> posX ={-1,1, 0, 0}; 
    vector<int> posY ={0,0, 1, -1};
    vector<int> toWalk = {'U', 'D', 'R', 'L'};
    
    int m = labyrinth.size() , n = labyrinth[0].size();
    vector<vector<int>> pathA (m,vector<int> (n,8));

    queue<pair<int,int>> monsters{};

    int posxA;
    int posyA;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (labyrinth[i][j] == 'A')
            {
                posxA = i;
                posyA = j;
                pathA[i][j] = -1;// mi posicion 
            }
            else if (labyrinth[i][j] == 'M')
            {
                monsters.push({i,j});
            }
        }
        
    }

    monsters.push({posxA,posyA});//nuestro posicion al ultimo para dar prioridad el movimiento del monstruo
    while (!monsters.empty()) {
        
        pair<int,int> current = monsters.front();
        monsters.pop();
        int r = current.first;
        int c = current.second;
        // cout<<r<<" "<<c<<"\n";
        if (labyrinth[r][c] == 'A' && (r == 0 || r == m-1 || c == 0 || c == n-1)) // si A esta en los bordes limitrofes
        {
            cout<<"YES\n";
            int pos = pathA[r][c];
            stack<char> pathResult;
            while (pos != -1)
            {
                pathResult.push(toWalk[pos]);
                r -= posX[pos];// retroceder
                c -= posY[pos];// retroceder
                pos = pathA[r][c];
            }
            cout<<pathResult.size()<<"\n";
            while (!pathResult.empty())
            {
                cout<<pathResult.top();
                pathResult.pop();
            }
            cout<<"\n";
            return ;

        }
        

        for (size_t k = 0; k < 8; k++) {
                
            int ir = r + posX[k];
            int jc = c + posY[k];
            // cout<<ir<<" "<<jc<<"\n";
            if (( ir >= 0 && ir < m && jc >= 0 && jc < n) && labyrinth[ir][jc] == '.') {
                labyrinth[ir][jc] = labyrinth[r][c];
                if (labyrinth[ir][jc] == 'A') pathA[ir][jc] = k;
                monsters.push({ir,jc});
            }
        }
    }
    cout<<"NO\n";
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;
    cin>>m>>n;

    string line;
    vector<vector<char>> labyrinth;

    int n_inpt = 0;
    while (n_inpt<m)
    {
        cin>>line;
        // cout<<line<<"\n";
        vector<char> col_(n);
        for (size_t i = 0; i < n; i++) col_[i] = (line[i]); 
        labyrinth.push_back(col_);
        n_inpt++; 
    }

    Monsters(labyrinth);
    // for (auto &&i : labyrinth)
    // {
    //     for (auto &&x : i)
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    
    return 0;
    
}