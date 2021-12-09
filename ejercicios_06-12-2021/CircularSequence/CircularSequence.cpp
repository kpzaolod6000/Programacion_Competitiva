#include <bits/stdc++.h>

using namespace std;

string solve(int idx, string text)
{
    string tmp(text.begin()+idx,text.end());
    for(size_t i=0;i<idx;i++)
        tmp+=text[i];
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--)
    {
        string text;
        cin>>text;
        vector<int> seq[4];
        for(size_t i=0;i<text.size();i++)
        {
            if(text[i]=='A')
                seq[0].push_back(i);
            if(text[i]=='C')
                seq[1].push_back(i);
            if(text[i]=='G')
                seq[2].push_back(i);
            if(text[i]=='T')
                seq[3].push_back(i);
        }
        int res=-1;
        string ans,tmp;
        for(size_t i=0;i<4;i++)
        {
            for(size_t j=0;j<seq[i].size();j++)
            {
                tmp=solve(seq[i][j],text);
                if(ans.empty()||tmp<ans)
                    ans=tmp;
                if(ans.size()!=0)
                    res=0;
            }
            if(res!=-1)
            {
                cout<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}