#include <bits/stdc++.h>

using namespace std;

vector<int> SuffixArray(string text){
    
    int n = text.size();
    map<string,int> order_id;
    
    vector<int> suffix(n);

    for (size_t i = 0; i < n; i++) {
        // cout<<text.substr(i, n)<<" "<<i<<"\n";
        order_id[text.substr(i, n)] = i;
    }
    int j = 0;
    for (auto x : order_id) {
        suffix[j] = x.second;
        j++;
    }
    return suffix;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    string text;
    cin >> text;
    vector<int> Suffixarr = SuffixArray(text);
     
    
    for (size_t i = 0; i < Suffixarr.size(); i++) {
        cout << Suffixarr[i] << " ";
    }

    return 0;
}
