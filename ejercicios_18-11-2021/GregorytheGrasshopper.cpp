#include <bits/stdc++.h>
using namespace std;


int GregoryinAction(int m,int n,int r,int c,int gr,int gc){
    
    vector<int> posX ={-1, -1, -2, -2, 1, 1, 2, 2}; 
    vector<int> posY ={2, -2, 1, -1, 2, -2, 1, -1};

    vector<vector<int>> pass_(m, vector<int>(n, 0));
    pass_[r][c] = 1;
    

    queue<pair<int,int>> jumps{};
    jumps.push({r,c});

    while (!jumps.empty()) {

        pair<int,int> current = jumps.front();
        jumps.pop();
        int r_i = current.first;
        int c_i = current.second;
        
        int sum_;
        if(r_i == r && c_i == c) sum_ = 0;
        else sum_= pass_[r_i][c_i];

        for (size_t k = 0; k < 8; k++) {
                
            int ir = r_i + posX[k];
            int jc = c_i + posY[k];
            // cout<<ir<<" "<<jc<<"\n";
            if ( ir >= 0 && ir < m && jc >= 0 && jc < n){
                if (pass_[ir][jc] == 0)
                {
                    pass_[ir][jc] = sum_ + 1;
                    jumps.push({ir,jc});
                }
            }
        }
    }
    if (pass_[gr][gc] == 0) return -1;
    return pass_[gr][gc];
    
}



int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n,r,c,gr,gc;
    
    while (cin>>m && cin>>n && cin>>r && cin>>c && cin>>gr && cin>>gc)
    {
        int isV = GregoryinAction(m,n,r-1,c-1,gr-1,gc-1);
        if (isV == -1) cout<<"impossible\n";
        else cout<<isV<<"\n";
    } 
    
    return 0;
    
}