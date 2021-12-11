#include <bits/stdc++.h>

using namespace std;

vector<int> kmp_pre(string subS)
{
    vector<int> tab(subS.size() + 1, -1);
    for(int i = 1; i <= subS.size(); i++)
    {
        int pos = tab[i - 1];
        
        while(pos != -1 && subS[pos] != subS[i - 1]){
            pos = tab[pos];
        }
        tab[i] = pos + 1;
    }
    return tab;
}

void kmp_search(string subS,string fullstring,vector<int> tab)
{
    int fullIndex = 0;
    int subIndex = 0;
    
    int fSize = (int)fullstring.size();
    int sSize = (int)subS.size();
    
    while(fullIndex < fSize)
    {
        while(subIndex != -1 && (subIndex == sSize || subS[subIndex] != fullstring[fullIndex]))
            subIndex = tab[subIndex];
        
        subIndex++;
        fullIndex++;
        
        if(subIndex == sSize){
            cout << fullIndex - sSize << " ";
        }
    }
    cout << "\n";
}


int main() {
    
    int x,y,z;
    string sub, full;
    while (getline(cin,sub)) {
        getline(cin,full);
        kmp_search(sub, full, kmp_pre(sub));
    }
    return 0;   
}