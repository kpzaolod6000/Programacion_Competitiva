#include <bits/stdc++.h>
using namespace std;

int stoneWall(vector<int>& H){
    stack<int> height;
    int cntBlock = 0;
    
    for (size_t i = 0; i < H.size(); i++)
    {
        while (!height.empty() && height.top()>H[i] ) height.pop();
        if (height.empty())
        {
            cntBlock++;
            height.push(H[i]);
        }
        else if(height.top() == H[i]){;}
        else if(height.top() < H[i]){
            cntBlock++;
            height.push(H[i]);
        }
    }
    return cntBlock;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;    
    cin>>n;
    vector<int> H(n);

    for (size_t i = 0; i < n; i++) cin>>H[i];
    
    // for(auto x : H) cout<<x<<" ";

    cout<<stoneWall(H)<<"\n";
    return 0;
    
}

