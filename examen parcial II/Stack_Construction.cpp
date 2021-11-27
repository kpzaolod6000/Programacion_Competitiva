#include <bits/stdc++.h>

using namespace std;

int stackConstruction(string arr,stack<char> contents) {
    
    int n = arr.size();
    if(n == 1) return 3;
    unordered_map<char,int> memo;
    
    for (size_t i = 0; i < n; i++)
    {
        memo[arr[i]] = 0;
    }
    // for (auto x : memo)
    // {
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
    
    int min_cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (memo[arr[i]] == 0)
        {
            contents.push(arr[i]);
            min_cnt++;
            memo[arr[i]] = 1;
        }else
        {
            while (!contents.empty() && contents.top() != arr[i]){
                memo[contents.top()] = 0;
                contents.pop();
                min_cnt++;
            }
            // memo[arr[i]] = 0;
        }
        min_cnt++;
    }
    
    while(!contents.empty())
    {
        contents.pop();
        min_cnt++;
    }
    
    return min_cnt;

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;

    cin.ignore();
    while (q--)
    {
        string arr;
        
        getline(cin,arr);
        stack<char> contents;
        cout<<stackConstruction(arr,contents)<<endl;
    }
    
    return 0;
}
