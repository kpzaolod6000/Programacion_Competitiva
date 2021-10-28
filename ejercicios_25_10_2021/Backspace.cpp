#include <bits/stdc++.h>
using namespace std;

deque<char> Backspace(string& S) {
    deque<char> t;
    char ch;

    for (size_t i = 0; i < S.size(); i++)
    {
        ch = S[i];
        if (ch != '#')
        {
            t.push_back(ch);
        }else{
            t.pop_back();
        }
        
    }

    return t;
}

int main ()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text = "abc#de##f#ghi#jklmn#op#";
    
    
    deque<char> mydeque= Backspace(text);
    while (!mydeque.empty())
    {
        cout << mydeque.front();
        mydeque.pop_front();
    }
    cout<<"\n";
    return 0;
    
}

