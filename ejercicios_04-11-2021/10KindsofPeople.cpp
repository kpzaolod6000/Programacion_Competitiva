#include <bits/stdc++.h>
using namespace std;

// int main(int argc, char const * argv[]){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

    
//     // vector<vector<int>> grid_ = {   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//     //                                 {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}
//     //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0}
//     //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0}
//     //                                 {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1}
//     //                                 {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//     //                                 {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//     //                                 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1}
//     //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//     //                                 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
//     // vector<vector<int>> grid_ = {{1,1,0,0}};

//     int n,m;
//     cin>>n>>m;

//     vector<vector<int>> grid;
//     grid.resize(n, vector<int>(m,-1));

//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = 0; j < m; j++)
//         {
//             cin>>grid[i][j];
//         }
//     }

//     int q;
//     cin>>q;
//     vector<int> arr(4);
//     int val;
//     while (q--)
//     {
//         for (size_t i = 0; i < arr.size(); i++) {
//             cin>>val; 
//             arr[i] = val - 1;
//         }
//         cout<<KindsofPeople10(grid,arr)<<"\n";
//     }
//     cout<<"\n";
//     return 0;
// }

    
int main()
{
    int r,c;
    cin>>r>>c;
    
    char map[r][c+1];
    // vector<vector<int>> grid;
    // grid.resize(r, vector<int>(c,0));
    
    for (int i = 0; i < r; i++) scanf("%s", map[i]);
    
    int total = r * c;
    int next_group = 1;
    int *group = (int*)calloc((size_t)total, sizeof(int));
    short one = 1;

    stack<pair<int,int>> open{};
    // open.push(total*2^2)
    // stack open;
    // init(&open, total<<2);

    int q;
    cin>>q;
    // scanf("%d",&q);

    while (q--)
    {
        short r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        // scanf("%hi %hi %hi %hi",&r1,&c1,&r2,&c2);
        r1--; c1--; r2--; c2--;
        int dim_one_1 = r1 * c + c1;
        int dim_one_2 = r2 * c + c2;

        if (dim_one_1 == dim_one_2){
            if (map[r1][c1] == '1')
            {
                cout<<"decimal\n";
            }else{
                cout<<"binary\n";
            }
            
        }
        else if (group[dim_one_1] == 0 && group[dim_one_2] == 0)
        {
            // DFS
            open.push({r1,c1});
            // push(&open, r1, c1);
            while (!open.empty())
            {
                pair<int,int> current = open.top();
                open.pop();
                short curr_x = current.first;
                short curr_y = current.second;
                // point* curr = pop(&open);
                // short  = curr->x,  = curr->y;
                char curr_val = map[curr_x][curr_y];
                int dim_one = curr_x * c + curr_y;
                if (group[dim_one]) continue;
                group[dim_one] = next_group;
                if (curr_x > 0 && map[curr_x-1][curr_y] == curr_val && !group[(curr_x-1)*c+curr_y]) open.push({curr_x-one, curr_y});
                if (curr_x < r - 1 && map[curr_x+1][curr_y] == curr_val && !group[(curr_x+1)*c+curr_y]) open.push({curr_x+one, curr_y});
                if (curr_y > 0 && map[curr_x][curr_y-1] == curr_val && !group[curr_x*c+curr_y-1]) open.push({curr_x, curr_y-one});
                if (curr_y < c - 1 && map[curr_x][curr_y+1] == curr_val && !group[curr_x*c+curr_y+1]) open.push({curr_x, curr_y+one});
            }
            next_group++;
            printf(group[dim_one_2] ? (map[r1][c1] == '1' ? "decimal\n" : "binary\n") : ("neither\n"));
        }
        else if (map[r1][c1] != map[r2][c2]) printf("neither\n");
        else if (group[dim_one_1] == group[dim_one_2]) printf(map[r1][c1] == '1' ? "decimal\n" : "binary\n");
        else printf("neither\n");
    }

    return 0;
}