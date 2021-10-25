#include <bits/stdc++.h>
using namespace std;

int brackets(string& S){
    
    stack<int> N_oper;
    char ch;
    if (S.empty()) return 1;

    for (size_t i = 0; i < S.size(); i++)
    { 
        switch (S[i]){
            case '(':
                N_oper.push(')');
                break;
            case '[':
                N_oper.push(']');
                break;
            case '{':
                N_oper.push('}');
                break;
            default:
                if (N_oper.empty()) return 0;
                else
                {
                    ch = S[i];
                    if (ch != N_oper.top()) return 0;
                    N_oper.pop();
                }
                break;
        }
    }

    return N_oper.size() > 0 ? 0 : 1;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // int n;
    // cin>>n;

    string text;
    getline(cin, text);

    // cout<<text<<"\n";
    
    cout<<brackets(text)<<"\n";
    return 0;
    
}

