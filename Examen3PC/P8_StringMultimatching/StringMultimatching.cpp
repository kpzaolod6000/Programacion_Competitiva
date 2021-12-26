#include <bits/stdc++.h>
using namespace std;

vector<int> pre_KMP(string subText)
{
    vector<int> pattern(subText.size() + 1, -1);
    for(size_t i = 1; i <= subText.size(); i++)
    {
        int pos = pattern[i - 1];
        
        while(pos != -1 && subText[pos] != subText[i - 1]){
            pos = pattern[pos];
        }
        pattern[i] = pos + 1;
    }
    // for (auto x : table)
    // {
    //     cout<<x<<" ";
    // }
    
    return pattern;
}

void s_KMP(string subText,string fullText,vector<int> table)
{
    int fullIdx = 0;
    int subIdx = 0;
    
    int fSize = (int)fullText.size();
    int sSize = (int)subText.size();
    
    while(fullIdx < fSize)
    {
        while(subIdx != -1 && (subIdx == sSize || subText[subIdx] != fullText[fullIdx]))
            subIdx = table[subIdx];
        
        subIdx++;
        fullIdx++;
        
        if(subIdx == sSize){
            cout << fullIdx - sSize << " ";
        }
    }
    cout << endl;
}



int main() {
    
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int q,y,z;
    
    while (cin>>q)
    {
        cin.ignore();
        int i = 0;
        vector<string> sub_textList;
        string full_text;
        while (i <= q)
        {
            string sub_text;
            if (i == q)
            {
                string f_text;
                getline(cin, f_text);
                full_text = f_text;
            }
            else
            {
                getline(cin,sub_text);
                sub_textList.push_back(sub_text);
            }
            i++;
        }
        // cout<<i<<endl;
        for (auto s_text : sub_textList)
        {
            s_KMP(s_text, full_text, pre_KMP(s_text));
        }
    }    
}