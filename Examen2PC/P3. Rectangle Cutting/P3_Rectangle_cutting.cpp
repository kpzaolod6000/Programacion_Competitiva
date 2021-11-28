#include <bits/stdc++.h>

using namespace std;

int rectangle_Ctt(int m, int n){
    vector<vector<int>> dp_rectangles(m+1,vector<int>(n+1,0));

    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            if (i == j) dp_rectangles[i][j] = 0;
            else{
                int cnt = INT_MAX;
                for (size_t c = 1; c < j; c++)
                    cnt = min(cnt,1+dp_rectangles[i][j-c] + dp_rectangles[i][c]);
                for (size_t c = 1; c < i; c++)
                    cnt = min(cnt,1+dp_rectangles[i-c][j] + dp_rectangles[c][j]);
                dp_rectangles[i][j] = cnt;
                
            }
        }
        
    }
    

    
    return dp_rectangles[m][n];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;
    cin>>m>>n;
    cout<<rectangle_Ctt(m,n)<<"\n";


    return 0;

}
