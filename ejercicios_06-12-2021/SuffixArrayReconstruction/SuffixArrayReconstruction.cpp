
#include <bits/stdc++.h>
using namespace std;

#define PLACEHOLDER '#'
#define WILDCARD '*'

struct SuffixArray {
    int position;
    string suffix;
};

inline bool insert_suffix(string& target, SuffixArray& s) {
    bool wildcard = false;
    for (int suffix_pos = 0, target_pos = s.position;
         target_pos < target.size();
         suffix_pos++, target_pos++) {

        if (s.suffix[suffix_pos] == WILDCARD) {
            wildcard = true;
            break;
        }
        
        if (target[target_pos] != PLACEHOLDER &&
            target[target_pos] != s.suffix[suffix_pos])
            return false;
        else
            target[target_pos] = s.suffix[suffix_pos];
    }

    if (wildcard) {
        for (int suffix_pos = s.suffix.size() - 1, target_pos = target.size() - 1;
             s.suffix[suffix_pos] != WILDCARD;
             suffix_pos--, target_pos--) {
            
            if (target[target_pos] != PLACEHOLDER &&
                target[target_pos] != s.suffix[suffix_pos])
                return false;
            else
                target[target_pos] = s.suffix[suffix_pos];
        }
    }
    
    return true;
}


string Re_Construct(int length, vector<SuffixArray>& suffixes) {
    string result;
    result.resize(length, PLACEHOLDER);
    
    for (SuffixArray& s : suffixes) {
        if (!insert_suffix(result, s)) return "";
    }

    for (char c : result) {
        if (c == PLACEHOLDER) return "";
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        int length, suffix_count;
        cin >> length >> suffix_count;

        vector<SuffixArray> suffixes;
        suffixes.reserve(suffix_count);
        
        while (suffix_count--) {
            SuffixArray s;
            cin >> s.position >> s.suffix;
            s.position--;
            suffixes.push_back(s);
        }
        
        auto result = Re_Construct(length, suffixes);
        
        if (result.empty()) printf("IMPOSSIBLE\n");
        else printf("%s\n", result.c_str());
    }
}