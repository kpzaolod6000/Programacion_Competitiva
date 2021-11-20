#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> mbttmup(m,vector<int> (n,0));
    
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == 0 && j == 0) mbttmup[i][j] = 1;
            else if( i == 0)  mbttmup[i][j] = mbttmup[i][j-1];
            else if( j == 0)  mbttmup[i][j] = mbttmup[i-1][j];
            else mbttmup[i][j] = mbttmup[i-1][j] + mbttmup[i][j-1];
        }
        
    }
    return mbttmup[m-1][n-1];

}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;

    cin>>n>>m;


    cout<<uniquePaths(m,n)<<"\n";
    return 0;
    
}