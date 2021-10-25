#include <bits/stdc++.h>
using namespace std;

int nesting(string& S){
    stack<int> parenth;
    char ch;
    for (size_t i = 0; i < S.size(); i++)
    {
        ch = S[i];
        if (ch == '(') parenth.push('(');
        else
        {
            if(parenth.empty() || parenth.top() != '(') return 0;
            else parenth.pop();
        }
    }
    return parenth.size() > 0 ? 0 : 1;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text;
    getline(cin, text);

    cout<<nesting(text)<<"\n";
    return 0;
    
}

