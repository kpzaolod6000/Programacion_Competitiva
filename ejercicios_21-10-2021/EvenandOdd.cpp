#include <bits/stdc++.h>
using namespace std;

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int> > even;
    priority_queue<int> odd;
  
    int n,val;
    cin>>n;

    for (size_t i = 0; i < n; i++)
    {
        cin>>val;
        // if(numOrder.empty()) numOrder.push(val)
        if (val % 2 == 0 ) even.push(val);
        else odd.push(val);
    }
    while(!even.empty()){
        cout << even.top() << "\n";
        even.pop();
    }
    while(!odd.empty()){
        cout << odd.top() << "\n";
        odd.pop();
    }
    return 0;
    
}

