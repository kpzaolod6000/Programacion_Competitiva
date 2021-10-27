#include <bits/stdc++.h>
using namespace std;

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n,citizen,h;
    cin>>n;
    stack<int> h_ord;
    stack<int> aux_;
    

    while (n--)
    {
        cin>>citizen;
        
        while (citizen--)
        {
            cin>>h;
            if (h_ord.empty()) h_ord.push(h);
            else
            {   
                while (!h_ord.empty() && h > h_ord.top())
                {
                    
                    aux_.push(h_ord.top());
                    h_ord.pop();
                }
                h_ord.push(h);
                while (!aux_.empty())
                {
                    h_ord.push(aux_.top());
                    aux_.pop();
                }
            }
        }
        while (!h_ord.empty())
        {
            cout<<h_ord.top()<<" ";
            h_ord.pop();
        }
        cout<<"\n";
    }
    
    return 0;
    
}
