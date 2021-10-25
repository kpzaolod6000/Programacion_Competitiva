#include <bits/stdc++.h>
using namespace std;
int fish(vector<int>& A,vector<int>& B){
    if (A.size() == 0) return 0;
    
    stack<int> fishDepretator;
    int fishLive = A.size();
    for (size_t i = 0; i < A.size(); i++)
    {
        if(B[i] == 1){
            fishDepretator.push(A[i]);
        }
        else //B[i] == 0
        {
            while (!fishDepretator.empty())
            {
                if (fishDepretator.top() > A[i])
                {
                    fishLive--;
                    break;
                }else if (fishDepretator.top()<A[i]){
                    fishLive--;
                    fishDepretator.pop();
                }
                
            }
            
        }
    }
    return fishLive;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    for (size_t i = 0; i < n; i++) cin>>A[i];
    for (size_t i = 0; i < n; i++) cin>>B[i];
    
    cout<<fish(A,B)<<"\n";
    return 0;
    
}

