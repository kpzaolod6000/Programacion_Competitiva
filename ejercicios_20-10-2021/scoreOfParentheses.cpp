#include <bits/stdc++.h>
using namespace std;

int score_OfParentheses(string s) {
    
    stack<int> parenthBalanced;
    int score_ = 0;
    char ch;
    
    for (size_t i = 0; i < s.size(); i++)
    {
        ch = s[i];
        if (ch == '(')
        {
            parenthBalanced.push(score_);
            score_ = 0;
        }else{
            score_ = parenthBalanced.top() + max(score_*2,1);
            parenthBalanced.pop();
        }
    }

    return score_;

    
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string arr ="()()";
    cout<<score_OfParentheses(arr)<<"\n";

    string arr2 ="(()(()))";
    cout<<score_OfParentheses(arr2)<<"\n";

    return 0;

}