#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> MergekSortedLists(list<list<int>>& list_){
    
    priority_queue<int, vector<int>, greater<int>> ordered;

    for (auto sub : list_)
    {
        for(auto x : sub){
            ordered.push(x);
        }
    }
    return ordered;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;
    cin>>n;

    list<list<int>> list_;
    list<int> sublist;
    
  
    for (int i = 0; i < n; i++) {
  
        // number of elements in list
        cin>>m;
        for (int j = 0; j < m; j++) {
            cin>>num;
            sublist.push_back(num);
        }
  
  
        list_.push_back(sublist);
  
        // delete all elements from single_list
        sublist.erase(sublist.begin(),
                          sublist.end());
    }
    priority_queue<int, vector<int>, greater<int>> ordered = MergekSortedLists(list_);

    while (!ordered.empty())
    {
        cout<<ordered.top()<<" ";
        ordered.pop();
    }
    cout<<"\n";

    

    return 0;
    
}

