#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> parenth;
    parenth.push(s[0]);
    
    for (size_t i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        if(parenth.empty()) parenth.push(ch);
        else 
        {
            char ins = parenth.top();
            
            if (ins == ch || ch < ins) parenth.push(ch);
            else parenth.pop();
        }
               
    }
    return parenth.size();
    
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    string arr = "())";
    cout<<minAddToMakeValid(arr)<<"\n";
    
    string arr2 ="()))((";
    cout<<minAddToMakeValid(arr2)<<"\n";
    
    return 0;

}