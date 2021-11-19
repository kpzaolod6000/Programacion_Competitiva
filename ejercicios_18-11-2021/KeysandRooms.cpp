#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {

    stack<int> keys;
    keys.push(0);
    unordered_map<int,int> visited;

    for (size_t i = 0; i < rooms.size(); i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;

    while (!keys.empty())
    {
        int idroom = keys.top();
        keys.pop();

        vector<int> room = rooms[idroom];

        for (size_t ky = 0; ky < room.size(); ky++)
        {
            if (visited[room[ky]] == 0)
            {
                visited[room[ky]] = 1;
                keys.push(room[ky]);
            }
            
        }
    }

    int all_ = 0;

    for (auto x : visited)
    {
        if(x.second == 1) all_++;
    }

    if(all_ == rooms.size()) return true;
    return false;
        
}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> kRooms = {{1},
                                  {2},
                                  {3},
                                  {}};

    cout<<canVisitAllRooms(kRooms)<<"\n";
    
    return 0;
    
}


