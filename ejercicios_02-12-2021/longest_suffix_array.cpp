#include <bits/stdc++.h>

using namespace std;

map<string,int> SuffixArray(string text){
    
    int n = text.size();
    map<string,int> order_id;
    
    vector<int> suffix(n);

    for (size_t i = 0; i < n; i++) {
        // cout<<text.substr(i, n)<<" "<<i<<"\n";
        order_id[text.substr(i, n)] = i;
    }
    
    return order_id;

}

int  longestCommonPrefix(string text){
    map<string,int> Suffix = SuffixArray(text);
    map<string,int> lcp;
    map<string,int>::iterator it=Suffix.begin();

    for (auto x : Suffix) {
        cout<<x.second<<" "<<x.first<<"\n";
    }
    cout<<"\nlcp\n";
    
    string prev = it->first;
    lcp[prev] = 0;
    it++;
    int max_ = 0;

    while (it!=Suffix.end())
    {
        int cnt_equal = 0;
        string current = it->first;
        
        for (size_t i = 0; i < prev.size(); i++)
        {
            if (prev[i] == current[i]) cnt_equal++;
            else break;
            
        }
        max_ = max(max_,cnt_equal);
        lcp[current] = cnt_equal;
        prev = current;
        it++;
    }
    
    for (auto x : lcp) {
        cout<<x.second<<" "<<x.first<<"\n";
    }
    
    return max_;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    string text;
    cin >> text;
    cout << longestCommonPrefix(text)<<"\n";
    

    return 0;
}
