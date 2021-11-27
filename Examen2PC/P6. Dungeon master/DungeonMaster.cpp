#include <bits/stdc++.h>
using namespace std;

class Positions{
public:
    int x, y, z;
    Positions(){};
    Positions(int x_,int y_,int z_) : x(x_),y(y_),z(z_){}
    ~Positions(){};
};

Positions* pos_start = new Positions();
Positions* pos_end = new Positions();

//BFS
void DungeonMaster(int m,int n,int o,vector<vector<vector<char>>>& dungeon, vector<vector<vector<int>>>& memo){
    
    vector<int> posX ={-1,1, 0,0, 0,0}; 
    vector<int> posY ={ 0,0,-1,1, 0,0};
    vector<int> posZ ={ 0,0, 0,0,-1,1};
   
   
    queue<Positions*> my_pos; //mi posicion
    my_pos.push(pos_start);

    while (!my_pos.empty()) {
        
        Positions* current = my_pos.front();
        my_pos.pop();
        int r = current->x;
        int c = current->y;
        int p = current->z;
       
        for (size_t k = 0; k < 6; k++) {
                
            int ir = r + posX[k];
            int jc = c + posY[k];
            int kp = p + posZ[k];
            // cout<<ir<<" "<<jc<<"\n";
            if (( ir >= 0 && ir < m && jc >= 0 && jc < n && kp >=0 && kp < o) && memo[ir][jc][kp] == -2) {
                memo[ir][jc][kp] = memo[r][c][p] + 1;
                my_pos.push(new Positions(ir,jc,kp));
            }
        }
    }
    if(memo[pos_end->x][pos_end->y][pos_end->z] < 0) {
        cout << "Trapped!" << endl;
    }
    else {
        cout << "Escaped in " << memo[pos_end->x][pos_end->y][pos_end->z]  << " minute(s)." << endl;
    }
    
 
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n,o;
    while (cin>>m >> n >>o)
    {
        if(m == 0 || n == 0 || o == 0) break;
        
        vector<vector<vector<char>>> dungeon(m,vector<vector<char>> (n,vector<char> (o,'.')));
        vector<vector<vector<int>>> memo(m,vector<vector<int>> (n,vector<int> (o,-2)));
        // for (size_t i = 0; i < m; i++)
        // {
        //     for (size_t j = 0; j < n; j++)
        //     {
        //         for (size_t k = 0; k < o; k++)
        //         {
        //             cout<<dungeon[i][j][k];
        //         }
        //         cout<<" ";
        //     }
        //     cout<<"\n";
        // }
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                for (size_t k = 0; k < o; k++)
                {
                    char ch;
                    cin>>ch;
                    

                    if(ch == '#') {
                        dungeon[i][j][k] = '#';
                        memo[i][j][k] = -1;
                    }
                    else if(ch == 'S') {
                        dungeon[i][j][k] = 'S';
                        memo[i][j][k] = 0;
                        pos_start->x = i;
                        pos_start->y = j;
                        pos_start->z = k;
                    }
                    else if(ch == 'E') {
                        dungeon[i][j][k] = 'E';
                        pos_end->x = i;
                        pos_end->y = j;
                        pos_end->z = k;
                    }
                    //dungeon[i][j][k] = ch;
                }
            }
        }
        //cout<<pos_end->x <<" "<<pos_end->y<<" "<<pos_end->z<<endl;
        // cout<<"resulta"<<endl;
        // for (size_t i = 0; i < m; i++)
        // {
        //     for (size_t j = 0; j < n; j++)
        //     {
        //         for (size_t k = 0; k < o; k++)
        //         {
        //             cout<<dungeon[i][j][k];
        //         }
        //         cout<<"\n";
        //     }
        //     cout<<"\n";
        // }
        DungeonMaster(m,n,o,dungeon,memo);
        //break;
    }
    
    return 0;
    
}